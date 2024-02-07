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
        }

        printf("\n\n"); // print new line
    }

    return 0; // return 0
}
