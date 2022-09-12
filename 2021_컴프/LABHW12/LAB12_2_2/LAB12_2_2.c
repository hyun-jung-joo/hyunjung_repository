#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	FILE* fp; 
	FILE* fp2;
	char buf[30];
	
	fp = fopen("hello.txt", "rt");
	if (fp == NULL)
	{
		printf("file open error!\n");
		return 1;
	}

	fp2 = fopen("hello2.txt", "wt");
	if (fp2 == NULL)
	{
		printf("file open error!\n");
		return 1;
	}

	fgets(buf, sizeof(buf), fp); // 입력 파일에서 한줄 읽어서
	while (!feof(fp)) // 파일의 끝이 아니면 계속 반복
	{
		fputs(buf, fp2); // 출력 파일에 출력
		fgets(buf, sizeof(buf), fp); // 입력 파일에서 또 읽어서(다시) 한줄을 읽
	}
	fclose(fp);
	fclose(fp2);
}