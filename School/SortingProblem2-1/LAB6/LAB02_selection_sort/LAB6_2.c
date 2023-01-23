#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection(int* nums, int n)
{
	int i, j;
	int temp;

	for (i = 0; i < n - 1; i++) {
		int max = 0;

		for (j = 0; j < n - i; j++)
			if (nums[max] < nums[j])
				max = j;

		temp = nums[max];
		nums[max] = nums[n - i - 1];
		nums[n - i - 1] = temp;
	}
}

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

	selection(nums, n);
	
	printf("정렬된 후: \n");
	for (i = 0; i < n; i++)
		printf("%d ", nums[i]);
	printf("\n");

	free(nums);
}