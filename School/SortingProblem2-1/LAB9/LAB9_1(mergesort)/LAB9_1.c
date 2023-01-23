#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int* arr, int* t, int p, int q, int r)
{
	int i, j, k;

	i = p; 
	j = q + 1;
	k = p;
	
	while (i <= q && j <= r) {
		if (arr[i] < arr[j]) {
			t[k] = arr[i];
			i++;
		}
		else {
			t[k] = arr[j];
			j++;
		}
		k++;
	}

	if (i > q) {
		for (; j <= r; j++, k++)
			t[k] = arr[j];
	}
	else {
		for (; i <= q; i++, k++)
			t[k] = arr[i];
	}
	for (i = p, k = p; i <= r; i++, k++)
		arr[i] = t[k];
}

void mergesort(int* arr, int* t, int p, int r)
{
	int q;

	if (p < r) {
		q = (p + r) / 2;
		mergesort(arr, t, p, q);
		mergesort(arr, t, q + 1, r);
		merge(arr, t, p, q, r);
	}
}

int main() 
{
	int n;
	int i;
	int* array;
	int* t;

	scanf("%d", &n);

	array = (int*)malloc(sizeof(int) * n);
	t = (int*)malloc(sizeof(int) * n);

	srand(time(NULL));
	for (i = 0; i < n; i++) {
		array[i] = rand() % 100001;
		printf("%6d ", array[i]);
	}
	printf("\n");

	mergesort(array, t, 0, n - 1);

	for (i = 0; i < n; i++)
		printf("%6d ", array[i]);
	printf("\n");

	free(array);
	free(t);
	return 0;
}