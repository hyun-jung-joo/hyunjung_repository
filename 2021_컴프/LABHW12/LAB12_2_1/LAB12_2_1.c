#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	//int state;
	FILE* fp;
	FILE* fp2;
	char ch;

	fp = fopen("hello.txt", "wt");
	if (fp == NULL)
	{
		printf("file open error!\n");
		return 1;
	}

	fprintf(fp, "Hello\n");
	fprintf(fp, "World\n");

	fp2 = fopen("hello.txt", "at"); // a -> 추가하기
	if (fp2 == NULL)
	{
		printf("file open error!\n");
		return 1;
	}

	fprintf(fp2, "Hi\n");
	fprintf(fp2, "Everybody\n");

	fclose(fp);
	fclose(fp2);
}