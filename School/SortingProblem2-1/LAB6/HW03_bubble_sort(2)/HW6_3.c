#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble(int* nums, int n)
{
	int *new_nums;
	int i, j, k, p;
	int temp;

	new_nums = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n - 1; i++) {
		for (p = 0; p < n; p++)
			new_nums[p] = nums[p];
		for (j = 0; j < n - i - 1; j++)
			if (nums[j] > nums[j + 1]) {
				temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}

		for (p = 0; p < n; p++)
			if (new_nums[p] != nums[p])
				break;

		if (p != n) {
			printf("i = %d:  ", i);
			for (k = 0; k < n; k++)
				printf("%d  ", nums[k]);
			printf("\n");
		}

		else
			break;
	}

	free(new_nums);
}

int main(void)
{
	int n, i;
	int* nums;

	printf("Enter a number : ");
	scanf("%d", &n);

	nums = (int*)malloc(sizeof(int) * n);

	//srand(time(NULL));

	for (i = 0; i < n; i++)
		nums[i] = rand() % 100;
	printf("초기 :  ");
	for (i = 0; i < n; i++)
		printf("%d  ", nums[i]);
	printf("\n");

	bubble(nums, n);

	printf("정렬 :  ");
	for (i = 0; i < n; i++)
		printf("%d  ", nums[i]);
	printf("\n");

	free(nums);
}