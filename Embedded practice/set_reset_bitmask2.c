#include <stdio.h>
#include <stdint.h>

uint32_t Set(uint32_t input, int pos){
    uint32_t output = input | (1<<pos-1);
}

uint32_t Reset(uint32_t input, int pos){
    uint32_t output = input & ~(1<<pos-1);
}

int main(){
    int pos1 = 3;
    int pos2 = 2;
    uint32_t input1 = 0xffffffff; /*Reset*/
    uint32_t input2 = 0x00000000; /*Set*/
    uint32_t out1 = Reset(input1,pos1);
    uint32_t out2 = Set(input2,pos2);

    printf("%08x %08x",out1,out2);
}