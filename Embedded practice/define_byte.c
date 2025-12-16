#include <stdio.h>
#include <stdint.h>

#define BIT_MASK(BIT_POS) (1U << BIT_POS)

int main(){
    uint32_t Hey = 0x0000;

    printf("%08x",BIT_MASK(5));
    return 0;
}