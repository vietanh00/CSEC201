#include "stdio.h"
#include "string.h"

void printit(int a){
    printf("a is received as %d\n",a);
}

void doubleit(int a){
    a = a*2;
    printf("a is doubled and is now %d\n", a);
}

char *greet(){
    return("Sup");
}

int main(){
    //A pointer for a function
    void (*ptr1) (int a); //the a is not important and can be removed. The 'int' must stay
    char* (*ptr2)();

    ptr1 = printit; //assign printit to ptr1. We can assign doubleit to this as well.
    //execute the function. Instead of printit(10)
    ptr1(10);
    //assign ptr1 to a different function with the same declaration
    ptr1 = doubleit;
    ptr1(10);
    ptr2 = greet;
    char* result = ptr2();
    
    printf("%s\n", result);
}