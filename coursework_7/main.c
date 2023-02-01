#define _CRT_SECURE_NO_WARNINGS

/*For whoever is peer reviewing the code, everything can be done esentially with one big function that locally creates the list*/
/*It just feels sad*/

#include <stdio.h>
#include <stdlib.h>

/*This function generates a series up to n of all integers*/
void series_generator(int n, int* series)
{
	int i;
	for (i = 2; i <=n; i++)
	{
		*(series + i - 2) = 1;
	}
}

void series_printer(int n, int *series)
{
	int i;
	for (i = 2; i <= n; i++)
		if(*(series + i - 2) == 1)
			/*It prints only the non zero values*/
			/*It is important to note that here the list acts
			as a list of boolean elements, indicating the veracity of prime/not prime*/
			printf("%d ", i);
}

void eratosthenes(int n, int* series)
{
	int i, j;
	for (i = 2; i * i <= n; i++) 
	//To avoid needing the Sqrt function we simply make the condition i^2 <= n (including as stated by the question)
	{
		if (*(series + i -2) == 1)
		//If prime we make all its multiples not prime in the list by 1 -> 0. This is assured by the j = j+i step size.
		//Additionally we can start in i*i because all the previous elements have to be multiple of a
		//previous prime and hence have already been converted to 0.
		{
			for (j = i * i; j <= n; j += i)
			{
				*(series + j -2) = 0;
			}
		}
	}
}

void optimised_Eratostenes(int n)
{	
	int diff = n-3;

	int values = 1+(diff + (diff % 2))/2;
	// (n + (n % 2)) / 2;
	int* a = (int*)calloc((values-1), sizeof(int));
	int i, j;
	for (i = 3; i * i <= n; i++)
		//To avoid needing the Sqrt function we simply make the condition i^2 <= n (including as stated by the question)
	{
		if (*(a + i - 3) == 0)
			//If prime we make all its multiples not prime in the list by 1 -> 0. This is assured by the j = j+i step size.
			//Additionally we can start in i*i because all the previous elements have to be multiple of a
			//previous prime and hence have already been converted to 0.
		{
			// printf("->%d\n", (i));
			for (j = i * i; j <= n; j += i)
			{
				if (j % 2 == 1)
					*(a + (j - 3)/2) = 1;

				// printf("%d\n", j);
			}
		}
	}
	if (n >= 2)
		printf("2 ");

	for (i = 0; i <= values; i++)
		if (*(a + i) == 0)
			/*It prints only the non zero values*/
			/*It is important to note that here the list acts
			as a list of boolean elements, indicating the veracity of prime/not prime*/
			printf("%d ", i * 2 + 3);

}

int main(void)
{
	int N;

	printf("Input an integer number to use the Eratostenes sieve up to that value.\n");
	scanf("%d", &N);
	
	printf("Normal Sieve\n");
	
	int* a = (int*)malloc((N - 1) * sizeof(int));
	series_generator(N, a);
	printf("The original series is:\n");
	series_printer(N, a);
	printf("\n");
	eratosthenes(N, a);
	printf("The prime numbers less or equal than %d are:\n", N);
	series_printer(N, a);
	free(a);

	printf("\nOptimised Sieve\n");
	optimised_Eratostenes(N);


	return EXIT_SUCCESS;
}