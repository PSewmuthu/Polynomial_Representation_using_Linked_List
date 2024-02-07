#include <conio.h>
#include "polynomial.h" // include user defined header file

void arrowHere(int realPosition, int arrowPosition){ // function to print arrow
    if(realPosition == arrowPosition){ // if realPosition is equal to arrowPosition
        printf("------>> "); // print arrow indicating current position
    } else { // if realPosition is not equal to arrowPosition
        printf("         "); // print spaces
    }
}

int menu(){ // function to display menu
    system("cls"); // clear screen

    int position = 1; // declare and initialize position to 1
    int keyPressed = 0; // declare and initialize keyPressed to 0

    while(keyPressed != 13){ // while keyPressed is not equal to 13
        system("cls"); // clear screen

        printf("================Polynomial Functions Calculator================\n\n"); // print title

        arrowHere(1, position); printf("1. Insert values from the front side.\n"); // print menu option 1
        arrowHere(2, position); printf("2. Insert values from the rear side.\n"); // print menu option 2
        arrowHere(3, position); printf("3. Insert a value after an existing value.\n"); // print menu option 3
        arrowHere(4, position); printf("4. Search an element.\n"); // print menu option 4
        arrowHere(5, position); printf("5. Delete an element.\n"); // print menu option 5
        arrowHere(6, position); printf("6. Show the maximum power.\n"); // print menu option 6
        arrowHere(7, position); printf("7. Add two polynomial functions.\n"); // print menu option 7
        arrowHere(8, position); printf("8. Substract two polynomial functions.\n"); // print menu option 8
        arrowHere(9, position); printf("9. Quite\n"); // print menu option 9

        keyPressed = getch(); // get key pressed

        if(keyPressed == 80 && position != 9){ // if down arrow key is pressed and position is not 4
            position++; // increment position
        } else if (keyPressed == 72 && position != 1){ // if up arrow key is pressed and position is not 1
            position--; // decrement position
        } else { // if any other key is pressed or position is 1 or 4
            position = position; // set position to position
        }
    }

    return position; // return position
}

