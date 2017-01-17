#include <stdio.h>
#include <stdlib.h>
struct list_item {
    int value;
    struct list_item *next;
};

/* puts x at the end of the list */
void append(struct list_item *first, int x);
  
/* puts x at the beginning of the list */
void prepend(struct list_item *first, int x); 

/* prints all elements in the list */
void print(struct list_item *first);  

/* input_sorted: find the first element in the list larger than x
     and input x right before that element */
void input_sorted(struct list_item *first, int x);

/* free everything dynamically allocated */
void clear(struct list_item *first);

/* creates a new node allocated in memory*/
struct list_item * createNode(int x){
    struct list_item *newNode;
    newNode = (struct list_item *) malloc(sizeof(struct list_item));
    newNode->value = x;
    newNode->next = NULL;
    return newNode;
}

void append(struct list_item * first, int x){
    struct list_item *newNode = createNode(x);
    while(first->next != NULL){
        first = first->next;
    }
    first->next = newNode;
}

void prepend(struct list_item *first, int x){
     struct list_item *newNode = createNode(x);
     newNode->next = first->next;
     first->next = newNode;
}

void print(struct list_item *first){
    if(first->next != NULL){
        first = first->next;
        while(first != NULL){
            printf("%d", first->value);
            first = first->next;
        }
        printf("\n");
    }
}

void input_sorted(struct list_item *first, int x){
    struct list_item *newNode = createNode(x);
    while(first->next != NULL){
        if(x < first->next->value){
            newNode->next = first->next;
            first->next = newNode;
            break;
        }
        first = first->next;
    }
    if(newNode->next == NULL){
        first->next = newNode;
    }
}

void clear(struct list_item *first){
    if(first->next != NULL){
        struct list_item *root = first;
        first = first->next;
        while(first != NULL){
            struct list_item *delNode = first;
            first = first->next;
            free(delNode);
        }
        first = root;
        first->next = NULL;
    }
}

int main(){
    struct list_item root;
    root.value = -1;
    root.next = NULL;
    
    append(&root, 1);
    append(&root, 2);
    prepend(&root, 3);
    input_sorted(&root, 2);
    input_sorted(&root, 6);
    print(&root);
    clear(&root);
    print(&root);

    append(&root, 3);
    prepend(&root, 2);
    append(&root, 1);
    input_sorted(&root, 6);
    input_sorted(&root, 2);
    print(&root);
    clear(&root);
    print(&root);
}