#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int matrixPath(int** m, int i, int j) 
{
	if (i == 0 && j == 0)
		return m[0][0];
	else if (i == 0)
		return matrixPath(m, 0, j - 1) + m[i][j];
	else if(j == 0)
		return matrixPath(m, i - 1, 0) + m[i][j];
	else {
		int a, b;
		
		a = matrixPath(m, i - 1, j);
		b = matrixPath(m, i, j - 1);

		if (a < b)
			return a + m[i][j];
		else
			return b + m[i][j];
	}
}

int main(void)
{
	int** m;
	int i, j, r, c;
	r = c = 4;

	m = (int**)malloc(sizeof(int*) * r);
	for (i = 0; i < r; i++)
		m[i] = (int*)malloc(sizeof(int) * c);

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			scanf("%d", &m[i][j]);

	printf("%d\n", matrixPath(m, r - 1, c - 1));

	for (i = 0; i < r; i++)
		free(m[i]);
	free(m);

	return 0;
}