#include <stdio.h>
#include <string.h>

/*Instruction: 

Use "Input" Knowledge : scanf() to write Name and num
Use "Output" Knowledge : printf() to console and write 

*/ 

int main() {
    // Get input
    char name[10];
    int a;
    printf("Name and Number of films:"); scanf("%s %d",&name,&num);
    char status[10] = "";
    if (num <= 10){
        printf("%s is in unpopular Case",name);
        strcat(status,"unpopular");
    }
    else{
        printf("%s is Approved",name);
        strcat(status,"Approved");
    }

    // Write to file
    FILE* filepointer = fopen("input_actor.txt","a"); //a is append
    char num_str[5];
    snprintf(num_str,5,"%d",num); //

    char line[50];// put name and status together with only one space between them
    sprintf(line, "\n%s   %s   %s",name,num_str,status);
    fputs(line,filepointer);
    fclose(filepointer);

    return 0;



}