#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	int i, j, k = 0;
	//int len;
	int index = 0;
	char key[1000];
	char str[1000];
	char str2[1000];
	char temp[1000] = "";
	char num[5];
	int count = 0;
	int count2 = 0;
	int shortest = 1000;

	scanf("%s", str);

	for (i = 1; i <= strlen(str) / 2; i++) {
		temp[0] = '\0';
		strncpy(key, str, i);
		key[i] = '\0';
		count = 0;

		for (j = 0; j < strlen(str); j += i) {
			count++;
			k = 0;
			while (k < i) {
				str2[k] = str[j + k + i];
				k++;
			}
			str2[k] = '\0';

			if (strcmp(key, str2) != 0) {
				if (count == 1) {
					strcat(temp, key);
				}
				else {
					num[0] = count + '0';
					num[1] = '\0';
					strcat(temp, num);
					strcat(temp, key);

					if (count / 10 != 0) {
						while (count != 0) {
							count /= 10;
							count2++;
						}
					}
				}
				count = 0;
				strcpy(key, str2);
			}
		}

		if (count2 > 0) {
			if (shortest > strlen(temp) + count2 - 1)
				shortest = strlen(temp) + count2 - 1;
		}
		else {
			if (shortest > strlen(temp))
				shortest = strlen(temp);
		}	
	}
	printf("%d", shortest);
}