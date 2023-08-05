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
    struct linkedlist list;
    list.head = NULL; 
    list.size = 0;
    return list;

}

void add(struct linkedlist *list, int data){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = list->head;
    list->size += 1;

}

 

int delete(struct linkedlist *list, int data){
   struct node *curr = list->head;
   struct node *prev = NULL;
    while (curr != NULL){
        if (curr->data == data){
            prev->next = curr->next;
            free(curr);
            list->size -= 1;
            return 1;

        }

        prev = curr;
        curr = curr->next;
    }
    return 0;
}

int main(){
    struct linkedlist list = make_list();
    add(&list, 10);
    add(&list, 20);
    add(&list, 30);

    delete(&list, 40);
    delete(&list, 10);
    delete(&list, 30);  

    return 0;

}