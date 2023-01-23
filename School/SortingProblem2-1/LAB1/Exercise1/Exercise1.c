#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int n;
	long result = 1;

	printf("Enter a number:");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		result *= 2;

	printf("%d\n", result);
}