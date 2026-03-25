# include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <errno.h>
#include <signal.h>

#define PKT_SIZE 64  /* Define packet Size as 64 bytes*/
#define TIMEOUT_SEC 5 /*Define how long we wait before Reset*/

int sock = -1; /*Socket File DEscriptor*/
/* tx_count and rx_count will count the data send and received. (TCP Header Sequence Number)*/
int tx_count = 0;
int rx_count = 0;

unsigned int dest_addr; /*Destination Socket Address*/

unsigned short checksum (unsigned short *addr, int count){
    /*checksum: Verify if all payload is send correctly.*/
    /*
    Inputs: -----------------------------------------------
    addr (unsigned short): The Packet's address pointer.
    count (int) : Size bytes of the packet.
    Outputs: -----------------------------------------------
    ~sums (unsigned long): 1's complement of the sums. 
    The sums is a sum of all data in sequence of 2 bytes (short) at a time.
    */
    unsigned long sum = 0;

    for (count; count > 1; count -= 2){
        /* Add data 2 bytes at a time.*/
        sum += *addr++;
        // printf("%d", count);
    }

    /*In case the data has an odd bytes. ex. count = 7, add the last bytes to sum*/
    if (count > 0){
        sum += *(unsigned char *)addr++;
    }

    sum = (sum>>16) + (sum&0xffff); /*Add carry bits*/
    sum += (sum>>16); /* Second pass maye have the carry bits*/

    return ~sum;
}

unsigned short test_checksum(unsigned short* addr, int count, unsigned short check_sum)
{
    /*Test_checksum : Verify that "checksum + all data" results in all 1's
    Inputs: ------------------------------------
    */
   unsigned long ver_sum = 0;
   for (count; count > 1; count -=2){
        printf("%x",*addr);
        ver_sum += *addr++;
   }
   if (count > 0){
        ver_sum += *(unsigned char *)addr;
        printf("%x", *(unsigned char *)addr);
   }

   ver_sum += check_sum;

   /*Carry bits*/
   ver_sum = (ver_sum >> 16) + ver_sum;
   ver_sum += (ver_sum>>16);

   return ver_sum;
    
}

int init_socket(){
    /*Initialize the socket. Return -1 if we can't find a raw socket*/
    int s = socket(AF_INET,SOCK_RAW,IPPROTO_ICMP);
    if (s<0){
        perror("socket");
        printf("Need Root Privilege to create a socket!"); // Most of the timed system can't arrange us a socket due to root privilege
        return -1;
    }

    struct timeval tv_out; // timeval is a structure from <sys/time.h>
    tv_out.tv_sec = TIMEOUT_SEC;// tv_sec = time in second
    tv_out.tv_usec = 0;

    // Set Socket File Descriptor Options
    if (setsockopt(s,SOL_SOCKET, SO_RCVTIMEO , &tv_out, sizeof(tv_out)) < 0)
    {
        perror("setsockopt SO_RCVTIMEO");
        return -1;
    }

    // If everything is okay.
    return s;
}

void prep_packet(char* sendbuffer, int seq){
    /* Prepare ICMP packet. This is for receiver echo request. 
    Inputs:
    sendbuffer (char*): pointer points at buffer of data. 
    seq (int) : sequence number of data, use as the starting point of data we send.
    */

   // Set all bytes in sendbuffer '0'
    memset(sendbuffer,0,PKT_SIZE);

   struct icmp* icmp_pk = (struct icmp*)sendbuffer; // Recast

   // Necessary variables in icmp_pk structure.
   icmp_pk -> icmp_type = ICMP_ECHO;
   icmp_pk -> icmp_code = 0;
   icmp_pk -> icmp_id = getpid() & (0xffff); 
   icmp_pk -> icmp_seq = seq;

    // Then add data to the block we had cleared before. 0x99 in this case.
    // we move pointer by "icmphdr" size.
    memset(sendbuffer + sizeof(struct icmphdr),0x99,PKT_SIZE);

    // For checksum in icmp header. It's necessary that
    // we need to need to set checksum as 0 firsy.
    icmp_pk -> icmp_cksum = 0;
    icmp_pk -> icmp_cksum = checksum((unsigned short *)icmp_pk,PKT_SIZE);

}

int sendpacket(int s, char* sendbuffer, struct sockaddr_in* dest_addr){
    /* Send a packet from a selected raw socket.*/
    /*
    Inputs:
    s (int): an input raw socket.
    sendbuffer (char*) : pointer points at the buffer of data.
    des_ip_addr (struct sockaddr_in*): An Socket Address destination.
    Outputs:
    send_bytes: number of bytes send successfully.
    */
   socklen_t size_of_dest_addr = sizeof(*dest_addr);
   int send_bytes = sendto(s,sendbuffer,PKT_SIZE,0,(struct sockaddr*)dest_addr,size_of_dest_addr);

   // send_bytes = -1 if error occurred.
   if (send_bytes < 0){
    perror("sendto failed");
   }
   return send_bytes;
}

