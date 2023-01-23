#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct student
{
	int id;
	int korean, english, math;
};

int partition(struct student* arr, int p, int r)
{
	int i, j;
	struct student k;

	i = p - 1;
	j = p;

	for (; j < r; j++) {
		if (arr[j].korean > arr[r].korean) {
			i++;
			k = arr[i];
			arr[i] = arr[j];
			arr[j] = k;
		}
	}

	i++;
	k = arr[i];
	arr[i] = arr[r];
	arr[r] = k;

	return i;
}

void quicksort(struct student* arr, int p, int r)
{
	int q;

	if (p < r) {
		q = partition(arr, p, r);
		quicksort(arr, p, q - 1);
		quicksort(arr, q + 1, r);
	}
}

int main()
{
	int n;
	int i;
	struct student* array;

	scanf("%d", &n);

	array = (struct student*)malloc(sizeof(struct student) * n);

	srand(time(NULL));
	for (i = 0; i < n; i++) {
		array[i].id = i + 1;
		array[i].korean = rand() % 101;
		array[i].english = rand() % 101;
		array[i].math = rand() % 101;
	}

	for (i = 0; i < n; i++) {
		printf("�й� : %d ", array[i].id);
		printf("����� : %d ", array[i].korean);
		printf("����� : %d ", array[i].english);
		printf("���м��� : %d ", array[i].math);
		printf("\n");
	}

	quicksort(array, 0, n - 1);
	printf("\n");
	printf("���ĵ� ��: \n");
	for (i = 0; i < n; i++) {
		printf("�й� : %d ", array[i].id);
		printf("����� : %d ", array[i].korean);
		printf("����� : %d ", array[i].english);
		printf("���м��� : %d ", array[i].math);
		printf("\n");
	}

	free(array);
	return 0;
}