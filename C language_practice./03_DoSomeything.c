#include <stdio.h>

// Instruction : Use all kinds of operation to perform this task.

int main() {
    const int a = 1;
    int b = 4;
    printf("%d", ((((a+b)==(a*b)) && ((a%b)!=b))+5) << 3 );  // (0+5)<<3 = 40
    return 0;
}