#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define numiter 200

char* suffix_for_number(int number) {
	int last_digit = number % 10;
	switch (last_digit) {
	case 1:
		return "st";
	case 2:
		return "nd";
	case 3:
		return "rd";
	default:
		return "th";
	}
}


float input_digit()
{
	float n;
	while (scanf("%f", &n) != 1)
	{
		printf("Please enter a number: ");
		while (getchar() != '\n');
	}
	return n;
}

void reverse_number_print( int n)
{

	float value;
	char* suffix = suffix_for_number(numiter - n + 1);

	printf("Input the %d%s value.\n", numiter - n + 1, suffix);
	value = input_digit();

	if (n != 1)
	{
		reverse_number_print(n - 1);
	}

	printf("The %d%s value is: %f.\n", numiter - n + 1, suffix, value);

}
