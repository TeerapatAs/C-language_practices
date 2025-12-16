#include <stdio.h>
#include <stdint.h>

uint32_t swap_byte(uint32_t input){
    uint32_t output = 0x0;
    uint8_t Temp = 0x0;

    for(int i=0;i<4;i++){
        output = output<<8; /* Shift 1 byte*/
        Temp = input>>(i*8) & 0xFF;
        output += Temp;
    }
    return output;
};

typedef struct{
    int age;
}John;

int main()
{
    John j1 = {22};
    uint32_t data = 0xFC0087CC;
    uint32_t output= swap_byte(data);
    printf("%x",output);
    return 0;
}