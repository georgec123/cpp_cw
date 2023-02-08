#include <stdio.h>
#include <stdlib.h>
#include "Q5i.c"


void return_sleepy_fractions()
{   
    const int size1 = 9;

    int numerator;
    int denominator;

    //arr1 contains all the elements our first digit in the numerator/denominator can take
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    //Loop through each elemnt in arr and pass to our function 
    for (int i = 0; i < size1; i++) {
        all_elements(arr1[i]);
    }
    for (int j = 0; j < size1; j++) {
        for (int k = 0; k < size1; k++) {
            numerator = (arr1[j] * 10);
            denominator = (arr1[k] * 10);
            printf("%i/%i, ", numerator, denominator);
        }
    }
}

int main() {
    return_sleepy_fractions();
}
