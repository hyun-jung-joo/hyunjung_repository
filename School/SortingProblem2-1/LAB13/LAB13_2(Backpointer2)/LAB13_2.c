#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define ST 1
#define LE 2
#define UP 3

int matrixPath(int** m, int** M1, int** M2, int** BP, int i, int j)
{
	if (M2[i][j] != 0)
		return M1[i][j];
	if (i == 0 && j == 0) {
		BP[i][j] = ST;
		return m[i][j];
	}
	else if (i == 0) {
		M1[i][j] = matrixPath(m, M1, M2, BP, i, j - 1) + m[i][j];
		BP[i][j] = LE;
	}
	else if (j == 0) {
		M1[i][j] = matrixPath(m, M1, M2, BP, i - 1, j) + m[i][j];
		BP[i][j] = UP;
	}
	else {
		int a, b;
		a = matrixPath(m, M1, M2, BP, i, j - 1);
		b = matrixPath(m, M1, M2, BP, i - 1, j);

		if (a < b) {
			M1[i][j] = a + m[i][j];
			BP[i][j] = LE;
		}
		else {
			M1[i][j] = b + m[i][j];
			BP[i][j] = UP;
		}
	}
	M2[i][j] = 1;
	return M1[i][j];
}

void print_path(int i, int j, int** BP)
{
	if (BP[i][j] == LE)
		print_path(i, j - 1, BP);

	if (BP[i][j] == UP)
		print_path(i - 1, j, BP);

	printf(" <%d %d> ", i, j);
}

int main(void)
{
	int** m;
	int** M1;
	int** M2;
	int** BP;
	int i, j, r, c;
	r = c = 4;

	m = (int**)malloc(sizeof(int*) * r);
	M1 = (int**)malloc(sizeof(int*) * r);
	M2 = (int**)malloc(sizeof(int*) * r);
	BP = (int**)malloc(sizeof(int*) * r);
	for (i = 0; i < r; i++) {
		m[i] = (int*)malloc(sizeof(int) * c);
		M1[i] = (int*)malloc(sizeof(int) * c);
		M2[i] = (int*)malloc(sizeof(int) * c);
		BP[i] = (int*)malloc(sizeof(int) * c);
	}

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++) {
			scanf("%d", &m[i][j]);
			M1[i][j] = 0;
			M2[i][j] = 0;
		}

	printf("%d\n", matrixPath(m, M1, M2, BP, r - 1, c - 1));
	print_path(3, 3, BP);
	printf("\n");

	for (i = 0; i < r; i++) {
		free(m[i]);
		free(M1[i]);
		free(M2[i]);
		free(BP[i]);
	}
	free(m);
	free(M1);
	free(M2);
	free(BP);

	return 0;
}