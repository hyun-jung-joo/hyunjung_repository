#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void readMatrix(int a[][3], int n)
{
	int i, j;

	for (i = 0; i < n; i++)
		for (j = 0; j < 3; j++)
			scanf("%d", &a[i][j]);
}

void matrixAdd(int a[][3], int b[][3], int x[][3], int n)
{
	int i, j;

	for (i = 0; i < n; i++)
		for (j = 0; j < 3; j++)
			x[i][j] = a[i][j] + b[i][j];
}

void printMatrix(int a[][3], int n)
{
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < 3; j++)
			printf("%3d ", a[i][j]);
		printf("\n");
	}
}

int main(void)
{
	int a[3][3], b[3][3], x[3][3];

	printf("<3 x 3> 행렬 A 입력: \n");
	readMatrix(a, 3);
	printf("<3 x 3> 행렬 B 입력: \n");
	readMatrix(b, 3);

	matrixAdd(a, b, x, 3);

	printf("행렬합: \n");
	printMatrix(x, 3);

	return 0;
}