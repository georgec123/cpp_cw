#include "header.h"

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

        if (ptr->coeff != 0)
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

int evaluation(struct node *ptr1, int num)
{
    int total = 0;

    for (int i = ptr1->exp; i >= 0; i--)
    {
        // decrement through the expected increments
        if (ptr1 == NULL)
        {
            // if the pointer is null, we have reached the end, so multiply by x
            total = total * num;
        }
        else if (ptr1->exp == i)
        {
            // pointer is not null, and is expected exponent, so we do normal horner's
            total = total * num + ptr1->coeff;
            ptr1 = ptr1->next;
        }
        else
        {
            // not finished polynomial, but not expected exponent, so we multiply by x (ie total*x +0)
            total = total * num;
        }
    }

    return total;
}