#include <stdio.h>
#include <stdlib.h>


void all_elements(int elem)
{
    const int size1 = 9;
    const int size2 = 10;

    //arr1 contains all the elements our first digit in the numerator/denominator can take
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    //arr1 contains all the elements our second digit in the numerator/denominator can take
    int arr2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    //Define each fraction as ab/cd where a,b,c, and d come from the arrays above. By symmetry, if ab/cd is a sleepy fraction and ab = cd then so too is cd/ab.
    //We can use this property to reduce the number of fractions we must search

    //First fix the value of a in our fraction and loop through b
    for (int i = 0; i < size2; i++) {

        //elem_first represents ab
        int elem_first = (elem * 10) + arr2[i];

        //elem_second represents b
        int elem_second = arr2[i];

        //Now fix the value of c in our fraction and loop through d
        for (int j = 0; j < size2; j++) {

            //elem_third represents cd
            int elem_third = (elem * 10) + arr2[j];

            //elem_fourth represents d
            int elem_fourth = arr2[j];
            
            //If ab/cd is a sleepy fraction then we must have, for fixed a and c, ab/cd = b/d. This can also be written as ab*d - cd*b = 0.
            //This is the test we will use to determine if the fraction is sleepy
            int fraction_to_test = (elem_first * elem_fourth) - (elem_second * elem_third);

            if (fraction_to_test == 0) {
                printf("%i / %i \n", elem_first, elem_third);
            }
        }
    }

    //Fix the value of a in our fraction and loop through b
    for (int k = 0; k < size2; k++) {

        //elem_first represents ab
        int elem_first = (elem * 10) + arr2[k];

        //elem_second represents b
        int elem_second = arr2[k];

        //Now fix the value of d in our fraction and loop through c
        for (int l = 0; l < size1; l++) {

            //elem_third represents cd
            int elem_third = (arr1[l] * 10) + elem;

            //elem_fourth represents c
            int elem_fourth = arr1[l];

            //If ab/cd is a sleepy fraction then we must have, for fixed a and d, ab/cd = b/c. This can also be written as ab*c - cd*b = 0.
            //This is the test we will use to determine if the fraction is sleepy
            int fraction_to_test = (elem_first * elem_fourth) - (elem_second * elem_third);
            
            //In this case we have that the reverse of our digits are also sleepy fractions so we must account for them as well
            if (elem_first != elem_third && fraction_to_test == 0) {
                printf("%i / %i \n", elem_first, elem_third);
                printf("%i / %i \n", elem_third, elem_first);
            }
        }
    }
}
