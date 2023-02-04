#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
};


// polynomial.c
struct node* new_empty_node(void);
struct node *create(struct node *p);
struct node *push(struct node *ptr, struct node *q);
void display(char const* string, struct node* ptr);
struct node* concat_polynomails(struct node* left, struct node* right);
struct node* copy_polynomial(struct node* polynomial);

// poly_maths.c
struct node *addition(struct node *ptr1, struct node *ptr2);
struct node *subtraction(struct node *ptr1, struct node *ptr2);
struct node *multiplication(struct node *ptr1, struct node *ptr2);
int evaluation(struct node* ptr1, int num);
