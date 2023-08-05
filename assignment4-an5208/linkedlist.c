#include "stdio.h"
#include "stdlib.h"

//make_list, add, print, delete

struct Node {
    int data;           //this node's data
    struct Node *next;  //points to the next node
};

struct List{
    struct Node *head;  //pointer of the first node in this list
    int size;
};

//create an empty linked list and return its reference
struct List * make_list(){
    struct List* list =(struct List*) malloc(sizeof(struct List));
    list->head = NULL;  //the first node 
    list->size = 0;     //the size
    return list;
}

//add a node to a list
void add(struct List* list, int data){
    //Create a new node to hold the data
    struct Node *newNode = (struct Node*) malloc((sizeof(struct Node)));
    newNode->data = data;
    //Link new node to the head of the list
    newNode->next = list->head;
    //list->head should now point to newNode
    list->head = newNode;
    //Increase list size to reflect the new node
    list->size += 1;
}

//print all data in the list
void print_list(struct List* list){
    struct Node* currentNode = list->head;
    //Stop when the last node is accessed
    while(currentNode != NULL){
        printf("%d\n", currentNode->data);
        //Get to the next node
        currentNode = currentNode->next;
    }
    printf("\n");
}

//Delete the node with data in the list
int delete(struct List* list, int removed){
    struct Node* currentNode = list->head;
    struct Node* previousNode = NULL;
    //Stop when the last node is accessed
    while(currentNode != NULL){
        //Compare the data and remove the current node if needed
        if(currentNode->data == removed){
            //The current node is somewhere in the middle
            if(previousNode != NULL){ 
                previousNode->next = currentNode->next;
            }
            //The current node is the head
            else{
                list->head = currentNode->next;
            }
            list->size --;
            //Nodes are created using malloc, so we are removing the current node
            free(currentNode);
            return; //assuming that data is unique
        }
        //Get to the next node
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    //Fail to delete if there are errors, used to debug
    return 0;
}

int main(){
    struct List *list = make_list();
    add(list, 10);
    add(list, 20);
    add(list, 30);
    //The last node entered will be the head
    print_list(list);

    delete(list,10);
    print_list(list);
}


