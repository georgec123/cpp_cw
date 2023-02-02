#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(void)
{
	for (int i = 0; i < 90; i++)
	{
		for (int j = 0; j < 90; j++)
		{
			frac_sleepy(i + 10, j + 10);
		}
	}
	system("pause");
	return EXIT_SUCCESS;
}