int main(){
    list *l1, *l2, *l3; // declare three lists

    l1 = (list*)malloc(sizeof(list)); // allocate memory for l1
    l2 = (list*)malloc(sizeof(list)); // allocate memory for l2
    l3 = (list*)malloc(sizeof(list)); // allocate memory for l3

    initList(l1); // initialize l1
    initList(l2); // initialize l2
    initList(l3); // initialize l3

    int position; // declare position

    system("COLOR 0A"); // set background color to black and text color to green

    while (position != 9){ // while position is not 9
        position = menu(); // get position from menu

        switch(position){ // switch position
            case 1: // if position is 1
                printf("Enter the coefficient and power of the polynomial with space separation(<coefficient> <power>) for each term. Enter -1 to stop.\n"); // print message

                int coef, pow, i=1; // declare coef and pow

                while(coef != -1){ // while coef is not equal to -1
                    printf("Enter the values for term %d: ", i); // print message
                    scanf("%d %d", &coef, &pow); // get coef and pow from user

                    if(coef != -1){ // if coef is not equal to -1
                        insertFront(l1, newNode(coef, pow)); // insert from front
                    }

                    i++; // increment i
                }

                printf("\n\nEntered polynomial is: "); // print message
                display(l1); // display polynomial
                printf("\n\n"); // print new line

                break; // break

            case 2: // if position is 2
                printf("Enter the coefficient and power of the polynomial with space separation for each term. Enter -1 to stop.\n"); // print message

                int coef, pow, i=1; // declare coef and pow

                while(coef != -1){ // while coef is not equal to -1
                    printf("Enter the values for term %d: ", i); // print message
                    scanf("%d %d", &coef, &pow); // get coef and pow from user

                    if(coef != -1){ // if coef is not equal to -1
                        insertRear(l2, newNode(coef, pow)); // insert from front
                    }

                    i++; // increment i
                }

                printf("\n\nEntered polynomial is: "); // print message
                display(l1); // display polynomial
                printf("\n\n"); // print new line

                break; // break

            case 3: // if position is 3
                printf("For which list do you want to insert a value after an existing value? (1/2): "); // print message
                
                int old_coef, old_pow, new_coef, new_pow, listNum; // declare coef and pow

                scanf("%d", &listNum); // get listNum from user

                printf("\nAfter which element do you want to insert a value? "); // print message
                scanf("%d %d", &old_coef, &old_pow); // get coef and pow from user

                printf("\nEnter the coefficient and power of the new term: "); // print message
                scanf("%d %d", &new_coef, &new_pow); // get coef and pow from user

                if (listNum == 1){ // if listNum is 1
                    insertNext(l1, old_coef, old_pow, newNode(new_coef, new_pow)); // insert next

                    printf("\nUpdated polynomial is: "); // print message
                    display(l1); // display polynomial
                    printf("\n\n"); // print new line
                } else { // if listNum is not 1
                    insertNext(l2, old_coef, old_pow, newNode(new_coef, new_pow)); // insert next

                    printf("\nUpdated polynomial is: "); // print message
                    display(l2); // display polynomial
                    printf("\n\n"); // print new line
                }

                break; // break

            case 4: // if position is 4
                printf("For which list do you want to search an element? (1/2): "); // print message

                int coef, pow, listNum; // declare coef and pow

                scanf("%d", &listNum); // get listNum from the user

                printf("\nEnter the coefficient of the term you want to search: "); // print message
                scanf("%d", &coef); // get coefficient from the user

                printf("\nEnter the power of the term you want to search: "); // print message
                scanf("%d", &pow); // get power from the user

                if (listNum == 1){
                    if (search(l1, coef, pow) == NULL){
                        printf("\n\nElement not found!\n");
                    } else {
                        printf("\n\nElement found!\n");
                    }
                } else {
                    if (search(l2, coef, pow) == NULL){
                        printf("\n\nElement not found!\n");
                    } else {
                        printf("\n\nElement found!\n");
                    }
                }

                printf("\n"); // print new line

                break; // break

            case 5: // if position is 5
                printf("From which list do you want to delete an element? (1/2): "); // print message

                int coef, pow, listNum; // declare coef and pow

                scanf("%d", &listNum); // get listNum from the user

                printf("\nEnter the coefficient and power of the term you want to delete: "); // print message
                scanf("%d %d", &coef, &pow); // get coef and pow from the user

                if (listNum == 1){
                    deleteNode(l1, coef, pow); // delete node

                    printf("\nUpdated polynomial is: "); // print message
                    display(l1); // display polynomial
                    printf("\n\n"); // print new line
                } else {
                    deleteNode(l2, coef, pow); // delete node

                    printf("\nUpdated polynomial is: "); // print message
                    display(l2); // display polynomial
                    printf("\n\n"); // print new line
                }

                break; // break

            case 6: // if position is 6
                printf("For which list do you want to show the maximum power? (1/2): "); // print message

                int listNum; // declare listNum

                scanf("%d", &listNum); // get listNum from the user

                if (listNum == 1){
                    printf("\nMaximum power is: %d\n\n", maxPow(l1)->pow); // print maximum power
                } else {
                    printf("\nMaximum power is: %d\n\n", maxPow(l2)->pow); // print maximum power
                }

                break; // break

            case 7: // if position is 7
                printf("Resultant polynomial is: "); // print message
                
                l3 = add(l1, l2); // add polynomials

                display(l3); // display polynomial
                printf("\n\n"); // print new line

                break; // break

            case 8: // if position is 8
                printf("From which polynomial do you want to subtract another polynomial? (1/2): "); // print message

                int listNum; // declare listNum

                scanf("%d", &listNum); // get listNum from the user

                if (listNum == 1){
                    l3 = subtract(l1, l2); // subtract polynomials
                } else {
                    l3 = subtract(l2, l1); // subtract polynomials
                }

                printf("Resultant polynomial is: "); // print message
                display(l3); // display polynomial
                printf("\n\n"); // print new line

                break; // break

            default: // if position is 9
                printf("Goodbye!\n"); // print goodbye
        }

        printf("\n\n"); // print new line
    }

    return 0; // return 0
}
