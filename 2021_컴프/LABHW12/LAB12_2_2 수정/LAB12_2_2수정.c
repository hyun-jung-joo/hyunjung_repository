#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	FILE* fp;
	FILE* fp2;
	char buf[30];
	int i;

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

	for (i = 0; i < 2; i++) {
		fgets(buf, sizeof(buf), fp); // �Է� ���Ͽ��� ���� �о
		while (!feof(fp)) // ������ ���� �ƴϸ� ��� �ݺ�
		{
			fputs(buf, fp2); // ��� ���Ͽ� ���
			fgets(buf, sizeof(buf), fp); // �Է� ���Ͽ��� �� �о(�ٽ�) ������ ��
		}
		fseek(fp, 0, SEEK_SET);
	}

	fclose(fp);
	fclose(fp2);
}