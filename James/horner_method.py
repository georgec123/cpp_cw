int evaluation_horner(struct node *ptr1, int num)
{
    //ptr1(num)
    int total = ptr1->coeff;

    while (ptr1->next != NULL)
    {
        if (ptr1->next->exp == ptr1->exp - 1)
        {
            total = (total * num) + ptr1->next->coeff;
        }
        else{
            int i = ptr1->exp;
            while (i != ptr1->next->exp)
            {
                total = (total * num);
                i--;
            }
        }
        ptr1 = ptr1->next;
    }

    if (ptr1->next == NULL)
    {
        if (ptr1->exp != 0)
        {
            int j = ptr1->exp;
            while (j>0)
            {
                total = (total * num);
                j--;
            }
        }
        else
        {
            total += ptr1->coeff;
        }
    }
    return total;
}
