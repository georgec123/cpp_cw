#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
};

struct node *create(struct node *p);
struct node *push(struct node *ptr, struct node *q);
struct node *addition(struct node *ptr1, struct node *ptr2, struct node *p_add);
struct node *subtraction(struct node *ptr1, struct node *ptr2, struct node *p_sub);
struct node *multiplication(struct node *ptr1, struct node *ptr2, struct node *p_multi);
int evaluation(struct node *ptr1, int num);
void display(char const *string, struct node *ptr);

struct node *create(struct node *p)
{
    int n;
    printf("Number of non-zero terms in the polynomial: ");
    scanf("%d", &n);

    printf("Enter polynomial terms: \n");
    for (int i = 0; i < n; i++)
    {
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        if (ptr == 0)
        {
            printf("Out of Memory Space:\n");
            exit(0);
        }
        printf("Enter your coefficient and exponent values: ");
        if (scanf("%d %d", &ptr->coeff, &ptr->exp) != 2)
        {
            printf("You gave me too many values");
            exit(0);
        }
        ptr->next = NULL;
        p = push(ptr, p);
        display("Thanks, here is your current polynomial", p);
    }
    return p;
}

struct node *push(struct node *ptr, struct node *q)
{
    struct node *temp, *val;
    if (q == NULL)
    {
        q = ptr;
    }
    else
    {
        if (q->exp < ptr->exp)
        {
            printf("Greater \n");
            ptr->next = q;
            q = ptr;
        }
        else
        {
            q->next = ptr;
            //printf("Lesser \n");
            //temp = q;
            //while ((temp->next != NULL) && (temp->next->exp < ptr->exp)) {
            //    temp = temp->next;
            //}
            //val = temp->next;
            //ptr->next = val;
            //q = ptr;
        }
    }
    return q;
}

void display(char const *string, struct node *ptr)
{
    struct node *temp;
    const char *dummy = "";
    temp = ptr;
    printf("%s: ", string);
    while (temp != NULL)
    {
        printf("%s%dx^%d", dummy, temp->coeff, temp->exp);
        temp = temp->next;
        dummy = " + ";
    }
    putchar('\n');
}

struct node *addition(struct node *ptr1, struct node *ptr2, struct node *p_add)
{
    //ptr1 + ptr2
    while (ptr1 != NULL && ptr2 != NULL)
    {
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        if (ptr == 0)
        {
            printf("Out of Memory Space:\n");
            exit(0);
        }
        if (ptr1->exp > ptr2->exp)
        {
            ptr->exp = ptr1->exp;
            ptr->coeff = ptr1->coeff;
            ptr1 = ptr1->next;
        }
        else if (ptr1->exp < ptr2->exp)
        {
            ptr->exp = ptr2->exp;
            ptr->coeff = ptr2->coeff;
            ptr2 = ptr2->next;
        }
        else
        {
            ptr->exp = ptr1->exp;
            ptr->coeff = ptr1->coeff + ptr2->coeff;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        ptr->next = NULL;
        p_add = push(ptr, p_add);
    }

    while (ptr1 != NULL || ptr2 != NULL)
    {
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        if (ptr == 0)
        {
            printf("Out of Memory Space:\n");
            exit(0);
        }
        display("", ptr1);
        display("", ptr2);
        display("", ptr);
        printf("%d \n", ptr->coeff);
        printf("%d \n", ptr->exp);
        if (ptr1 != NULL)
        {
            ptr->exp = ptr1->exp;
            ptr->coeff = ptr1->coeff;
            ptr1 = ptr1->next;
        }
        else
        {
            ptr->exp = ptr2->exp;
            ptr->coeff = ptr2->coeff;
            ptr2 = ptr2->next;
        }
        ptr->next = NULL;
        display("", ptr1);
        display("", ptr2);
        display("", ptr);
        printf("%d \n", ptr->coeff);
        printf("%d \n", ptr->exp);
        p_add = push(ptr, p_add);
    }
    return p_add;
}

struct node *subtraction(struct node *ptr1, struct node *ptr2, struct node *p_sub)
{
    //ptr1 - ptr2

