#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition (int* arr, int p, int r)
{
	int i, j, k;

	i = p - 1;
	j = p;

	for (; j < r; j++) {
		if (arr[j] < arr[r]) {
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

void quicksort(int* arr, int p, int r)
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
	int* array;

	scanf("%d", &n);

	array = (int*)malloc(sizeof(int) * n);

	srand(time(NULL));
	for (i = 0; i < n; i++) {
		array[i] = rand() % 100001;
		printf("%6d ", array[i]);
	}
	printf("\n");

	quicksort(array, 0, n - 1);

	for (i = 0; i < n; i++)
		printf("%6d ", array[i]);
	printf("\n");

	free(array);
	return 0;
}