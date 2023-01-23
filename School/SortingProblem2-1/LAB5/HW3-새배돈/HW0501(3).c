#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int total, int items[], int n, int* bucket, int bucketSize, int k)
{
	int smallest, lastIndex, i, item;
	int index;
	int result = 0;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++) {
			index = bucket[i];
			result += items[index];
		}

		if (result == total) {
			for (i = 0; i < bucketSize; i++) {
				index = bucket[i];
				if (items[index] == 0)
					printf("");
				else
					printf("%d ", items[index]);
			}
			if(i == bucketSize)
				printf("\n");
		}
		return;
	}

	lastIndex = bucketSize - k - 1;
	if (bucketSize == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex];

	for (item = smallest; item < n; item++) {
		bucket[lastIndex + 1] = item;
		pick(total, items, n, bucket, bucketSize, k - 1);
	}
}

int main()
{
	int items[4] = { 0, 1000, 5000, 10000 };
	int money;
	int n;
	int* bucket;
	scanf("%d", &money);

	n = money / 1000;
	bucket = (int*)malloc(sizeof(int) * n);

	pick(money, items, 4, bucket, n, n);
}