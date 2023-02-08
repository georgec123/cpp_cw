#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "header.h"

int main()
{
    char action;
    int choice;
    int number;
    int end = 0;
    struct node *p1 = NULL, *p2 = NULL, *p_sol = NULL;

    printf("Enter for your first polynomial: \n");
    p1 = create(p1);
    printf("Enter for your second polynomial: \n");
    p2 = create(p2);

    display("Polynomial 1", p1);
    display("Polynomial 2", p2);


    while (end!=1) {

        printf("\nAdd (A), subtract (S), multiply (M) or evaluate (E)? (Q) to quit. \n");
        scanf(" %c", &action);

        switch (action)
        {
        case 'A':
            display("Result", addition(p1, p2));
            break;
        case 'S':
            display("Result", subtraction(p1, p2));
            break;
        case 'M':
            display("Result", multiplication(p1, p2));
            break;
        case 'E':

            printf("Which polynomial would you like to evaluate? (1/2) \n");
            scanf(" %d", &choice);
            if (choice != 1 && choice != 2)
            {
                printf("You have to pick either your first or second polynomial I'm afraid \n");
                exit(EXIT_FAILURE);
            }

            printf("Please enter an integer for x in your polynomial \n");
            scanf(" %d", &number);
            
            if (isdigit(number))
            {
                printf("That is not an integer \n");
                exit(EXIT_FAILURE);
            }
            else
            {
                if (choice == 1)
                    printf("Result: %d", evaluation(p1, number));
                else
                    printf("Result: %d", evaluation(p2, number));
                break;
            }
        case 'Q':
            end = 1;
        }
    }

    system("pause");
    return 0;
}
