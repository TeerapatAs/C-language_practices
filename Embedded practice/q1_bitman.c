#include <stdio.h>
#include <stdint.h>

/*deadbeef deafbabf*/

uint32_t replace (int a, int b, uint32_t x, uint32_t input){
    uint32_t one = 0x0;
    for (int i = a; i < b+1; i++){
        one = one <<1;
        one += 0x1;
    }
    one = ~(one << a);
    input = input & one;

    x = x <<a;   /*0xab  -> 0xab0*/

    input = input + x;
    return input;
}


int main(){
    int a = 4; int b = 11;  /*change bits in pos 4-11*/
    int x = 0xab;
    uint32_t input = 0xdeadbeef;
    uint32_t output = replace(a,b,x,input);

    printf("output: %08x %08x",output,input);
    return 0;
}