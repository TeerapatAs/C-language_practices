/*Count the bits how many bits a needed to convert to b*/
#include <stdio.h>
#include <stdint.h>

int count_bits(uint32_t a, uint32_t b){
    int count = 0;
    for (int i = 0; i<32 ; i++){
        if ((a&0x1)^(b&0x1)){   // XOR is 1 if bits are different.
            count++;
        }
        a = a>>1;
        b = b>>1;
    }
    return count;
}

int main(){
    uint32_t a = 0x10111011;
    uint32_t b = 0x01111011;
    int counter = count_bits(a,b);
    printf("%d",counter);
    return 0;
}