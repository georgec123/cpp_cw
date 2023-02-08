#include "header.h"

/*This function generates writtes 1 in all elements of an array of lenght n*/
/*We will use this as a Boolean condition of prime not prime*/
void series_generator(int n, int* series)
{
	int i;
	for (i = 2; i <= n; i++)
	{
		*(series + i - 2) = 1;
	}
}

void series_printer(int n, int* series)
{
	/*It prints only the non zero values*/
	/*It is important to note that here the list acts as a list of boolean elements, indicating the veracity of prime/not prime*/
	/*The reason why starts in 2 is that it is the first possible prime,
		then we add the -2 in *(series + i - 2) because array indecing starts at 0*/
	int i;
	for (i = 2; i <= n; i++)
		if (*(series + i - 2) == 1)
			printf("%d ", i);
}

void eratosthenes(int n, int* series)
{
	int i, j;
	for (i = 2; i * i <= n; i++)
		/*To avoid needing the Sqrt function we simply make the condition i^2 <= n (including as stated by the question)*/
	{
		if (*(series + i - 2) == 1)
			/*If prime we make all its multiples not prime in the list by changing the value in the array 1 -> 0. This is assured by the j = j+i step size.*/
			/*Additionally we can start in i*i because all the previous elements have to be multiple of a
				previous prime and hence have already been converted to 0.*/
		{
			for (j = i * i; j <= n; j += i)
			{
				*(series + j - 2) = 0;
			}
		}
	}
}

void optimised_eratostenes(int n)
{
	/* Make an array representing all the odd numbers bigger than 2*/
	/*There is a great change compared with the non optimised version*/
	/*calloc initialises to 0, and we have changed for simplicity the conditions to:
		prime represented by 0,
		not prime represented by 1.
	*/

	int diff = n - 3;
	int values = 1 + (diff + (diff % 2)) / 2;
	int* a = (int*)calloc((values - 1), sizeof(int));
	int i, j;

	for (i = 3; i * i <= n; i += 2)
		/*To avoid using the Sqrt function we simply make the condition i^2 <= n (including as stated by the question)*/
	{
		if (*(a + (i - 3) / 2) == 0)
			/*If prime we make all its multiples not prime in the list by 1 -> 0. This is assured by the j = j+i step size.*/
		{
			for (j = i * i; j <= n; j += 2 * i)
			{
				if (j % 2 == 1)
					/* 1 means not prime*/
					*(a + (j - 3) / 2) = 1;
				else
					/* 0 means prime*/
					*(a + (j - 3) / 2) = 0;


			}
		}
	}
	if (n >= 2)
		printf("2 ");

	for (i = 3; i <= n; i += 2)
		if (*(a + (i - 3) / 2) != 1)
			/*It prints only the zero values*/
			/*The list acts as a list of boolean elements, indicating the veracity of prime/not prime*/
			printf("%d ", i);
	printf("\n");
}
