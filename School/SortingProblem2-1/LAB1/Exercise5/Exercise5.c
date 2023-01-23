#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int count = 0;
	char string[99];
	char key;

	printf("Enter a String: ");
	gets(string);
	printf("Enter a character: ");
	scanf("%c", &key);

	for (int i = 0; string[i] != '\0'; i++)
		if (key == string[i])
			count++;

	printf("\'%c\' is appeared %d times", key, count);
}