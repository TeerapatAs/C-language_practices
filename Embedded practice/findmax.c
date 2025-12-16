#include <stdio.h>
#include <stdint.h>

#define max(x,y,z) ((x>y)?((x>z)?x:z):((y>z)?y:z))

int main(){
    int x = 1; int y = 2; int z = 3;
    printf("max: %d",max(x,y,z));
    return 0;
}