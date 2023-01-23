#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(char* item[], int n, int* bucket, int bucketSize, int k)
{
	int lastIndex, i;
	int num = 1;
	int result = 0;
	int index;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++) {
			index = bucket[i];
			printf("%s%d", item[index], num);

			if (index == 0)
				result += num;
			else
				result -= num;
			num++;
		}
		printf(" = %d", result);
		printf("\n");
		return;
	}
	
	lastIndex = bucketSize - k - 1;
	for (i = 0; i < n; i++) {
		bucket[lastIndex + 1] = i;
		pick(item, n, bucket, bucketSize, k - 1);
	}
}

int main()
{
	int n;
	int *picked;
	char* item[] = { "+", "-" };

	scanf("%d", &n);
	picked = (int*)malloc(sizeof(int) * n);

	pick(item, 2, picked, n, n);

	free(picked);
}