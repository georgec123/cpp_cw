#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void until_first_negative_number(void)
{
    //Define initial variable
    float a;
    
    //Input first value and check if positive. If negative, do not enter the loop.
    printf("Please input your first value, negative value to exit: \n");
    scanf("%f", &a);
    
    if (a < 0)
    {
        /*Exit function*/
        printf("Exit without any inputs.\n");
        return;
    }
    
    /*We initialise to the only value that we have so far*/
    float min = a, max = a;
    float rng = 0;
    int cnt = 0;

    while (a >= 0)
    {
        cnt++;
        //Loop until first negative value is inputted. Only count values up until this point when finding max, min, rng and cnt
        /*In the first pass through the loop none of the conditions are verified, but we need the input of a new variable
           to go at the end, to be checked before reentering the loop.*/
        if (a > max)
        {
            max = a;
        }
        else if (a < min)
        {
            min = a;
        }
        rng = max - min;  
        
        
        printf("Please input a new value, negative value to exit: \n");
        scanf("%f", &a);    
    }

    printf("\n->Negative number found. \n");
    printf("Maximum: %f\nMinimum: %f\nRange: %f\nNumber of non-negative values inserted: %d\n", max, min, rng, cnt);
}
int main(void)
{
    until_first_negative_number();
    return EXIT_SUCCESS;
}
