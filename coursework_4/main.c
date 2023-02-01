#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define numiter 5

void recursive_function(int n)
{
	float value;
	
	if (n == 1)
	{
		printf("Input the %d-th value.\n", numiter - n + 1);
		scanf("%f", &value);
		printf("The %d-th value is: %f.\n", numiter - n + 1, value);
	}
	else
	{
		printf("Input the %d-th value.\n", numiter - n + 1);
		scanf("%f", &value);
		recursive_function(n - 1);
		printf("The %d-th value is: %f.\n", numiter - n + 1, value);
	}
}

int main(void)
{
	recursive_function(numiter);

	return EXIT_SUCCESS;
}