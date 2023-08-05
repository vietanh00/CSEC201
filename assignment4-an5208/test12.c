#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LENGTH 10

void padding_change(char* text_a){
    size_t length = (int) strlen(text_a);
    int i = length-1;
    if(text_a[length-1] == '\n'){
        text_a[length-1] = 'A';
    }
    i+= 1;   
    while (i < LENGTH){
        text_a[i] = 'A';
        i += 1;
    }
    text_a[i] = '\0';
}

char* padding_no_change(char *text_a){
    char *text_b = (char *) malloc(LENGTH+1);
    strcpy(text_a, text_b);
    size_t length = (int) strlen(text_a);
    int i = length-1;
    if(text_a[length-1] == '\n'){
        text_b[length-1] = 'A';
    }
    i+= 1;   
    while (i < LENGTH){
        text_b[i] = 'A';
        i += 1;
    }
    text_b[i] = '\0';
    return text_b;
}

int main(){
    char text_a[LENGTH+1];
    fgets(text_a, LENGTH+1, stdin);
    printf("text_a = %s\n", text_a);
    char text_c[LENGTH+1];
    strcpy(text_c, text_a);

    padding_change(text_a);


    char *text_b = padding_no_change(text_c);
    printf("text_a = %s\n", text_a);
    printf("text_b = %s\n", text_b);
    return 0;
}