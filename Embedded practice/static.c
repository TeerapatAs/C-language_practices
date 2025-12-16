#include <stdio.h>
#include <stdint.h>

int count(){
    static int x = 0;
    x++;
    return x;
};

int main(){
    int a = count();
    int b = count();
    printf("%d %d",a,b);

    return 0;
}