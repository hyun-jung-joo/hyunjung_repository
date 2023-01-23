#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int i;
	char key;
	srand(time(NULL));

	printf("*** 로또 번호 생성기 ***\n");
	while(1) {
		printf("생성 번호:");
		for (i = 1; i <= 6; i++)
			printf("%d ", rand() % 45 + 1);
	
		printf("\n다시 생성하겠습니까? (y/n):");
		scanf(" %c", &key); // 앞에 공백 넣어주기 - \n 방지

		if (key == 'y')
			continue;
		else
			break;
	} 
}