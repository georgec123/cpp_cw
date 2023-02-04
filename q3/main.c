#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

float input_digit()
{

	float n;
	printf("Input a number, negative to end:\n");
	while (scanf("%f", &n) != 1)
	{
		printf("Please enter a number: ");
		while (getchar() != '\n');
	}
	return n;
}

int main(void)
{
	float n, max, min;
	int i = 1;
	n = input_digit();
	max = min = n;

	while (n >= 0)
	{
		n = input_digit();

		i++;

		if (max < n)
		{
			max = n;
		}
		if (min > n)
		{
			min = n;
		}
	}
	printf("The number of values read is: %d.", i);
	printf("The maximum value is: %f.", max);
	printf("The minimum value is: %f.", min);
	printf("The range is: %f.\n", max - min);

	system("pause");

	return EXIT_SUCCESS;
}