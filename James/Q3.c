#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float a;
    float a_new;
    float min;
    float max;
    float rng;
    float count;

    printf("Please input your first value: \n");
    scanf("%f", &a);
    ++count;
    min = a;
    max = a;

    while (a > 0) {
        printf("Oh damn, let's try again. Please input a new value: \n");
        scanf("%f", &a_new);

        if (a_new > a){
            max = a_new;
        } else if (a_new < a){
            min = a_new;
        }
        rng = max - min;
        ++count;
        a = a_new;
    }

    printf("We've found a negative number. \n");
    printf("Max: %f\n Min: %f\n Range: %f\n Count %f\n", max, min, rng, count);
    
}
