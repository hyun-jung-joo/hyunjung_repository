#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble(int* nums, int n)
{
	int i, j;
	int temp;

	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++)
			if (nums[j] > nums[j + 1]) {
				temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}	
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

	bubble(nums, n);

	printf("���ĵ� ��: \n");
	for (i = 0; i < n; i++)
		printf("%d ", nums[i]);
	printf("\n");

	free(nums);
}