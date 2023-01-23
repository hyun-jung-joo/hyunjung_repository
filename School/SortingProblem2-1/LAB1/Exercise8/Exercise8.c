#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void input(char* s)
{
	int i;
	scanf("%s", s);
}

void reverse(char* s)
{
	int size = strlen(s);
	int i;

	for (i = size - 1; i >= 0; i--)
		printf("%c", s[i]);
}

int main(void)
{
	char str[99];
	int num = 0;

	input(str);
	reverse(str);
}