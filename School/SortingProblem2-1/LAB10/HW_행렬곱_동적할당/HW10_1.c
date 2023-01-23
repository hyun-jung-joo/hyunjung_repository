#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void readMatrix(int** a, int r, int c)
{
	int i, j;

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			scanf("%d", &a[i][j]);
}

void matrixMul(int** a, int** b, int** x, int r, int c, int m)
{
	int i, j, k;

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++) {
			x[i][j] = 0;
			for (k = 0; k < m; k++)
				x[i][j] += a[i][j] * b[i][j];
		}

}

void matrixChange(int** a, int **x, int r, int c)
{
	int i, j;

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			x[j][i] = a[i][j];
}

void printMatrix(int** a, int r, int c)
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
	int** a, ** c, ** x, **ax;
	int arow, acol;
	int crow, ccol;
	int i;

	printf("Enter ��� a�� ��� ���� ����: ");
	scanf("%d %d", &arow, &acol);

	printf("Enter ��� a�� ��� ���� ����<c�� ���� %d�̾��>: ", acol);
	scanf("%d %d", &crow, &ccol);

	a = (int**)malloc(sizeof(int*) * arow);
	c = (int**)malloc(sizeof(int*) * crow);
	x = (int**)malloc(sizeof(int*) * arow);
	ax = (int**)malloc(sizeof(int*) * acol);

	for (i = 0; i < arow; i++) {
		a[i] = (int*)malloc(sizeof(int) * acol);
		x[i] = (int*)malloc(sizeof(int) * ccol);
	}

	for (i = 0; i < crow; i++) {
		c[i] = (int*)malloc(sizeof(int) * ccol);
		ax[i] = (int*)malloc(sizeof(int) * arow);
	}


	printf("<%d x %d> ��� A �Է�: \n", arow, acol);
	readMatrix(a, arow, acol);
	printf("\n");
	printf("<%d x %d> ��� C �Է�: \n", crow, ccol);
	readMatrix(c, crow, ccol);
	printf("\n");

	matrixMul(a, c, x, arow, ccol, acol);
	printf("��İ�: \n");
	printMatrix(x, arow, ccol);
	printf("\n");


	matrixChange(a, ax, arow, acol);
	printf("��ġ���: \n");
	printMatrix(ax, acol, arow);
	printf("\n");

	for (i = 0; i < arow; i++) {
		free(a[i]);
		free(x[i]);
	}

	for (i = 0; i < crow; i++)
		free(c[i]);

	free(a);
	free(c);
	free(x);

	return 0;
}