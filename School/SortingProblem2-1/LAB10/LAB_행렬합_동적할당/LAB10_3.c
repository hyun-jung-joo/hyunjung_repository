#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void readMatrix(int **a, int r, int c)
{
	int i, j;

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			scanf("%d", &a[i][j]);
}

void matrixAdd(int **a, int **b, int **x, int r, int c)
{
	int i, j;

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			x[i][j] = a[i][j] + b[i][j];
}

void printMatrix(int **a, int r, int c)
{
	int i, j;

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
			printf("%3d ", a[i][j]);
		printf("\n");
	}
}

int main(void)
{
	int** a, ** b, ** x;
	int r, c;
	int i;

	printf("Enter 행렬 a의 행과 열의 개수: ");
	scanf("%d %d", &r, &c);

	a = (int**)malloc(sizeof(int*) * r);
	b = (int**)malloc(sizeof(int*) * r);
	x = (int**)malloc(sizeof(int*) * r);

	for (i = 0; i < r; i++) {
		a[i] = (int*)malloc(sizeof(int) * c);
		b[i] = (int*)malloc(sizeof(int) * c);
		x[i] = (int*)malloc(sizeof(int) * c);
	}

	printf("<%d x %d> 행렬 A 입력: \n", r, c);
	readMatrix(a, r, c);
	printf("<%d x %d> 행렬 B 입력: \n", r, c);
	readMatrix(b, r, c);

	matrixAdd(a, b, x, r, c);

	printf("행렬합: \n");
	printMatrix(x, r, c);

	for (i = 0; i < r; i++) {
		free(a[i]);
		free(b[i]);
		free(x[i]);
	}

	free(a);
	free(b);
	free(x);

	return 0;
}