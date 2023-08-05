#include "stdio.h"
#include "string.h"
#include "stdlib.h"

struct Person{
    char name[20];
    int age;
};

//Have to pass the location of the object
void change(struct Person *p){
    strcpy(p->name, "Jonathan Dollar");
    p->age = 77;
}


int main(){
    struct Person *ptr = (struct Person*) malloc(sizeof(struct Person));
    strcpy(ptr->name, "Jon Buck");
    ptr->age = 20;
    change(ptr);
    printf("Name = %s , age = %d", ptr->name, ptr->age);

    /* The "original" way
    struct Person p = {"Jon Buck", 20}; 
    //name can be declared separately by doing strcpy, age is fine
    change(&p);

    printf("Name = %s , age = %d", p.name, p.age);*/
}