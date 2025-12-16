#include <stdio.h>
#include <stdbool.h> // For boolean

int main() {
    // char (%c,%d) (1 byte) is a single character or integer within -128 to 127  
    char f = 'f';
    char f1 = 'F';
    char f2 = 100;
    printf("char examples : %c %c %d Note that: percent_d displays integer",f,f1,f2);

    // unsigned char (%c,%d) (1 byte) holds only the positive integers 0 to 255
    unsigned char f4 = 210;
    unsigned char f5 = 200;
    printf("\nunsigned char example: %c %d", f4,f5);

    // float (%f) (4 bytes,32 bits precision) holds float with 6-7 decimals.
    float d = 3.14159764;
    printf("\nIf float d = 3.14159764, then printf d accuracy is 6-7 digits: %f",d);

    // double (%lf long float) (8 bytes) holds number with 15-16 decimals.
    double d1 = 3.14159764;
    printf("\nIf float d1 = 3.14159764, then printf d1 accuracy is 15-16 digits: %.15f",d1);

    // boolean (%d) (1 byte--due to oldest CPU data lines called 1 byte per time.)
    bool T = true;
    bool F = false;
    printf("\nBooleans display: %d %d , Note that: To display boolean, Please include <stdbool.h>",T,F);

    // int (%d) (4 bytes) -- contains integer from -2,147,483,648 to 2,147,483,647 
    // unsigned int (%u) (4 bytes) contains 0 to 4,294,967,295 (2^32)
    int g = 2147483647;
    int g1 = 2147483648;
    printf("\nInt display when g = 2147483647: %d \nand Int display when g1 =2147483648 %d, Note that: It will return to ",g,g1);
    //Ghandi bug : Nuke them
    unsigned char ghandi_peace = 1; //unsigned char holds integer 0-255
    ghandi_peace = ghandi_peace - 2;
    printf("\nGhandi Bug--[ 1-2 is 255 ]: %d",ghandi_peace);
    //integer overflow again
    unsigned int Max_unsigned = 4294967295;
    Max_unsigned += 1;
    printf("\nInteger overflow--[ 4294967295 + 1 is 0 ]: %u",Max_unsigned);

    // short int (%hu) (2 bytes) is divided the int to hols on from -32,768 to 32,767
    // unsigned short int (%hd) (2 bytes) holds on from 0 to 65535
    short int h = 32767;
    unsigned short int h1 = (1 << 16)-1; //shift binary form of 1 to left 16 position
    printf("\nthis is the maximum bound of short int: %hd and unsigned shirt int %hu",h,h1);

    // long long int (%lld) (8bytes) is so huge bro
    // unsigned long long int (%llu)
    long long int t1 = -4560000;
    unsigned long long int t2 = 46000000;
    printf("\nthis is long long: %lld %llu",t1,t2);
    return 0;
}