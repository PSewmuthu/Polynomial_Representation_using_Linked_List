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

void insertFront(list *l, link temp){ // insert node at front of list
    if (l->head == NULL){ // if list is empty
        l->head = l->tail = temp; // set head and tail to new node
    } else { // if list is not empty
        temp->next = l->head; // set next pointer of new node to head
        l->head = temp; // set head to new node
    }
}

void insertRear(list *l, link temp){ // insert node at rear of list
    if (l->head == NULL){ // if list is empty
        l->head = l->tail = temp; // set head and tail to new node
    } else { // if list is not empty
        l->tail->next = temp; // set next pointer of tail to new node
        l->tail = temp; // set tail to new node
    }
}
