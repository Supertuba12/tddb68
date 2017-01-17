#include <stdio.h>

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
    return newNode;
}

void append(struct list_item * first, int x){
    struct list_item *newNode = createNode(x);
    first->next = newNode;
    newNode->next = NULL;
}

void prepend(struct list_item *first, int x){
     struct list_item *newNode = createNode(x);
     newNode->next = first->next;
     first->next = newNode;
}

void print(struct list_item *first){
    while(first->next != NULL){
        printf("%d", first->value);
        first = first->next;
    }
}

void input_sorted(struct list_item *first, int x){
    if(first->next == NULL){
        struct list_item *newNode = createNode(x);
        first->next = newNode;
        newNode->next = NULL;
    }
    else if(x < first->next->value){
        struct list_item *newNode = createNode(x);
        newNode->next = first->next;
        first->next = newNode;
    } else{
        first = first->next;
        input_sorted(first, x);
    }
}

void clear(struct list_item *first){
    while(first->next != NULL){
        
    }
}

int main(){
    struct list_item root;
    root.value = -1;
    root.next = NULL;

}