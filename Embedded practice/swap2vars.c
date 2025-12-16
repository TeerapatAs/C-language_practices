#include <stdio.h>
#include <stdint.h>

void swap (int* a, int* b){
    *a = *b + *a; // ex. a=4, b = 6,  a = 4+6 = 10
    *b = *a - *b;
    *a = *a - *b;
}

int main(){
    int a = 4;
    int b = 6;
    swap(&a,&b);
    printf("Let's swap: %d , %d",a,b);
    return 0;
}