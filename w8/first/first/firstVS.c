#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* my_msg(char* first, char* last, int age) {
    char* msg = (char*)malloc(100);
    //char msg[100];
    sprintf_s(msg, 100, "I am %s %s. \nI am %d year old.", first, last, age);
    return msg;
}

int main() {
    int age;
    char first[20];
    char last[20];

    printf("Enter your first name: ");
    scanf_s("%s", first, 20);
    printf("Enter your last name: ");
    scanf_s("%s", last, 20);
    printf("Enter your age: ");
    scanf_s("%d", &age);

    char* msg = my_msg(first, last, age);
    printf("%s", msg);
    free(msg);

    return 0;
}