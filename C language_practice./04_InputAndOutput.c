#include <stdio.h>
int main(){
    //Outputs------------------------------------------------------------
    //printf("text") -- print out text
    printf("this is printf results: Hey!");

    //fputs("text",outputs) -- ex. outputs (stdout,filepointer)
    fputs("\nthis is fputs results: Hey with output: stdout",stdout);
    FILE* filepointer = fopen("inputoutput.txt","w");// fopen returns pointer of the file
    fputs("\nthis is fputs results: Hey with the pointer",filepointer);
    fclose(filepointer);
    printf("\nthis is fputs pointer: %p",(void *)filepointer); // %p is for pointer (it's now 75AC4660) as you can see, its has 8 digits (64 bits)


    //Inputs------------------------------------------------------------
    //scanf("%type",variable) --
    int age;
    printf("Enter your age in INT: ");
    scanf(" %d",age);
    if (age <= 18){
        printf("Here's looking at you, kid"); // From Calabranca!
    }
    else{
        printf("Woah! You're grown up!");
    }
    

    //fgets(str,n,stdout) -- str is the string, n is the maximum bytes of input, stdout is the output way
    /*
    printf("\nEnter your name in STR (Read only first 10): ");
    char name[50];
    fgets(name,10,stdin);
    fprintf("%s",name);
    */
    return 0;


}