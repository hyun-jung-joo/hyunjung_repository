#include <stdio.h>
int isPrime(int x)
{
	int i;

	for (i = 2; i < x; i++)
		if (x % i == 0)
			return 0;
	return 1;
}

int main(void)
{
	int num;

	for (num = 2; num <= 30; num++)
		if (isPrime(num) == 1)
			printf("%d ", num);
	printf("\n");
}