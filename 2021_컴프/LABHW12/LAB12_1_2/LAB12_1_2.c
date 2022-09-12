#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int state;
	FILE* fp;

	char ch;

	fp = fopen("hello.in", "rt"); 
	if (fp == NULL)
	{
		printf("파일 오픈 에러입니다!!!\n");
		return 1;
	}

	ch = getc(fp); // getc, putc를 사용하여 파일의 끝까지 읽고 쓴다
	while (!feof(fp))
	{
		putc(ch, stdout);
		ch = getc(fp);
	}

	fclose(fp);
	return 0;
}