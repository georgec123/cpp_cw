#include <stdio.h>
#include <stdlib.h>


void swap_char_inplace(char *a, char *b)
{
    /* 
    This function swaps the values of two characters in place 
    
    @param a: pointer to the first character
    @param b: pointer to the second character

    @return: void
    */
    int c;
    c = *a;
    *a = *b;
    *b = c;
}


int main(void)
{
    char a, b;

    printf("Input two characters\n");
    scanf("%c %c", &a, &b);

    printf("Original numbers : %c %c\n", a, b);
    swap_char_inplace(&a, &b);
    printf("Reversed numbers : %c %c\n", a, b);

}
