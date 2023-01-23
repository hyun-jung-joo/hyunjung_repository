#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void echo(int* s)
{
	int i;
	for (i = 0; i < 5; i++)
		scanf("%d", &s[i]);
}

void reverse(int* s)
{
	int temp, i;
	
	for (i = 0; i < 2; i++) {
		temp = s[i];
		s[i] = s[4 - i];
		s[4 - i] = temp;
	}
	for (i = 0; i < 5; i++)
		printf("%d ", s[i]);
}

int main(void)
{
	int str[5];
	int num = 0;

	echo(str);
	reverse(str);
}