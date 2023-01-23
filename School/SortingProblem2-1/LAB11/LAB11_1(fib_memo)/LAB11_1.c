#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
long fib(int n, long* F)
{
	if (n == 1 || n == 2) {
		return 1;
	}

	if (F[n] != 0)
		return F[n];
	else {
		F[n] = fib(n - 1, F) + fib(n - 2, F);
		return F[n];
	}
}

int main(void)
{
	int i, n;
	long* F;

	printf("몇 번째까지의 피보나치 수열:");
	scanf("%d", &n);

	F = (long*)malloc(sizeof(long) * (n + 1));
	for (i = 0; i < n + 1; i++)
		F[i] = 0;
	
	for (i = 1; i < n + 1; i++)
		printf("%2ld ", fib(i, F));

	return 0;
	free(F);
}