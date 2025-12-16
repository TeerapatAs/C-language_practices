#include <stdio.h>
#include <stdbool.h>

// Ghandi Return! This time I've used the knowledge from short int and char to perform the Ghandi Bug integer overflow.

// Algo;
//
//

int main() {
    printf("Ghandi Return!, Please look! the aggression is stored in the UNSIGNED CHAR and this time he shall be less aggressive:");
    unsigned char npc_aggression = 1;
    unsigned char npc_aggression2 = npc_aggression - 4;
    unsigned char npc_aggression3 = npc_aggression -6;
    printf("\nNPC Aggression is now 1-4 = (1-2)-2 = 255-2 =: %d",npc_aggression2);
    printf("\nNPC Aggression is now 1-6 = (1-2)-4 = 255-4 = : %d",npc_aggression3);

    printf("Ghandi Return!, Please look! the aggression is stored in the SHORT INT, so IF he is very aggressive, when added more aggresion, he will be calm");
    short int npc_anger = 32767;
    short int npc_anger2 = npc_anger + 10;
    short int npc_anger3 = 32765 + 7;
    printf("\nNPC Aggression is now 32767+10 = (32767+1)+9 = -32768 + 9 =: %d",npc_anger2);
    printf("\nNPC Aggression is now 32765+7 = 32767+5 = -32768 + 4 = : %d",npc_anger3);

    return 0;
    
}