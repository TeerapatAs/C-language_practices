#include <stdio.h>
#include <stdint.h>

int sumA(int a, int b){
    return a,b;
}

int main(){
    int (*ptr) (int a, int b) = sumA;
    printf("%16x",ptr);
    return 0;
}

