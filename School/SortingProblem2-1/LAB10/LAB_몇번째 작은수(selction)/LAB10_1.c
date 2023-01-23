#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int* A, int p, int r)
{
	int i = p - 1;
	int j, temp;

	for (j = p; j < r; j++) {
		if (A[j] < A[r]) {
			i++;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}

	i++;
	temp = A[i];
	A[i] = A[j];
	A[j] = temp;

	return i;
}

int selection(int* A, int p, int r, int n)
{
	int q;
	int pivot;

	q = partition(A, p, r);
	pivot = q - p + 1;

	if (n == pivot)
		return A[q];
	else if (n > pivot)
		return selection(A, q + 1, r, n - pivot);
	else
		return selection(A, p, q - 1, n);
}

int main(void)
{
	int* A;
	int n, r;
	int i;

	srand(time(NULL));

	printf("Enter the number of numbers : ");
	scanf("%d", &n);

	printf("몇번째로 작은 수: ");
	scanf("%d", &r);
	A = (int*)malloc(sizeof(int) * n);
	
	for (i = 0; i < n; i++)
		A[i] = rand() % 1000;
	for (i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");

	printf("%d번째 작은수는 %d\n", r, selection(A, 0, n - 1, r));

	free(A);
	return 0;
}

