#include <stdio.h>
#include <stdlib.h>
#include "header.h" 

void print_frac(int num, int den)
{
	printf("%d/%d ", num, den);
}

int check_frac(int num, int dom, int num_a, int num_b, int den_a, int den_b)
{
	if (num_a == den_a & num*den_b == dom*num_b & dom*num_b!=0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int frac_sleepy(int numerator, int denominator)
{
	int num_quot = numerator / 10;
	int num_div = numerator % 10;
	int den_quot = denominator / 10;
	int den_div = denominator % 10;

	int combs[4][4] = {{num_quot, num_div, den_quot, den_div},
					   {num_quot, num_div, den_div, den_quot},
					   {num_div, num_quot, den_quot, den_div},
					   {num_div, num_quot, den_div, den_quot}};

	for (int i = 0; i < 4; i++)
	{
		if (check_frac(numerator, denominator, combs[i][0], combs[i][1], combs[i][2], combs[i][3]))
		{
			print_frac(numerator, denominator);
			print_frac(combs[i][1], combs[i][3]);
			printf("\n");
			return 1;
		}
	}
	return 0;
}