#include<stdio.h>

int add(int x, int y);
int subtract(int x,int y);
int multiply(int x, int y);

int compute(int (*ptr) (int, int),   int x, int y);

int main(){
    //create an array of function pointers
    int (*array[]) (int, int) = {add, subtract, multiply};

    for (int i = 0; i<3; i++){
        int result;
        result = compute(array[i], 7, 3);
        printf("result = %d\n", result);
    }
}
//ptr to point to add,subtract, or multiply
int compute (int (*ptr) (int, int), int x, int y){
    return ptr(x,y);
}
int add(int x, int y){
    return x+y;
}
int subtract(int x,int y){
    return x-y;
}
int multiply(int x, int y){
    return x*y;
}

