#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
struct Node {
    int data;           //this node's data
    struct Node *next;  //points to the next node
};

typedef struct List{
    struct Node *head;  //pointer of the first node in this list
    int size;
}linkedlist_t;

//create an empty linked list and return its reference
struct List * make_list(){
    struct List* list =(struct List*) malloc(sizeof(struct List));
    list->head = NULL;  //the first node 
    list->size = 0;     //the size
    return list;
}
//add a node to a list using its data
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
    struct Node* curr = list->head;
    //Stop when the last node is accessed
    while(curr != NULL){
        printf("%d   ", curr->data);
        //Get to the next node
        curr = curr->next;
    }
    printf("\n");
}
//Delete the node with data in the list
int delete(struct List* list, int removed){
    struct Node* curr = list->head;
    struct Node* prev = NULL;
    //Stop when the last node is accessed
    while(curr != NULL){
        //Compare the data and remove the current node if needed
        if(curr->data == removed){
            //The current node is somewhere in the middle
            if(prev != NULL){ 
                prev->next = curr->next;
            }
            //The current node is the head
            else{
                list->head = curr->next;
            }
            list->size --;
            //Nodes are created using malloc, so we are removing the current node
            free(curr);
            return 1; //assuming that data is unique
        }
        //Get to the next node
        prev = curr;
        curr = curr->next;
    }
    //Fail to delete if there are errors, used to debug
    return 0;
}

// ================= Lab 4's work begins here =======================

//Create a copy of the list by adding nodes from original list to target list
int copy_to_list (struct List *target, struct Node *node){
    if(node == NULL){
        return 1;
    }
    else{
        add(target, node->data);
        copy_to_list(target, node->next);
    }
}

int pof(struct Node *node){
    if (node == NULL){
        return 1;
    }
    else{
        pof(node->next);
        printf("%d  ", node->data);
    }
}

void print_oldest_first(struct List *list){
    pof(list->head);
    printf("\n");
}

//Traverse the source list and add the maximum value to the target
int add_sorted(struct List *target, struct List *source){
    struct Node *curr = source->head;
    int max = curr->data;
    while(curr != NULL){
        if(curr->data > max){
            max = curr->data;
        }
        curr = curr->next;
    }
    add(target, max);
    return max;
}
struct List * sort(struct List *list){
    struct List *sorted = make_list();

    struct List *copy = make_list();
    copy_to_list(copy, list->head);

    struct Node *j = copy->head;
    while(j != NULL){
        int max = add_sorted(sorted, copy);
        delete(copy, max);
        j = copy->head; //reset the position of j to start over again
    }
    free(copy);
    return sorted;
}

//Delete the Node at specified index
int delete_at(struct List* list, int r_index){
    struct Node* curr = list->head;
    struct Node* prev = NULL;
    int c_index = 0;
    //Stop when the last node is accessed
    while(curr != NULL){
        //Compare the data and remove the current node if needed
        if(c_index == r_index){
            //The current node is somewhere in the middle
            if(prev != NULL){ 
                prev->next = curr->next;
            }
            //The current node is the head
            else{
                list->head = curr->next;
            }
            list->size --;
            free(curr);
            printf("data at %d is deleted.\n", r_index);
            return 1; //Successfully delete the node
        }
        //Get to the next node
        prev = curr;
        curr = curr->next;
        c_index ++;
    }
    //Fail to delete if there are errors - most likely invalid index
    printf("%d is not a valid index.\n", r_index);
    return 0;
}
//Change a Node at index to have new_data as its data
bool update(struct List *list, int index, int new_data){
    struct Node* curr = list->head;
    struct Node* prev = NULL;
    int c_index = 0;
    //Stop when the last node is accessed
    while(curr != NULL){
        if(c_index == index){
            curr->data = new_data;
            return true;
        }
        curr = curr->next;
        c_index ++;
    }
    printf("%d is not a valid index.\n", index);
    return false;
}
//Create a reverse copy of the list
struct List *reverse (struct List *list){
    struct List *new_list = make_list();
    struct Node *curr = list->head;
    while(curr != NULL){
        add(new_list, curr->data);
        curr = curr->next;
    }
    return new_list;
}
//Insert list2 at location index into list1
//Return a copy
//Neither list1 nor list2 will be modified
struct List * insert(struct List *list1, struct List *list2, int index){
    struct List *result = make_list();
    struct Node *curr1 = list1->head;
    struct Node *curr2 = list2->head;
    int c_index = 0;
    int length1 = 0;
    while(curr1 != NULL){
        length1++;
        curr1 = curr1->next;
    }
    if(index >length1){
        printf("%d is not a valid index.\n", index);
        return NULL;
    }
    curr1 = list1->head;
    while(curr1 != NULL){
        if(c_index == index){
            while(curr2 != NULL){
                add(result, curr2->data);
                curr2 = curr2->next;
            }
        }
        add(result,curr1->data);
        c_index ++;
        curr1 = curr1->next;
    }
    return reverse(result);
}
int main(){
    linkedlist_t *list1 = make_list();
    add(list1, 20);
    add(list1, 10);
    add(list1, 15);
    add(list1, 10);
    add(list1, 5);
    add(list1, 30);
    print_list(list1);
    printf("======================\n");

    printf("Test 1 - print_oldest:\n");
    print_oldest_first(list1);
    
    printf("Test 2 - sort:\n");
    print_list(sort(list1));

    
    printf("Test 3 - insert:\n");
    linkedlist_t *list2 = make_list();
    //struct List *list2 = make_list(); 
    add(list2, 100);
    add(list2, 200);
    insert(list1, list2, 7);
    print_list(insert(list1, list2, 0));
    print_list(insert(list1, list2, 6));
    print_list(insert(list1, list2, 3));
    
    printf("Test 4 - update:\n");
    if(update(list1, 6, 50)){
        print_list(list1);
    }
    if(update(list1, 5, 500)){
        print_list(list1);
    }
    if(update(list1, 4, 400)){
        print_list(list1);
    }

    printf("Test 5 - delete_at:\n");
    delete_at(list1, 5);
    print_list(list1);

    delete_at(list1, 2);
    print_list(list1);

    delete_at(list1, 0);
    print_list(list1);
    
}


