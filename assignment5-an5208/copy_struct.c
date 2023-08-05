#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct person{
    char name[30];
    int age;
}person_t; 

struct person *make_person(char * name, int age){
    person_t *ptr = (person_t *) malloc(sizeof(person_t));
    strcpy(ptr->name,name);
    ptr->age = age;
    return ptr;
}

//create our own memcpy function
void *my_memcpy(const void *dst, const void *src, size_t n){
    unsigned char* d = (unsigned char*) dst;
    unsigned char* s = (unsigned char*) src;
    for (int i = 0; i < n; i++){
        d[i] = s[i];
    }
    return d;
}

int main(){
    person_t *ptr1 = make_person("John Smith", 35);
    //person_t *ptr2 = ptr1; //this only makes ptr2 an alias of ptr1, we only have 1 object
    person_t *ptr2 = (person_t *) malloc(sizeof(person_t));
    memcpy(ptr2, ptr1, sizeof(person_t));
    printf("Using original method, name is %s, age is %d \n", ptr2->name, ptr2->age);
    person_t *ptr3 = (person_t *) malloc(sizeof(person_t));
    my_memcpy(ptr3, ptr1, sizeof(person_t));
    printf("Using new method, name is %s, age is %d \n", ptr3->name, ptr3->age);
}
