#include <stdio.h>
#include <stdlib.h>

// Define looping functions outsode of main

int loop_a()
{
    int ret_a = 0;
    // Should execute once
    for (int i=10; i<=10; i++){
        ret_a++;
    }

    return ret_a;
}

int loop_b()
{
    int ret_b = 0;
    // Should execute nonce
    for (int i=10; i<10; i++){
        ret_b++;
    }

    return ret_b;
}

int loop_c()
{
    int ret_c = 0;
    // Should execute thrice
    for (int i=10; i>=1; i-=4){
        ret_c++;
    }

    return ret_c;
}

int loop_d()
{
    int ret_d = 0;
    // Should execute once
    for (int i=10; i==10; i-=4){
        ret_d++;
    }

    return ret_d;
}

int main(void)
{  
    //Return and print looping results
   printf("Loop a is executed: %d times \n", loop_a());
   printf("Loop b is executed: %d times \n", loop_b());
   printf("Loop c is executed: %d times \n", loop_c());
   printf("Loop d is executed: %d times \n", loop_d());
}
