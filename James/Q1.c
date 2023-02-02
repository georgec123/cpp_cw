#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char a, b;
    printf("Input two characters");
    scanf("%c %c", &a, &b);

    printf("Here, take them back, I dont want them: %c %c", b, a);

}

