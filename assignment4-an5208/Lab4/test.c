#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

struct linkedlist{
    struct node* head;
    int size;
};

struct linkedlist make_list(){
    //struct linkedlist* list = (struct linkedlist*) malloc(sizeof(struct linkedlist*));
    struct linkedlist list;
    list.head = NULL; //
    list.size = 0;
    return list;
}

void add(struct linkedlist *list, int data){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = list->head;
    //2. update list attributes
    list->head = newnode;
    list->size += 1;
}

int main(){
    struct linkedlist list =  make_list();    
    //struct node* head = list->head;
    // Add 10, 20, 30 to the linked list
    add(&list, 10);
    add(&list, 20);
    add(&list, 30);


    return 0;
}