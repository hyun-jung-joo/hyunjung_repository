#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int num[5];
	int key;
	int i, count;

	printf("Enter 5���� ����: ");
	for (i = 0; i < 5; i++)
		scanf("%d", &num[i]);

	printf("Enter a key: ");
	scanf("%d", &key);

	for (i = 0; i < 5; i++) {
		if (key == num[i]) {
			count = i + 1;
			break;
		}
	}
	if (i == 5)
		printf("����\n");
	else
		printf("%d��°�� �ִ�\n", count);
}