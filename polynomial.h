#include <stdio.h>
#include <stdlib.h>

typedef struct node *link; // type definition of link as pointer to node

struct node { // node structure
    int coef; // coefficient of term
    int pow; // power of term
    link next; // pointer to next node
};
