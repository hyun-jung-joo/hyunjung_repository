#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int i;
	char key;
	srand(time(NULL));

	printf("*** �ζ� ��ȣ ������ ***\n");
	while(1) {
		printf("���� ��ȣ:");
		for (i = 1; i <= 6; i++)
			printf("%d ", rand() % 45 + 1);
	
		printf("\n�ٽ� �����ϰڽ��ϱ�? (y/n):");
		scanf(" %c", &key); // �տ� ���� �־��ֱ� - \n ����

		if (key == 'y')
			continue;
		else
			break;
	} 
}