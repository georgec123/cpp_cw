#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float n, max, min;
	int i = 1;
	printf("Input a number, negative to end:\n");
	scanf("%f", &n);
	max = min = n;
	
	while (n >= 0)
	{
		printf("Input a number, negative to end:\n");
		scanf("%f", &n);
		
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
	printf("The range is: %f.", max - min);

	return EXIT_SUCCESS;
}