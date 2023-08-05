#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *my_msg(char *first, int age){
    char *msg = (char *)malloc(100);
    sprintf(msg, "I am %s. \nI am %d year old.", first, age);
    return msg;
}

int main(){
    int age;
    char first[20];

    printf("Enter your first name: ");
    scanf("%s", first);

    printf("Enter your age: ");
    scanf("%d", &age);

    char *msg = my_msg(first, age);

    printf("%s", msg);

    return 0;
}