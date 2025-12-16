#include <stdio.h>
//#include <stdbool.h>

int main()
{
    // Arthemic
    printf("%d",(1+2));
    printf("\n%d",(1-2));
    printf("\n%d",(1*2));
    float d = 1.0/2.0;
    printf("\n%f",d);
    printf("\n%d",(1%2));
    int a = 1;
    printf("\n%d",a++);
    int b = 10;
    printf("\n%d",b+=5);
    printf("\n%d",b^3);

    //Relation
    printf("\nRELATION");
    printf("\n%d",(1==2));
    printf("\n%d",(1<2));
    printf("\n%d",(1>2));
    printf("\n%d",(2<=2));

    //logic
    printf("\nLOGIC");
    printf("\n%d",(0&&0)); //false
    printf("\n%d",(0&&1)); //false
    printf("\n%d",(0||1)); //true
    printf("\n%d",(0||0)); //false
    printf("\n%d",(!0));
    printf("\n%d",(!1));

    //bitwise (bit-by-bit)
    printf("\nBITWISE"); 
    printf("\n%d",(5&3));//& And Operand  (1 0 1) & (1 0 1)
    printf("\n%d",(5|3));//& OR Operand  (1 0 1) & (1 0 1)
    printf("\n%d",(5^3));//& XOR Operand  (1 0 1) & (1 0 1) = (1 1 0)
    printf("\n%d",(~5));//reset -> (1 0 1) -> (0 1 0)
    printf("\n%d",(5<<3)); //left shift bits (1 0 1) << 3 == (1 0 1 0 0 0) == 2^5 + 2^3 = 32+8=40
    printf("\n%d",(5>>3)); // ได้ 0

    return 0;
}