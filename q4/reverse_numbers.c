#include "header.h"
/*This file contains the functions required for the solution of Q4*/

/*This function is only used to make sure that the ordinal numbers have the right suffix*/
/*It returns a chain of characters*/
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

/*Function to take an input verifying that it is a number.*/
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

/*Recursive function keeps track of the values we have written, using recursion. Parameter is the number of values to take*/
void reverse_number_print( int n)
{

	float value;
	char* suffix = suffix_for_number(numiter - n + 1);
	
	printf("Input the %d%s value.\n", numiter - n + 1, suffix);
	value = input_digit();

	/*If after the last value has been inserted we stop recursion*/
	if (n != 1)
	{
		reverse_number_print(n - 1);
	}

	printf("The %d%s value is: %f.\n", numiter - n + 1, suffix, value);

}
