#include <stdio.h>

int main(){
    // Array Declaration and Initialization in a single line
    int full[5] = {0,1,2,3,4}; //full
    int num[5] = {1024,14,3}; //partial 
    char word[] = "Hey!"; //skip

    printf("%d",word); // display the memory address
    // Array Pointer
    int* full_ptr = full; // display the pointer
    printf("\npointer(p) (It can display as 8 digits hexagonal): %p",full_ptr);
    printf("\nmemory location (display in decimal)(the value is exact as ): %d",full);


    // We can only do array declaration and initialization seperatly with only "full" and "partial" type
    num[2] = 6;
    for(int i = 0; i < 3; i++){
        printf("%d ",num[i]);
    }

    // Know how many elements by elements = sizeof(array)/size_of_element
    int elements = sizeof(full)/4;
    printf("%d",elements); //results: 5

    // 2-D Array that stores [0 1; 2 3]-----------------------------------------------
    int array[2][2]; //Declear array 2 by 2\
    // Nested Loop
    int k = 0;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j<2; j++){
            array[i][j] = k;
            k++;
        }
    }
    //print out 2D array
    for (int i = 0; i < 2; i++){
        printf("\n");
        for (int j = 0; j<2; j++){
            printf("%d ",array[i][j]);
        }
    }
    //----------------------------------------------------------------------------------------------

    // 3D array with 3*2*3 dimension; each heigth has 0 1 2
    int arr3D[3][2][3];
    k = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j<2; j++){
            for (int l = 0; l<3; l++){
                arr3D[i][j][l] = k;
                k++;
            }
            k = 0;
        }
    }
    //print out 3D array in "Layer"
    for(k = 0; k<3; k++){
        printf("\n Layer: %d \n",k);
        for (int i = 0; i < 2; i++){
            for (int j = 0; j<2; j++){
                printf("%d ",arr3D[i][j][k]);
            }
        }
    }



    return 0;
}