#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int n, i;
	int* nums;

	scanf("%d", &n);

	nums = (int*)malloc(sizeof(int) * n);

	srand(time(NULL));

	for (i = 0; i < n; i++)
		nums[i] = rand() % 1000;
	for (i = 0; i < n; i++)
		printf("%d ", nums[i]);
	printf("\n");

	free(nums);
}