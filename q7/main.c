#include "header.h"

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
	optimised_eratostenes(N);
	system("pause");

	return EXIT_SUCCESS;
}
