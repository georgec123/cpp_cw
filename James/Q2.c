#include <stdio.h>
#include <stdlib.h>

int main(void)
{   
    // Should execute once
    //for (int i=10; i<=10; i++){
    //    printf("Here we go again\n");
    //}

    // Should execute nonce
    //for (int i=10; i<10; i++){
    //    printf("Here we go again\n");
    //}

    // Should execute thrice
    //for (int i=10; i>=1; i-=4){
    //    printf("Here we go again\n");
    //}

    // Should execute once
    for (int i=10; i==10; i-=4){
        printf("Here we go again\n");
    }
}
