#include <stdio.h>
#include <stdlib.h>

const int size1 = 9;
const int size2 = 10;

int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; //First elems
int arr2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; //Second elems

void all_elements(int elem)
{
    for (int i = 0; i < size2; i++) {
        int elem_first = (elem * 10) + arr2[i];
        int elem_second = arr2[i];
        for (int j = 0; j < size2; j++) {
            int elem_third = (elem * 10) + arr2[j];
            int elem_fourth = arr2[j];

            int fraction_to_test = (elem_first * elem_fourth) - (elem_second * elem_third);

            if (fraction_to_test == 0) {
                printf("%i %i \n", elem_first, elem_third);
            }
        }
    }

    for (int k = 0; k < size2; k++) {
        int elem_first = (elem * 10) + arr2[k];
        int elem_second = arr2[k];
        for (int l = 0; l < size1; l++) {
            int elem_third = (arr1[l] * 10) + elem;
            int elem_fourth = arr1[l];

            int fraction_to_test = (elem_first * elem_fourth) - (elem_second * elem_third);

            if (elem_first != elem_third && fraction_to_test == 0) {
                printf("%i %i \n", elem_first, elem_third);
                printf("%i %i \n", elem_third, elem_first);
            }
        }
    }
}
