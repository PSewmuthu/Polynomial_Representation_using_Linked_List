#include "polynomial.h"

int main(){
    list *l1, *l2, *l3; // declare three lists

    l1 = (list*)malloc(sizeof(list)); // allocate memory for l1
    l2 = (list*)malloc(sizeof(list)); // allocate memory for l2
    l3 = (list*)malloc(sizeof(list)); // allocate memory for l3

    initList(l1); // initialize l1
    initList(l2); // initialize l2
    initList(l3); // initialize l3
}