int receivepacket(int s,char* receivebuffer, struct sockaddr_in* sender_addr_ptr, size_t buffsize){
    /*Receive a packet from a "s" socket a "s" socket. Pls look at "sendpacket" for Variable inputs details*/
    // Pls look at "sendpacket" for Variable inputs details*/
    socklen_t size_of_sender_addr = sizeof(*sender_addr_ptr);

    int recv_bytes = recvfrom(s, receivebuffer, PKT_SIZE, 0, (struct sockaddr*)sender_addr_ptr,&size_of_sender_addr);

    return recv_bytes;
}

void processReply(char* recvbuffer,int bytes, struct sockaddr_in* sender,int seq, struct timeval* tv_start, \
struct timeval* tv_end){
    /*Function call after received reply from destination.*/
    /*Right now packet should contains both ip header and icmp packet*/
    // Unopack the packet.
    struct ip* ip_hdr = (struct ip*)recvbuffer;
    int h_len = ip_hdr->ip_hl <<2; // in_hi is the word length of ip header. ex. 15 words = 60 bytes
    struct icmp* icmp_reply = (struct icmp*)(recvbuffer+h_len); // points at the strat of icmp packet

    // Check if the packet is a EchoReply and the pid is correct (In case this host did multiple pings at the same time.).
    if ((icmp_reply->icmp_type == ICMP_ECHOREPLY) && (icmp_reply->icmp_id == (getpid() & 0xffff)))
    {
        rx_count++;

        // Calculate Round Time Trip in milliseconds.
        double rtt = (tv_end-> tv_sec - tv_start->tv_sec) * 1000 + \
        (tv_end-> tv_usec - tv_start->tv_usec)/1000;

        // Display the reply results from destination.
        printf("%d bytes from: %s : icmp_seq= %d ttl= %d time= %.3f ms \n", \
                h_len,
                inet_ntoa(sender->sin_addr),
                icmp_reply->icmp_seq,//Time to live.
                ip_hdr->ip_ttl, // Time to live.
                rtt
            );
    }

}

void cleanup(int sig){
    /* Call to RESET (ex. When sender cancel the ping. Reset the socket.)*/

    // Print Statistics
    printf("\n ----%s Ping Statics -------\n",inet_ntoa(*(struct in_addr*)&dest_addr));
    
    // Calculate loss
    float loss = 0.0;
    if (tx_count > 0){
        loss = ((tx_count -rx_count) / tx_count) * 100;
    }

    printf("loss rated: %.2f from transmitted packets: %d received packets: %d \n",loss,tx_count,rx_count);

    // Close the socket
    if (sock >= 0){
        close(sock);
    }
    exit(0);
}   

int ping_loop(int _sock, struct sockaddr_in* _dest_addr){
    /*Main loop, continuosly-ping destination until sender cancel the ping command.*/

    // Declear variables.
    int bytes; // Number of successfully bytes send.
    char sendbuff[PKT_SIZE];
    char recvbuff[PKT_SIZE + sizeof(struct ip)];
    struct sockaddr_in _sender;
    struct timeval tv_start;
    struct timeval tv_end;


    while (1){
        prep_packet(sendbuff,tx_count++);
        gettimeofday(&tv_start,NULL);
        bytes = sendpacket(_sock,sendbuff,_dest_addr); 

        if (bytes < 0){
            // If we cannot send bytes successfully. COntinue.
            continue;
        }

        bytes = receivepacket(sock,recvbuff,&_sender,sizeof(recvbuff));
        gettimeofday(&tv_end,NULL);

        if (bytes < 0){
            if (errno == EAGAIN || errno == EWOULDBLOCK){
                printf("request timeout for: icmp_seq=%d",tx_count-1);
            }
            else{
                perror("receive from failed!");
            }
        }
        else{
            processReply(recvbuff,bytes,&_sender,tx_count-1,&tv_start,&tv_end);
        }
        sleep(1); // sleep 1 s vefore next ping.
    }

    return 0;
}



int main(int argc, char *argv[]) {
    /*main: serve as an entry point*/
    // Check user argumetnt if It is not 2. Tell them that they got it wrong.
    if (argc != 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        return 1;
    }
    
    if (inet_pton(AF_INET, argv[1], &dest_addr) <= 0) {
        fprintf(stderr, "Bad address: %s\n", argv[1]);
        return 1;
    }
    
    signal(SIGINT, cleanup);
    
    // initailize a socket.
    sock = init_socket();
    if (sock < 0) {
        return 1;
    }
    
    // Set sockadd structure.
    struct sockaddr_in dest;
    memset(&dest, 0, sizeof(dest));
    dest.sin_family = AF_INET;
    dest.sin_addr.s_addr = dest_addr;
    
    printf("PING %s (%s): %ld data bytes\n", 
           argv[1], 
           inet_ntoa(*(struct in_addr *)&dest_addr), 
           PKT_SIZE - sizeof(struct icmphdr));
    
    return ping_loop(sock, &dest);
}


