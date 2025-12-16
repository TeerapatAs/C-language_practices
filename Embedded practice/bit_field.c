#include <stdio.h>

// Example: a structure to store date components efficiently
struct Date {
    unsigned int nWeekDay : 3;  // 0-7 (3 bits needed)
    unsigned int nMonthDay : 6; // 0-31 (6 bits needed)
    unsigned int nMonth : 5;    // 0-12 (5 bits needed)
    unsigned int nYear : 8;     // 0-100+ (8 bits needed)
};

typedef struct{

    int a : 3;
    int b : 2;
}Hello;

int main() {
    struct Date today = {3, 14, 12, 25};
    printf("Today is weekday %u, day %u of month %u, year %u\n", today.nWeekDay, today.nMonthDay, today.nMonth, today.nYear);

    // The size of the structure is often less than the sum of the default sizes
    printf("Size of Date struct: %zu bytes\n", sizeof(today)); 
    // On many systems, this might be 4 bytes instead of 16 bytes (4 ints * 4 bytes each)

    Hello H1 = {4,1};
    printf("this is size of Hello: %d bytes",sizeof(H1));
    
    return 0;
}