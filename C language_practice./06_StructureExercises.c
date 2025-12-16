#include <stdio.h>
#include <stdlib.h>
// # Content Table ======================================================================
// 1. Store the student information and print out
// 2. Store Student records as Structures and Sort them by Name
// 3. 
//========================================================================================

// 1. Store the student information and print out------------------------------------------
// Initialization
typedef struct 
{
    char* name; // include as pointer
    int id;
    int score;
}Student;

// 2. Store Student records as Structures and Sort them by Name---------------------------
// Function Compare (with pointer in Main)
int comp(const void* a,const void* b){
    return *(int *) a - *(int *) b; // if a - b >0; a is sent after b ex.(5 2-> 2 5)
    // use (int* a) to told function that a is the int first
};


int compare(const void* a, const void* b){
    Student student_a = *(Student *)a;
    Student student_b = *(Student *)b;
    // Pass Array(Strings) through function :: You need size too.
    int result = my_strCompare(student_a.name,student_b.name); //student.a is a char pointer
    return result;
}

int my_strCompare(char* str_a, char* str_b){ //student.a is a char pointer
    if (*str_a != '\0' && *str_b != '\0'){ // if str is not NULL
        if (*str_a == *str_b){
            str_a++; str_b++;
            my_strCompare(str_a,str_b);
        }
        else{
            return *str_a - *str_b;
        }

    }
    else{
        if (*str_a == '\0'){
            return -1; // sent str_a before str b
        }
        else{
            return 1;
        }
    }
}

//3. Add 2 complex numbers---------------------------------------------------------------
typedef struct{
    int real;
    int img;
}Complex;

// Pass Structure through pointer
Complex add(Complex a, Complex b){
    // Input: 2 complexs, Output: Complex added
    Complex c; // Initialize
    c.real = a.real + b.real;
    c.img = a.img + b.img;
    return c;
}

int main(){
    // 1. Store the student information and print out-------------------------------------
    Student student[2]; //Array with 2 members
    student[0].name = "John";
    student[0].id = 1023;
    student[0].score = 45;

    student[1].name = "Jenny";
    student[1].id = 1024;
    student[1].score = 87;

    printf("Q1: Store the student information and print out\n");
    for (int y = 0; y<2;y++){
        printf("%s \t %d \t %d\n",student[y].name,student[y].id,student[y].score);
    };

    // 2. Store Student records as Structures and Sort them by Name-------------------------------------
    // First We need to get familiar with qsort
    /*
    qsort(arr, n, size, comp);
    arr: Pointer to the first element of the array.
    n: Number of elements in the array.
    size: Size of each element. (Bytes)
    comp: Function which takes pointer to a comparison function/comparator. (must be in form int* (const void *, const void *)) 
    if comp (function) results in .....
    <0 :: put the first element 'before' second element
    =0 :: equal
    >0 :: put the first element 'after' second element
    */
    printf("Try on compare principle\n");
    int arr[5] = {1,2,4,5,3};
    qsort(arr,5,4,comp);
    for(int i=0;i<5;i++){
        printf(" %d",arr[i]);
    }


    printf("\nQ2: Store Student records as Structures and Sort them by Name");
    Student jemmy = {"Jemmy",1023,88};
    Student emma = {"Emma",1024,48};
    Student john = {"John",1025,57};

    Student students[] = {jemmy,emma,john};
      // Compare the character
    int name_a = (jemmy.name)[0];
    int name_b = (emma.name)[0];
    printf("\n Compare J and E %d %d",name_a,name_b);

    // Compare pointer.
    Student* jemmy_ptr = &jemmy;
    int name_j = jemmy_ptr->name[0];
    printf("\n Pointer %d \n",name_j);

    // Test str compare function
    char* str_jem = jemmy.name;
    char* str_john = john.name;
    printf("result myStrCompare (compare ASCII value of a char): %d\n",my_strCompare(str_jem,str_john),"ITS WORK!");
    
    // Now, use q_sort
    qsort(students,3,sizeof(Student),compare); // Mystery Function

    for(int i=0;i<3;i++){
        printf(" %s",students[i].name);
    }

    //3. Add 2 complex numbers-------------------------------------------------------
    Complex a,b,sum;
    a.img = 3.00;
    a.real = 2.00;
    b.img = 4.00;
    b.real = 5.00;
    sum = add(a,b);
    printf("\nQ3: result: %d + %di",sum.real,sum.img);

    // 4. Read/Write Structure From/to a File in C-------------------------------------------------------
    /*
    Syntax of fwrite()
    size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream) //const void in this case can be anything;
    Parameters
    ptr: pointer to the block of memory to be written.
    size: the size of each element to be written (in bytes).
    nmemb: number of elements.
    stream: FILE pointer to the output file stream.

    Return: number of objects wriiten
    */

    // Write Structure
    FILE* filepointer = fopen("Structure.txt","a");
    Student ken = {"Ken",1452,87};
    // fwrite(struture pointer, sizeof(structure),1 structure,File pointer)
    int flag = fwrite(&ken,sizeof(Student),1,filepointer);
    fclose(filepointer);
    if (flag){
        printf("\nSuccess!");
    }
    // Read file
    // rewind = get pointer to the start of file again.
    FILE* filepointer2 = fopen("Structure.txt","r");
    // fread(pointer::block of memory to read into,sizeof(Structure),1 Structure, Input file)
    Student read_student;
    fread(&read_student,sizeof(Student),1,filepointer2);
    printf("\nQ4: Read and Write: %s id %d",read_student.name,read_student.id);

    return 0;
}