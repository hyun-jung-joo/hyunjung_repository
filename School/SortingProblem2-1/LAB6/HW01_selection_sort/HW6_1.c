#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Student
{
	int id;
	int korean, english, math;
};

void selection(struct Student *nums, int n)
{
	int i, j;
	int temp;

	for (i = 0; i < n - 1; i++) {
		int max = 0;

		for (j = 0; j < n - i; j++)
			if (nums[max].korean > nums[j].korean)
				max = j;

		temp = nums[max].korean;
		nums[max].korean = nums[n - i - 1].korean;
		nums[n - i - 1].korean = temp;
	}
}

int main(void)
{
	int n, i;
	int id = 1;
	struct Student *nums;

	scanf("%d", &n);

	nums = (int*)malloc(sizeof(int) * n);

	srand(time(NULL));

	for (i = 0; i < n; i++) {
		nums[i].id = id;
		nums[i].korean = rand() % 101;
		nums[i].english = rand() % 101;
		nums[i].math = rand() % 101;
		id++;
	}

	for (i = 0; i < n; i++) {
		printf("학번 : %d ", nums[i].id);
		printf("국어성적 : %d ", nums[i].korean);
		printf("영어성적 : %d ", nums[i].english); 
		printf("수학성적 : %d ", nums[i].math);
		printf("\n");
	}
	
	selection(nums, n);
	printf("\n");
	printf("정렬된 후: \n");
	for (i = 0; i < n; i++) {
		printf("학번 : %d ", nums[i].id);
		printf("국어성적 : %d ", nums[i].korean);
		printf("영어성적 : %d ", nums[i].english);
		printf("수학성적 : %d ", nums[i].math);
		printf("\n");
	}
	printf("\n");

	free(nums);
}