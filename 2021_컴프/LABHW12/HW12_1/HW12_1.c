#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void)
{
	FILE* fp1, * fp2;
	int num;
	int i, sum = 0;

	fp1 = fopen("random.txt", "wt");
	if (fp1 == NULL)
	{
		printf("파일 오픈 에러입니다!!!\n");
		return 1;
	}

	fp2 = fopen("output.txt", "wt");
	if (fp2 == NULL)
	{
		printf("파일 오픈 에러입니다!!!\n");
		return 1;
	}

	srand(time(NULL));
	for (i = 0; i < 10; i++) {
		num = rand() % 100;
		fprintf(fp1, "%d\n", num);
		fprintf(fp2, "%d\n", num);
		printf("\t%d", num);
		sum += num;
	}
	printf("\n합은 %d\n", sum);
	fprintf(fp2, "합은 %d\n", sum);

	fclose(fp1);
	fclose(fp2);
}