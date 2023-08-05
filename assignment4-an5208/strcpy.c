#include "string.h"
#include "stdio.h"
#include "stdlib.h"
//declaring this before main -> no prototype needed
char* mystrcpy2(char* dst, const char* src){
    dst = (char*) malloc(30);
    for (int i = 0; i < strlen(src); i++){
        dst[i]=src[i];
    }
    dst[strlen(src)] = '\0';
    return dst;
}
char* mystrcpy1(const char* src){
    //char dst[30];
    char *dst = (char*) malloc(30);
    for (int i = 0; i < strlen(src); i++){
        dst[i]=src[i];
    }
    dst[strlen(src)] = '\0';
    return dst;
}
int main(){
    char src[] = "hello"; //mutable
    //char dst[30]; //some arbitrary length
    //char *dst = (char*) malloc(30);
    char *result = mystrcpy2(result, src);
    result[0] = 'c';
    result[1] = '4';
    printf("src: %s\n", src);
    //printf("dst: %s\n", );
    printf("result: %s\n", result);
}

// mystrcpy1 is not working because dst string is stored in the stack frame