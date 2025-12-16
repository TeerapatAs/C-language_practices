#include <stdio.h>
// Content:=========================================================
// 1. Structure Basic.
// 2. Typedef Structure.
// 3. Pass Structure with pointer through function.
// 4. Pass whole Structure through function.
// ================================================================


// 1. Structure: Basic:: Structure contains members with different data types
// Structure can only initialization, Not DECLERATION
// Syntax:: struct Struct_name var_name = {...};
struct BasicStruct{
    char name[20];
    int age;
    int salary;
};

// p.s. Array of Structure syntax: struct Struct_name var_name[] = {,..,..}

// 2. Structure: Typedef:: Structure decleared by owner
// Declare syntax: typedef struct {member1,member2,...,} struct_name;
// Syntax: struct_name var_name = {...};
typedef struct{
    char name[20];
    int length;
} TypedefStruct;     //movie

// 3. Passing Structure through pointer (recommended) or whole structure (too large struct will be problem)
// ex. struct Struc_name var_name = {...};
// pointer:: is &var_name --> Pass it through function
typedef struct
{
    char name[25];
    float win_rate;
}UFC;
// Manipulate the value in function: We have 2 options
// 1. Manipulate through the new_var (such as in Array:: int* arr = (int*)malloc(4*int_size)), 
// ---> Return pointer or Structure
// 2. Manipulate the variable directly
// --> It can be void because we manipulated the variable.
// ---- This function use Option2: <Manipulate the variable directly>:

void minus_winrate(UFC* fighter_pointer, float rate){
    // input: Structure's pointer, win rate
    // objective: reduce win_rate by rate
    fighter_pointer->win_rate -= rate;
};

// --- Option 1: Send the whole Structure:: Manipulate through the new_var
UFC updated_fighter(UFC fighter, float rate){
    // Output: Name and new win_rate
    UFC updated_fighter;
    updated_fighter.name = fighter.name;
    updated_fighter.win_rate = fighter.win_rate + rate;
    return updated_fighter;
};




// Main
int main(){
    //1.  Use Basic Structure
    struct BasicStruct jenna = {"Jenna",20,20000};
    struct BasicStruct tony = {"Tony",40,200000};
    struct BasicStruct joey = {"Joey",12,200};
    // Array of Structure
    struct BasicStruct team[] = {jenna,tony,joey};
    printf("Basic Structure: Name and Salary\n");
    struct BasicStruct member;
    for (int i = 0; i<3; i++){
        member = team[i];
        printf("%s \t %d\n",member.name,member.salary);
    };

    //2. Use Typedef
    TypedefStruct mov1 = {"No Country",120};
    TypedefStruct mov2 = {"Momento",135};
    TypedefStruct movies[] = {mov1,mov2};
    TypedefStruct movie;
    printf("Typedef Structure: Movie\n");
    for (int i = 0; i<2; i++){
        movie = movies[i];
        printf("%s \t %d\n",movie.name,movie.length);
    };

    //3. Pass Struct's pointer through function;
    UFC ngannou = {"Ngannou",89.90};
    UFC strick = {"Strick",68.71};
    UFC kha = {"Khabib",100};
    printf("Pass Structure through function with pointer: UFC\n");
    printf("Ngannou's point before: %s %.2f \n",ngannou.name,ngannou.win_rate);
    // Pass ngannou's pointer through pointer
    
    minus_winrate(&ngannou,8.76);
    printf("Ngannou's point after: %s \t %.2f \n",ngannou.name,ngannou.win_rate);

    // (NOT RECOMMENDED) 4. Pass Whole Structure through function-----
    printf("Pass Whole Structure through function: UFC\n");
    printf("Strick's point before: %s %.2f \n",strick.name,strick.win_rate);
    strick = updated_fighter(strick,7.20);
    printf("Strick's point after: %s \t %.2f \n",strick.name,strick.win_rate);
    
    return 0;
}