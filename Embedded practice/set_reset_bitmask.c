#include <stdio.h>
#include <stdint.h>

#define BIT_MASK(BIT_POS) (1U << BIT_POS)

uint32_t Set_bit (uint32_t input, uint8_t BIT_POS){
    uint32_t bitmask = 1U<<BIT_POS;
    uint32_t output = input | bitmask;
    return output;
};

uint32_t Reset_bit(uint32_t input, uint8_t BIT_POS){
    uint32_t bitmask = 1U<<BIT_POS;
    uint32_t output = input & ~(bitmask);
    return output;
}

int main(){
    uint32_t input = 0x01;
    uint32_t ans1 = Set_bit(input,3);
    uint32_t ans2 = Reset_bit(input,0);

    printf("ans1: %02x ans2:%02x", ans1, ans2);
}