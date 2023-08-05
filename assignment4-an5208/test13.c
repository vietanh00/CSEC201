#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b){
    int temp1 = (int*) malloc(sizeof(int));    
    temp1 = *a;
    *a = *b;
    *b = temp1;

}

int main(){
      int a = 15;
      int b = 20;
      swap(&a, &b);
      printf("a = %d, b = %d\n", a, b);

}