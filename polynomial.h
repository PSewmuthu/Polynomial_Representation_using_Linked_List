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
