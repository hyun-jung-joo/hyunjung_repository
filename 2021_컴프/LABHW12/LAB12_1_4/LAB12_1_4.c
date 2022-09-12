#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int state;
	FILE* fp;
	char ch;

	fp = fopen("hello.txt", "wt");
	if (fp == NULL)
	{
		printf("file open error!\n");
		return 1;
	}

	fprintf(fp, "Hello\n");
	fprintf(fp, "World\n");

	state = fclose(fp);
	if (state != 0) // 이 체크는 생략 가능
	{
		printf("file close error!\n");
		return 1;
	}

	fp = fopen("hello.txt", "rt");
	if (fp == NULL) {
		printf("file open error!\n");
		return 1;
	}

	ch = getc(fp);
	while (!feof(fp)) {
		putc(ch, stdout);
		ch = getc(fp);
	}
	fclose(fp);
}