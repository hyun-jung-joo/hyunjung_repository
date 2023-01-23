#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion(int* nums, int n)
{
	int i, j, k;
	int temp;

	for (i = 0; i < n; i++) {
		for (j = 0; j < i; j++)
			if (nums[i] < nums[j])
				break;

		temp = nums[i];

		for (k = i; k > j; k--)
			nums[k] = nums[k - 1];
		nums[k] = temp;
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

	insertion(nums, n);

	printf("정렬된 후: \n");
	for (i = 0; i < n; i++)
		printf("%d ", nums[i]);
	printf("\n");

	free(nums);
}