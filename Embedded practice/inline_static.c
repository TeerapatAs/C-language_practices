#include <stdio.h>
#include <stdint.h>

static inline int sumA (int A){
    return A;
}

int sumB(int B){
    return B;
}


int main(){
    sumA(2);
    sumB(3);
}