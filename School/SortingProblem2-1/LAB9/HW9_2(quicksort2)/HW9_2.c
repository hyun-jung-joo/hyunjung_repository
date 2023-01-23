#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct student
{
	int id;
	int korean, english, math;
};

int partition(struct student* arr, int p, int r, int count)
{
	int i, j;
	struct student k;

	i = p - 1;
	j = p;

	for (; j < r; j++) {
		if ((count == 1 && arr[j].korean > arr[r].korean) ||
			(count == 2 && arr[j].english > arr[r].english) ||
			(count == 3 && arr[j].math > arr[r].math) ||
			(count == 4 && arr[j].id < arr[r].id)) 
		{
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

void quicksort(struct student* arr, int p, int r, int count)
{
	int q;

	if (p < r) {
		q = partition(arr, p, r, count);
		quicksort(arr, p, q - 1, count);
		quicksort(arr, q + 1, r, count);
	}
}

int main()
{
	int n;
	int i;
	int count;
	struct student* array;

	printf("�л� ���� �Է��ϼ��� : ");
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
	printf("\n���� ���� ����<1:����, 2:����, 3:����, 4:id<��������>, 0:������> :");
	scanf("%d", &count);
	while (count != 0) {
		quicksort(array, 0, n - 1, count);
		for (i = 0; i < n; i++) {
			printf("�й� : %d ", array[i].id);
			printf("����� : %d ", array[i].korean);
			printf("����� : %d ", array[i].english);
			printf("���м��� : %d ", array[i].math);
			printf("\n");
		}
		printf("\n���� ���� ����<1:����, 2:����, 3:����, 4:id<��������>, 0:������> :");
		scanf("%d", &count);
	}

	free(array);
	return 0;
}