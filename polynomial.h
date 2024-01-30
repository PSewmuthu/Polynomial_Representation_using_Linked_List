#include <stdio.h>
#include <stdlib.h>

typedef struct node *link; // type definition of link as pointer to node

struct node { // node structure
    int coef; // coefficient of term
    int pow; // power of term
    link next; // pointer to next node
};

typedef struct {
    link head; // pointer to head node
    link tail; // pointer to tail node
} list; // type definition of list

void initList(list *l){ // initialize linked list
    l->head = NULL; // set head to NULL
    l->tail = NULL; // set tail to NULL
}

link newNode(int coef, int pow){ // create new node
    link temp = (link)malloc(sizeof(struct node)); // allocate memory for new node
    temp->coef = coef; // set coefficient of new node
    temp->pow = pow; // set power of new node
    temp->next = NULL; // set next pointer of new node to NULL
    
    return temp; // return new node
}