    while (ptr1 != NULL && ptr2 != NULL)
    {
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        if (ptr == 0)
        {
            printf("Out of Memory Space:\n");
            exit(0);
        }
        if (ptr1->exp > ptr2->exp)
        {
            ptr->exp = ptr1->exp;
            ptr->coeff = ptr1->coeff;
            ptr1 = ptr1->next;
        }
        else if (ptr1->exp < ptr2->exp)
        {
            ptr->exp = ptr2->exp;
            ptr->coeff = -1 * ptr2->coeff;
            ptr2 = ptr2->next;
        }
        else
        {
            if (ptr1->coeff - ptr2->coeff != 0)
            {
                ptr->exp = ptr1->exp;
                ptr->coeff = ptr1->coeff - ptr2->coeff;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        ptr->next = NULL;
        p_sub = push(ptr, p_sub);
    }

    while (ptr1 != NULL || ptr2 != NULL)
    {
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        if (ptr == 0)
        {
            printf("Out of Memory Space:\n");
            exit(0);
        }
        if (ptr1 != NULL)
        {
            ptr->coeff = ptr1->coeff;
            ptr->exp = ptr1->exp;
            ptr1 = ptr1->next;
        }
        else
        {
            ptr->coeff = -1 * ptr2->coeff;
            ptr->exp = ptr2->exp;
            ptr2 = ptr2->next;
        }
        ptr->next = NULL;
        p_sub = push(ptr, p_sub);
    }
    return p_sub;
}

struct node *multiplication(struct node *ptr1, struct node *ptr2, struct node *p_multi)
{
    //ptr1 + ptr2
    while (ptr1->next != NULL)
    {
        printf("Welcome \n");
        display("", ptr1);
        display("", ptr2);
        display("", p_multi);
        printf("%d \n", ptr1->coeff);
        printf("%d \n", ptr1->exp);
        printf("%d \n", ptr2->coeff);
        printf("%d \n", ptr2->exp);
        display("", ptr1->next);
        while (ptr2->next != NULL)
        {
            printf("Welcome again \n");
            struct node *ptr = (struct node *)malloc(sizeof(struct node));
            if (ptr == 0)
            {
                printf("Out of Memory Space:\n");
                exit(0);
            }
            ptr->exp = ptr1->exp + ptr2->exp;
            ptr->coeff = ptr1->coeff * ptr2->coeff;
            ptr2 = ptr2->next;
            ptr->next = NULL;
            display("", ptr1);
            display("", ptr2);
            printf("%d \n", ptr->coeff);
            printf("%d \n", ptr->exp);
            display("", p_multi);
            p_multi = addition(p_multi, ptr, p_multi);
            display("", ptr1);
            display("", ptr2);
            display("", p_multi);
            printf("%d \n", ptr1->coeff);
            printf("%d \n", ptr1->exp);
            printf("%d \n", ptr2->coeff);
            printf("%d \n", ptr2->exp);
            display("", ptr2->next);
        }

        if (ptr2->next == NULL)
        {
            struct node *ptr = (struct node *)malloc(sizeof(struct node));
            if (ptr == 0)
            {
                printf("Out of Memory Space:\n");
                exit(0);
            }
            ptr->exp = ptr1->exp + ptr2->exp;
            ptr->coeff = ptr1->coeff * ptr2->coeff;
            ptr->next = NULL;
            p_multi = addition(p_multi, ptr, p_multi);
            printf("Welcome again again \n");
            display("", ptr1);
            display("", ptr2);
            display("", p_multi);
            printf("%d \n", ptr1->coeff);
            printf("%d \n", ptr1->exp);
            printf("%d \n", ptr2->coeff);
            printf("%d \n", ptr2->exp);
        }
        ptr1 = ptr1->next;
        printf("Welcome some more \n");
        display("", ptr1);
        display("", ptr2);
        display("", p_multi);
        printf("%d \n", ptr1->coeff);
        printf("%d \n", ptr1->exp);
        printf("%d \n", ptr2->coeff);
        printf("%d \n", ptr2->exp);
        display("", ptr1->next);
    }

    if (ptr1->next == NULL)
    {
        while (ptr2->next != NULL)
        {
            struct node *ptr = (struct node *)malloc(sizeof(struct node));
            if (ptr == 0)
            {
                printf("Out of Memory Space:\n");
                exit(0);
            }
            ptr->exp = ptr1->exp + ptr2->exp;
            ptr->coeff = ptr1->coeff * ptr2->coeff;
            ptr2 = ptr2->next;
            ptr->next = NULL;
            p_multi = addition(p_multi, ptr, p_multi);
            printf("Welcome again again again \n");
            display("", ptr1);
            display("", ptr2);
            display("", p_multi);
            printf("%d \n", ptr1->coeff);
            printf("%d \n", ptr1->exp);
            printf("%d \n", ptr2->coeff);
            printf("%d \n", ptr2->exp);
            display("", ptr1->next);
        }

        if (ptr2->next == NULL)
        {
            struct node *ptr = (struct node *)malloc(sizeof(struct node));
            if (ptr == 0)
            {
                printf("Out of Memory Space:\n");
                exit(0);
            }
            ptr->exp = ptr1->exp + ptr2->exp;
            ptr->coeff = ptr1->coeff * ptr2->coeff;
            ptr->next = NULL;
            p_multi = addition(p_multi, ptr, p_multi);
            printf("Welcome again again again again \n");
            display("", ptr1);
            display("", ptr2);
            display("", p_multi);
            printf("%d \n", ptr1->coeff);
            printf("%d \n", ptr1->exp);
            printf("%d \n", ptr2->coeff);
            printf("%d \n", ptr2->exp);
        }
    }
    return p_multi;
}

int evaluation(struct node *ptr1, int num)
{
    //ptr1(num)
    int total = 0;
    while (ptr1->next != NULL)
    {
        total += ptr1->coeff * pow(num, ptr1->exp);
        ptr1 = ptr1->next;
    }

    if (ptr1->next == NULL)
    {
        total += ptr1->coeff * pow(num, ptr1->exp);
    }
    return total;
}

int main()
{
    int ans;
    char action;
    int choice;
    int number;
    struct node *p1 = NULL, *p2 = NULL, *p_sol = NULL;

    printf("How many polynomials will you be entering? \n");
    scanf(" %d", &ans);

    if (ans != 2)
    {
        printf("I'm afraid we can't help you. You'll have to enter two and then repeat \n");
        exit(0);
    }
    else
    {
        printf("Time for your first polynomial: \n");
        p1 = create(p1);

        printf("And now the second: \n");
        p2 = create(p2);

        display("Polynomial 1: ", p1);
        display("Polynomial 2: ", p2);

        printf("What shall we do with our new polynomials: Add (A), subtract (S), multiply (M) or evaluate (E)? \n");
        scanf(" %c", &action);

        switch (action)
        {
        case 'A':
            display("We have a new polynomial: ", addition(p1, p2, p_sol));
            break;
        case 'S':
            display("We have a new polynomial: ", subtraction(p1, p2, p_sol));
            break;
        case 'M':
            display("We have a new polynomial: ", multiplication(p1, p2, p_sol));
            break;
        case 'E':
            printf("Which polynomial would you like to evaluate? (1/2) \n");
            scanf(" %d", &choice);
            if (choice != 1 && choice != 2)
            {
                printf("You have to pick either your first or second polynomial I'm afraid \n");
                exit(0);
            }
            else
            {
                printf("Please enter an integer for x in your polynomial \n");
                scanf(" %d", &number);
                if (isdigit(number))
                {
                    printf("That is not an integer \n");
                    exit(0);
                }
                else
                {
                    if (choice == 1)
                    {
                        printf("The answer is: %d \n", evaluation(p1, number));
                        break;
                    }
                    else
                    {
                        printf("The answer is: %d \n", evaluation(p2, number));
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
