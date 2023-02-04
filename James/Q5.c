#include <stdio.h>
#include <stdlib.h>
#include "Q5i.c"


void return_sleepy_fractions()
{   
    //Define an array of all the integers from 1 to 9 inclusive. Exclude 0 since the first value of the numerator and denominator can not be 0
    const int size = 9;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    //Loop through each elemnt in arr and pass to our function 
    for (int i = 0; i < size; i++) {
        all_elements(arr[i]);
    }
}

int main() {
    return_sleepy_fractions();
}
