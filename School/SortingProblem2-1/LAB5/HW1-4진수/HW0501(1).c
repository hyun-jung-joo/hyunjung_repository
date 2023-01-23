#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int n, int* bucket, int bucketSize, int k)
{
    int smallest = 0;
    int lastIndex, i, item;
    if (k == 0) {
        for (i = 0; i < bucketSize; i++)
            printf("%d", bucket[i]);
        printf("\n");
        return;
    }

    lastIndex = bucketSize - k - 1;
    for (item = smallest; item < n; item++) {
        bucket[lastIndex + 1] = item;
        pick(n, bucket, bucketSize, k - 1);
    }
}

int main()
{
    int n = 4;
    int* bucket;
    int num;

    scanf("%d", &num);
    bucket = (int*)malloc(sizeof(int) * num);

    pick(n, bucket, num, num);

    free(bucket);
}