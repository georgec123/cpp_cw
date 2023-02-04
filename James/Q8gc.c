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
struct node *addition(struct node *ptr1, struct node *ptr2);
struct node *subtraction(struct node *ptr1, struct node *ptr2);
struct node *multiplication(struct node *ptr1, struct node *ptr2);
int evaluation(struct node *ptr1, int num);
void display(char const *string, struct node *ptr);

struct node *new_empty_node(void)
{
    // Create a new empty node

    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    if (ptr == 0)
    {
        printf("Out of Memory Space:\n");
        exit(0);
    }

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

struct node *addition(struct node *ptr1, struct node *ptr2)
{
    // ptr1 + ptr2

    /*
    We loop through both pointers, and add the coefficients of the nodes with the same exponent
    If one coef is bigger than the other, we set the value of p_add to that value, and only increment that polynomial
    */

    struct node *p_add = NULL;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        struct node *ptr = new_empty_node();

        if (ptr1->exp > ptr2->exp)
        {
            // ptr1 has a higher exponent than ptr2
            // set ptr (p_add) value to ptr1 value
            ptr->exp = ptr1->exp;
            ptr->coeff = ptr1->coeff;

            // and increment ptr1
            ptr1 = ptr1->next;
        }
        else if (ptr1->exp < ptr2->exp)
        {
            // ptr2 has a higher exponent than ptr1
            // set ptr (p_add) value to ptr2 value

            ptr->exp = ptr2->exp;
            ptr->coeff = ptr2->coeff;

            // and increment ptr2
            ptr2 = ptr2->next;
        }
        else
        {
            // ptr1 and ptr2 have the same exponent
            // set ptr (p_add) value to the sum of the two coefficients

            ptr->exp = ptr1->exp;
            ptr->coeff = ptr1->coeff + ptr2->coeff;

            // and increment both ptr1 and ptr2
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        ptr->next = NULL;
        p_add = push(ptr, p_add);
    }

    struct node *non_null_node;
    if (ptr1 != NULL)
    {
        non_null_node = ptr1;
    }
    else if (ptr2 != NULL)
    {
        non_null_node = ptr2;
    }
    else
    {
        return p_add;
    }

    // if we have reached the end of one of the polynomials, we add the rest of the other polynomial to p_add
    struct node *right_copy = copy_polynomial(non_null_node);
    p_add = concat_polynomails(p_add, right_copy);
    return p_add;
}

struct node *subtraction(struct node *ptr1, struct node *ptr2)
{
    /*
    can just multiply the coefficients of the second polynomial by -1, and add the two polynomials.
    But this takes up extra space to cater for the new negative polynomial

    */

    // ptr1 - ptr2
    struct node *p_sub = NULL;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        struct node *ptr = new_empty_node();

        if (ptr1->exp > ptr2->exp)
        {
            // ptr1 has a higher exponent than ptr2, so we set ptr (p_sub) value to ptr1 value
            ptr->exp = ptr1->exp;
            ptr->coeff = ptr1->coeff;
            ptr1 = ptr1->next;
        }
        else if (ptr1->exp < ptr2->exp)
        {
            // ptr2 has a higher exponent than ptr1, so we set ptr (p_sub) value to -1*ptr2 value
            ptr->exp = ptr2->exp;
            ptr->coeff = -1 * ptr2->coeff;
            ptr2 = ptr2->next;
        }
        else
        {
            // ptr1 and ptr2 have the same exponent
            // set ptr (p_sub) value to the difference of the two coefficients
            ptr->exp = ptr1->exp;
            ptr->coeff = ptr1->coeff - ptr2->coeff;

            // and increment both ptr1 and ptr2
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        if (ptr1->coeff - ptr2->coeff != 0)
        {
            ptr->next = NULL;
            p_sub = push(ptr, p_sub);
        }
        else
        {
            // if the coefficients are the same, we don't add the node to p_sub
            free(ptr);
        }
    }

    if (ptr1 != NULL)
    {
        // if we have reached the end of ptr2, we add the rest of ptr1 to p_sub
        p_sub = concat_polynomails(p_sub, ptr1);
        return p_sub;
    }
    else if (ptr2 == NULL)
    {
        // if we have reached the end of both polynomials, we return p_sub
        return p_sub;
    }
    else
    {
        // if we have reached the end of ptr1, we subtract the rest of ptr2 to p_sub
        struct node *ptr2_copy = copy_polynomial(ptr2);
        struct node *ptr2_copy_iter = ptr2_copy;

        // we multiply the coefficients of ptr2_copy by -1
        while (ptr2_copy_iter != NULL)
        {
            ptr2_copy_iter->coeff = -1 * ptr2_copy_iter->coeff;
            ptr2_copy_iter = ptr2_copy_iter->next;
        }

        // and add the result to p_sub
        p_sub = concat_polynomails(p_sub, ptr2_copy);
        return p_sub;
    }
}

struct node *multiplication(struct node *ptr1, struct node *ptr2)
{

    if (ptr1 == NULL || ptr2 == NULL)
    {
        // Given that we only store non zero coefficients, if either polynomial is NULL (ie a zero polynomial)
        // the result is 0

        struct node *ptr = new_empty_node();
        return ptr;
    }

    // ptr1 * ptr2
    struct node *p_multi = NULL;
    struct node *ptr2_dummy = new_empty_node();

    struct node *ptr_add_dummy = NULL;

    struct node *ptr = new_empty_node();

    while (ptr1 != NULL)
    {
        ptr2_dummy = ptr2;
        while (ptr2_dummy != NULL)
        {
            // create a new node for the multiplication of ptr1 and ptr2_dummy
            ptr->exp = ptr1->exp + ptr2_dummy->exp;
            ptr->coeff = ptr1->coeff * ptr2_dummy->coeff;
            ptr->next = NULL;

            // iterae ptr2_dummy
            ptr2_dummy = ptr2_dummy->next;

            // add the new node to p_multi
            struct node *old_mult = p_multi;
            p_multi = addition(p_multi, ptr);

            // free the old p_multi as addition function creates a new polynomial
            free(old_mult);
        }
        ptr1 = ptr1->next;
    }
    return p_multi;
}

int evaluation(struct node *ptr1, int x)
{
    // ptr1(num)
    int total = 0;

    int last_coef = 0;
    int last_exp = ptr1->exp + 1;

    while (ptr1 != NULL)
    {
        if (ptr1->exp == last_exp - 1)
        {
            // normal Horner method
            total += last_coef * x + ptr1->coeff;
        }
        else
        {
            // Horner method with a gap in the exponents
            // same as (((total*x +0)*x +0)*x +0...)
            total += last_coef * pow(x, last_exp - ptr1->exp - 1);
        }
        last_coef = ptr1->coeff;
        last_exp = ptr1->exp;
        ptr1 = ptr1->next;
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

    printf("Enter for your first polynomial: \n");
    p1 = create(p1);
    printf("Enter for your second polynomial: \n");
    p2 = create(p2);

    display("Polynomial 1: ", p1);
    display("Polynomial 2: ", p2);

    printf("What shall we do with our new polynomials: Add (A), subtract (S), multiply (M) or evaluate (E)? \n");
    scanf(" %c", &action);

    switch (action)
    {
    case 'A':
        display("We have a new polynomial: ", addition(p1, p2));
        break;
    case 'S':
        display("We have a new polynomial: ", subtraction(p1, p2));
        break;
    case 'M':
        display("We have a new polynomial: ", multiplication(p1, p2));
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

    return 0;
}
