#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int n1[5];
	int n2[5];
	int same;
	int i;

	printf("Enter 첫번째 배열: ");
	for (i = 0; i < 5; i++)
		scanf("%d", &n1[i]);
	printf("Enter 두번째 배열: ");
	for (i = 0; i < 5; i++)
		scanf("%d", &n2[i]);

	same = 1;
	for (i = 0; i < 5; i++)
	{
		if (n1[i] != n2[i]) {
			same = 0;
			break;
		}
	}

	if (same == 1)
		printf("두 개의 배열은 같다");
	else
		printf("두 개의 배열은 다르다");
}
