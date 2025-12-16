#include <stdio.h>
#include <stdlib.h>

/* Array needs to be return as a pointer*/

int* create_array(int size){
    int* arr = malloc(4*size);
    for(int i = 0; i < size; i++){
        arr[i] = i;
    }
    return arr;
}

int* rev_arr(int* arr, int size){
    int* rev_arr = malloc(4*size);
    for (int i = 0; i<size; i++){
        rev_arr[i] = arr[size-i-1];
    }
    return rev_arr;
}

int* insert(int arr[], int pos, int size, int value){
    //(arr,position(start at 0),size of original array, value)
    // Algorithm: Shift right, then insert.
    if (pos > size-1){
        printf("pos invalid!");
    }
    int* inserted_arr = malloc(4*size);

    for (int i = 0; i<pos; i++){
        inserted_arr[i] = arr[i];
    }
    /*at int i = pos*/
    inserted_arr[pos] = value;
    for (int i = pos+1;i<=size;i++){
        inserted_arr[i] = arr[i-1];
    }
    return inserted_arr;
}

int* del_element(int arr[], int size, int pos){
    int* del_arr = malloc(4*(size-1));
    for (int i = 0; i<pos;i++){
        del_arr[i] = arr[i];
    }
    for (int i = pos; i < size-1; i++){
        del_arr[i] = arr[i+1];
    }
    return del_arr;
}

int* rot_arr(int arr[], int size, int pos){
    int* rot_arr2 = malloc(4*size);
    
}

int main(){
    int size = 5;
    int* arr_created = create_array(size);
    int* rev_array = rev_arr(arr_created,size);
    int* inserted_arr = insert(arr_created,2,size,5);
    int* del_arr = del_element(arr_created,size,2);
    for (int i = 0;i <size; i++){
        printf("%d",arr_created[i]);
    }

    for (int i = 0;i <size; i++){
        printf("%d",rev_array[i]);
    }

    printf("\n");

    for (int i = 0;i <size; i++){
        printf("%d",inserted_arr[i]);
    }

    printf("\n");

    for (int i = 0;i <size; i++){
        printf("%d",del_arr[i]);
    }

    // Array Rotation
    int arr3[] = {0,1,2,3,4,5,6};
    int rotate_pos = 4;
    int size_arr3 = 7;
    int* rot = rot_arr(arr3,size_arr3,rotate_pos);
    printf("\nRotate Array: ");
    for (int i = 0; i<size_arr3; i++){
        printf(" %d",rot[i]);
    }


    printf("\n%d",*arr_created);
    free(arr_created); free(rev_array); free(inserted_arr);
    /*After free, set pointer to NULL*/ arr_created = NULL;
    // printf("\n%d",*arr_created);

    return 0;

}