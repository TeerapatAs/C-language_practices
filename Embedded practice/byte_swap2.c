#include <stdio.h>
#include <stdint.h>

uint32_t swap_byte (uint32_t input){
    uint32_t output = input & 0xff;
    for(int i=0; i < 3; i++){
        output = output << 8;
        output += ((input>>8*(i+1)&0xff));
    }
    return output;
}

/* 0xaabbccdd ddccbbaa*/
int main(){
    uint32_t input = 0xaabbccdd;
    uint32_t output = swap_byte(input);

    printf("%08x",output);

    return 0;
}