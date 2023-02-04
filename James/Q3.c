#include <stdio.h>
#include <stdlib.h>

float *until_first_negative_number()
{
    //Define initial variables
    float a;
    float a_new;

    float min = 0;
    float max = 0;
    float rng = 0;
    float cnt = 0;

    static float results[4];
    
    //Input first value and check if positive. If negative, we are done
    printf("Please input your first value: \n");
    scanf("%f", &a);
    if (a > 0)
    {
        ++cnt;
        min = a;
        max = a;
    }

    while (a > 0)
    {
        //Loop until first negative value is inputted. Only count values up until this point when finding max, min, rng and cnt
        printf("Oh damn, let's try again. Please input a new value: \n");
        scanf("%f", &a_new);

        if (a_new > a)
        {
            max = a_new;
        }
        else if (a_new < a && a_new > 0)
        {
            min = a_new;
        }
        rng = max - min;
        if (a_new > 0)
        {
            ++cnt;
        }
        a = a_new;
    }

    //Assign values to the returns array
    results[0] = max;
    results[1] = min;
    results[2] = rng;
    results[3] = cnt;
    
    //Return array
    return results;
}
int main(void)
{
    float *r;

    //Outsource the steps to a separate function and return an array
    r = until_first_negative_number();

    printf("We've found a negative number. \n");
    printf("Max: %f\n Min: %f\n Range: %f\n Count %f\n", r[0], r[1], r[2], r[3]);
}
