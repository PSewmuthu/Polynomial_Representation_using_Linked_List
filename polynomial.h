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

link search(list *l, int coef, int pow){ // search for node with given coefficient and power
    link temp = l->head; // set temp to head

    while (temp != NULL){ // while temp is not NULL
        if (coef == NULL){ // if coefficient is NULL
            if (temp->pow == pow){ // if power of temp is equal to given power
                return temp; // return temp
            }
        } else { // if coefficient is not NULL
            if (temp->coef == coef && temp->pow == pow){ // if coefficient and power of temp is equal to given coefficient and power
                return temp; // return temp
            }
        }

        temp = temp->next; // set temp to next node
    }

    return NULL; // return NULL if node is not found
}

void insertNext(list *l, int coef, int pow, link temp){ // insert node after given node
    link t = search(l, coef, pow); // search for node with given coefficient and power

    if (t == NULL){ // if node is not found
        printf("Node not found!\n"); // print error message
    } else { // if node is found
        temp->next = t->next; // set next pointer of new node to next pointer of given node
        t->next = temp; // set next pointer of given node to new node
    }
}

void deleteNode(list *l, int coef, int pow){ // delete node with given coefficient and power
    link temp = search(l, coef, pow); // search for node with given coefficient and power

    if (temp == NULL){ // if node is not found
        printf("Node not found!\n"); // print error message
    } else { // if node is found
        if (temp == l->head){ // if node is head
            l->head = temp->next; // set head to next node
        } else { // if node is not head
            link t = l->head; // set t to head

            while (t->next != temp){ // while next pointer of t is not equal to temp
                t = t->next; // set t to next node
            }

            t->next = temp->next; // set next pointer of t to next pointer of temp
        }

        free(temp); // free memory of temp
    }
}
