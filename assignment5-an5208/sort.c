#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//use pointers to x, y to compare the actual value x,y
//if x>y, return positive value
//if x == y, return 0
//if x<y, return negative value
//qsort using this would get an ascending array
int compare(const void *ptrx, const void *ptry){
    int *px = (int *) ptrx;
    int *py = (int *) ptry;
    return *px - *py; //return x - y
}

int str_compare(const void *ptrx, const void *ptry){
    //ptrx and ptry is a pointer to a string
    //buuut a string is a pointer too
    char* *px = (char* *) ptrx;
    char* *py = (char* *) ptry;
    return strcmp(*px, *py);
}

int main(){
    //int arr[] ={7,2,4,1,9,8};
    char *arr[] = {"B","A","D","C"};

    int nel = sizeof(arr)/sizeof(char*);
    qsort(arr, nel, sizeof(char *), str_compare);
    for (int i = 0; i<nel; i++){
        printf("%s\n", arr[i]);
    }
}