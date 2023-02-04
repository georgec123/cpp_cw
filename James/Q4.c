#include <stdio.h>
#include <stdlib.h>

int in_out_shake_it_all_about(int count)
{   
    char ch;
    printf("Input a new character: \n");
    scanf(" %c", &ch);
    ++count;

    if (count == 10) {
        printf("%c \n", ch);
    } else {
        in_out_shake_it_all_about(count);
        printf("%c \n", ch);
    }
    return 0;
}

int main(void)
{
    int count = 0;
    in_out_shake_it_all_about(count);

}
