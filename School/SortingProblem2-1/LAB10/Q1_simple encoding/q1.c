#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int num;
	int* array;
	int i, j;
	int max = -1;

	printf("�迭 ���� : ");
	scanf("%d", &num);
	array = (int*)malloc(sizeof(int) * num);
	
	printf("�迭 �Է� : ");
	for (i = 0; i < num; i++)
		scanf("%d", &array[i]);

	for (i = 0; i < num; i++) {
		int total = 1;
		array[i] += 1;
		for (j = 0; j < num; j++) {
			total *= array[j];
		}
		if (max < total)
			max = total;
		array[i] -= 1;
	}

	
	printf("��� �� �ִ밪 : %d", max);

	free(array);
	return 0;
}