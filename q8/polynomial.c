#include "header.h"

struct node *new_empty_node(void)
{
    // Create a new empty node

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == 0)
    {
        printf("Out of Memory Space:\n");
        exit(0);
    }
    
    // set all values to 0
    ptr->coeff = NULL;
    ptr->exp = NULL;
    ptr->next = NULL;

    return ptr;
}

struct node *create(struct node *p)
{
    int n;
    printf("Number of higest power of the polynomial: ");
    scanf("%d", &n);

    printf("Enter polynomial terms: \n");
    for (int i = n; i >= 0; i--)
    {
        struct node *ptr = new_empty_node();

        printf("Enter your coefficient of x^%d: ", i);
        if (scanf("%d", &ptr->coeff) != 1)
        {
            printf("You gave me too many values");
            exit(0);
        }
        else if (ptr->coeff != 0)
        {
            // only add to list if non zero
            ptr->exp = i;
            ptr->next = NULL;
            p = push(ptr, p);
        }
        else
        {
            // free memory if zero
            free(ptr);
        }
    }
    display("Thanks, here is your current polynomial", p);

    return p;
}

struct node *push(struct node *new_node, struct node *polynomial)
{ /*
  Insert one node at the correct point in a polynomial
  Modifies inplace and returns pointer to the polynomial
  */

    struct node *temp, *val;
    if (polynomial == NULL)
    {
        //
        polynomial = new_node;
        return polynomial;
    }
    else if (polynomial->exp < new_node->exp)
    {
        // New node has a higher exponent than the existing polynomial
        // So we add it to the front of the existing polynomial
        new_node->next = polynomial;
        polynomial = new_node;

        return polynomial;
    }
    else
    {
        // New node has a lower exponent than the existing node
        // So we add it to the right of the existing node
        // We need to find the right place to add it
        temp = polynomial;
        while ((temp->next != NULL) && (temp->next->exp > new_node->exp))
        {
            temp = temp->next;
        }

        // existing_high_power -> new_right_node -> existing_low_power
        val = temp->next;
        temp->next = new_node;
        new_node->next = val;
    }
    return polynomial;
}

void display(char const *string, struct node *ptr)
{
    struct node *temp;
    const char *dummy = "";
    temp = ptr;
    printf("%s: ", string);

    if (temp == NULL) {
        // null node, so 0
        printf("0");
    }

    while (temp != NULL)
    {
        printf("%s%dx^%d", dummy, temp->coeff, temp->exp);
        temp = temp->next;
        // dummy = " + ";
        if ((temp != NULL))
        {
            if (temp->coeff >= 0)
            {
                dummy = " + ";
            }
            else
            {
                dummy = " ";
            }
        }
    }
    putchar('\n');
}

struct node *concat_polynomails(struct node *left, struct node *right)
{
    /*
    Concatenate two polynomials inplace
    */

    struct node *temp = left;

    if (left == NULL)
    {
        return right;
    }
    else if (right == NULL)
    {
        return left;
    }

    // find the end of the left polynomial
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // add the right polynomial to the end of the left polynomial
    temp->next = right;
    return left;
}

struct node *copy_polynomial(struct node *polynomial)
{
    /*
    Copy a polynomial, and return a pointer to the new polynomial
    */

    struct node *new_polynomial = NULL;
    struct node *temp = polynomial;

    while (temp != NULL)
    {
        // allocate memory for new node
        struct node *ptr = new_empty_node();

        // set the values of the new node
        ptr->exp = temp->exp;
        ptr->coeff = temp->coeff;
        ptr->next = NULL;

        // add the new node to the new polynomial
        new_polynomial = push(ptr, new_polynomial);

        // increment the old polynomial
        temp = temp->next;
    }
    return new_polynomial;
}