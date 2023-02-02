#include <stdio.h>
#include <stdlib.h>
#include "Q5i.c"

const int size = 9;
int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; //First elems

void return_sleepy_fractions()
{   
    //If 0 is the 2nd and 4th elements then the fraction always satisfies these conditions. Consider this as a separate case
    for (int i = 0; i < size; i++) {
        all_elements(arr[i]);
    }
}

int main() {
    return_sleepy_fractions();
}
