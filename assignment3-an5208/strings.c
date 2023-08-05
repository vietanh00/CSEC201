#include <stdio.h>
#include <string.h>

// The method's header must be declared if it is used inside main()
// returns 1 if the 2 strings are equal, 0 otherwise

int str_equals(char *str1, char *str2);

int str_equals(char *str1, char *str2){
    char *ptr1 = str1;
    char *ptr2 = str2; // Those start at the beginning of the strings

    // keep going while dereferenced stuff isnt null
    while(*ptr1 != '\0' && *ptr2 != '\0'){
        if (*ptr1 != *ptr2){
            return 0;
        }
        ptr1 +=1;
        ptr2 +=1;
    }
    //The 2 strings are exhausted
    if (*ptr1 == '\0' && *ptr2 =='\0'){
        return 1;
    }
    //Only 1 string is exhausted, the other keeps going
    else{
        return 0;
    }
}

int main(){
    char str1[6] = "Hello";
    char *str2 = str1;
    char str3[6];
    strcpy(str3, str1);
    str3[1] = 'u'; // Hello vs Hullo
    printf("str1: %s \n", str1);
    printf("str3: %s \n", str3);
    printf("str1 equals str3? %d", str_equals(str1, str3));
}