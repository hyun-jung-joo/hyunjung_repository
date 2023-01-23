#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int comb(int **C, int n, int r)
{
	if (r == n || r == 0)
		C[n][r] = 1;
	else {
		if (C[n - 1][r - 1] == 0)
			C[n - 1][r - 1] = comb(C, n - 1, r - 1);

		if (C[n - 1][r] == 0)
			C[n - 1][r] = comb(C, n - 1, r);

		C[n][r] = C[n - 1][r - 1] + C[n - 1][r];
	}

	return C[n][r];
}

int main(void)
{
	int** C;
	int a, b;
	int i, j;

	scanf("%d %d", &a, &b);

	C = (int**)malloc(sizeof(int*) * (a + 1));
	for (i = 0; i < a + 1; i++)
		C[i] = (int*)malloc(sizeof(int) * (b + 1));

	for (i = 0; i < a + 1; i++)
		for (j = 0; j < b + 1; j++)
			C[i][j] = 0;

	printf("%d\n", comb(C, a, b));

	for (i = 0; i < a - 1; i++)
		free(C[i]);
	free(C);
	return 0;
}