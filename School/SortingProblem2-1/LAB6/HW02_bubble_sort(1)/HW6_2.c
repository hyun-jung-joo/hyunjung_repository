#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Student
{
	int id;
	int korean, english, math;
};

void bubble (struct Student* nums, int n, int count)
{
	int i, j;
	int temp;

	switch (count) {
		case 1 :
			for (i = 0; i < n - 1; i++) {
				for (j = 0; j < n - i - 1; j++)
					if (nums[j].korean < nums[j + 1].korean) {
						temp = nums[j].korean;
						nums[j].korean = nums[j + 1].korean;
						nums[j + 1].korean = temp;
					}
			}
			break;
		case 2:
			for (i = 0; i < n - 1; i++) {
				for (j = 0; j < n - i - 1; j++)
					if (nums[j].math < nums[j + 1].math) {
						temp = nums[j].math;
						nums[j].math = nums[j + 1].math;
						nums[j + 1].math = temp;
					}
			}
			break;
		case 3:
			for (i = 0; i < n - 1; i++) {
				for (j = 0; j < n - i - 1; j++)
					if (nums[j].english < nums[j + 1].english) {
						temp = nums[j].english;
						nums[j].english = nums[j + 1].english;
						nums[j + 1].english = temp;
					}
			}
			break;
		case 4:
			for (i = 0; i < n - 1; i++) {
				for (j = 0; j > n - i - 1; j++)
					if (nums[j].id < nums[j + 1].id) {
						temp = nums[j].id;
						nums[j].id = nums[j + 1].id;
						nums[j + 1].id = temp;
					}
			}
			break;
	}

}

int main(void)
{
	int n, i;
	int id = 1;
	struct Student* nums;
	int count;

	printf("�л� ���� �Է��ϼ��� : ");
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
		printf("�й� : %d ", nums[i].id);
		printf("����� : %d ", nums[i].korean);
		printf("����� : %d ", nums[i].english);
		printf("���м��� : %d ", nums[i].math);
		printf("\n");
	}

	printf("\n���� ���� ����<1:����, 2:����, 3:����, 4:id<��������>, 0:������> :");
	scanf("%d", &count);
	while (count != 0) {
		bubble(nums, n, count);
		for (i = 0; i < n; i++) {
			printf("�й� : %d ", nums[i].id);
			printf("����� : %d ", nums[i].korean);
			printf("����� : %d ", nums[i].english);
			printf("���м��� : %d ", nums[i].math);
			printf("\n");
		}
		printf("\n���� ���� ����<1:����, 2:����, 3:����, 4:id<��������>, 0:������> :");
		scanf("%d", &count);
	}

	free(nums);
}