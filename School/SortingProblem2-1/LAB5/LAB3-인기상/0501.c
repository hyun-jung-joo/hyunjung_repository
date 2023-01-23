#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(char *item[], int n, int* picked, int m, int toPick)
{
	int i;
	int lastIndex, smallest;
	int index;

	if (toPick == 0) {
		for (i = 0; i < m; i++) {
			index = picked[i];
			printf("%s ", item[index]);
		}
		printf("\n");
		return;
	}

	lastIndex = m - toPick - 1;

	if (m == toPick)
		smallest = 0;
	else
		smallest = picked[lastIndex] + 1;

	for (i = smallest; i < n; i++) {
		picked[lastIndex + 1] = i;
		pick(item, n, picked, m, toPick - 1);
	}
}

int main(void)
{
	int num;
	int* picked;
	char *item[] = {"공유", "김수현", "송중기", "지성", "현빈"};
	printf("인기상 몇명? ");
	scanf("%d", &num);
	
	picked = (int*)malloc(sizeof(int) * num);
	pick(item, 5, picked, num, num);

	free(picked);
}