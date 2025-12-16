#include <stdio.h>
// Define Array
typedef struct{
    int array[5];
}ArrayStruct;

typedef struct 
{
    int num;
    char name[50];
}Profile;


// Define a function return ArrayStruct
ArrayStruct create_ArrayStruct(){
    ArrayStruct Oarray;
    // Manipulate array in ArrayStruct
    for (int i = 0; i <5; i++){
        Oarray.array[i] = i;
    }
    return Oarray;
}

void main(){
    // Array store in structure
    ArrayStruct array = create_ArrayStruct();// Array that given by create_ArrayStruct function.
    int size = sizeof(array.array)/4;
    printf("%d ",size);
    printf("Array: ");
    for (int i = 0;i<size;i++){
        printf("%d ",array.array[i]);
    }

    // Structure Declaration
    Profile jenna = {24,"Jenna"};
    Profile john = {40,"JOHN"};
    Profile tree = {25,"HEYTREE"};

    // Array of Structure
    Profile profiles[] = {jenna,john,tree};


    printf("\nAge:");
    for (int i = 0; i <3; i++){
        printf(" %d",profiles[i].num);
    }



}



