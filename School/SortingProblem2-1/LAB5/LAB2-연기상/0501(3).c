#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(char* item[], int n, int* picked, int m, int toPick)
{
	int i, j;
	int lastIndex;
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

	for (i = 0; i < n; i++) {
		int flag = 0;

		for (j = 0; j <= lastIndex; j++)
			if (picked[j] == i)
				flag = 1;
		if (flag == 1)
			continue;

		picked[lastIndex + 1] = i;
		pick(item, n, picked, m, toPick - 1);
	}
}

int main(void)
{
	int num;
	int* picked;
	char* item[] = { "공유", "김수현", "송중기", "지성", "현빈" };
	
	printf("상의 종류는? ");
	scanf("%d", &num);
	picked = (int*)malloc(sizeof(int) * num);
	
	printf("   상1    상2\n");
	pick(item, 5, picked, num, num);

	free(picked);
}