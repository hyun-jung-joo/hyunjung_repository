#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	int len;
	int i;
	int j = 0;
	char str[1000];
	char new_str[1000];
	int count = 0;
	scanf("%s", str);
	len = strlen(str);

	for (i = 0; i < len; i++) {
		count++;
		if (str[i] != str[i + 1]) {
			if (count == 1) {
				printf("%c", str[i]);
				new_str[j] = str[i];
				j++;
			}
			else {
				printf("%d%c", count, str[i]);
				new_str[j] = count;
				new_str[j + 1] = str[i];
				j = j + 2;
			}
			count = 0;
		}
	}
	new_str[j] = '\0';
	printf("\n%d", strlen(new_str));
}