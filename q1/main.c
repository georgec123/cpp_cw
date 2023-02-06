#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char a, b;
	printf("Input to characters: \n");
	scanf("%c %c", &a, &b);
	printf("Your characters in reverse order are: %c\t%c\n", b, a);

	return EXIT_SUCCESS;
}
