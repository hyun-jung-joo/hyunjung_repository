#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	int i, j;
	char key[10];
	char num[5];
	char str[1000];
	char str2[1000];
	char temp[1000] = "";
	int count = 0;
	int count2 = 0;

	scanf("%s", str);

	for (i = 0; i < 2; i++)
		key[i] = str[i];
	key[i] = '\0';

	for (i = 0; i < strlen(str); i += 2) {
		count++;
		for (j = 0; j < 2; j++) {
			str2[j] = str[j + i + 2];
		}
		str2[j] = '\0';

		if (strcmp(key, str2) != 0) {
			if (count == 1) {
				printf("%s", key);
				strcat(temp, key);
			}
			else {
				printf("%d%s", count, key);
				num[0] =  count + '0';
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

	printf("\n");
	if(count2 > 0)
		printf("%d", strlen(temp) + count2 - 1);
	else
		printf("%d", strlen(temp));
}