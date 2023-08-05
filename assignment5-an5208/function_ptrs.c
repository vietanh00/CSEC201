#include<stdio.h>

void print_it(int a);
void double_it(int a);
char *greet();

int main(){
    
}

void print_it(int a){
    printf("a is received %d\n", a);
}
void double_it(int a){
    a = a*2;
    printf("a is doubled %d\n", a);
}
char *greet(){
    return "Hello World!";
}