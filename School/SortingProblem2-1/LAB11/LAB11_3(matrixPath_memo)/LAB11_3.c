#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int matrixPath(int** m, int **M,int i, int j)
{
	if (i == 0 && j == 0)
		return m[0][0];
	if (M[i][j] == 0) {
		if (i == 0)
			M[i][j] = matrixPath(m, M, 0, j - 1) + m[i][j];
		else if(j == 0) 
			M[i][j] = matrixPath(m, M, i - 1, 0) + m[i][j];
		else {
			int a, b;

			a = matrixPath(m, M, i - 1, j);
			b = matrixPath(m, M, i, j - 1);

			if (a < b)
				M[i][j] =  a + m[i][j];
			else
				M[i][j] = b + m[i][j];
		}
	}

	return M[i][j];
}

int main(void)
{
	int** m;
	int** M;
	int i, j, r, c;
	r = c = 4;

	m = (int**)malloc(sizeof(int*) * r);
	M = (int**)malloc(sizeof(int*) * r);
	for (i = 0; i < r; i++) {
		m[i] = (int*)malloc(sizeof(int) * c);
		M[i] = (int*)malloc(sizeof(int) * c);
	}

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++) {
			scanf("%d", &m[i][j]);
			M[i][j] = 0;
		}

	printf("%d\n", matrixPath(m, M, r - 1, c - 1));

	for (i = 0; i < r; i++) {
		free(m[i]);
		free(M[i]);
	}
	free(m);
	free(M);
	return 0;
}