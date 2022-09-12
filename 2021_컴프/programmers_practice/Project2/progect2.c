#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(char *word) {
	int answer = 0;
	int i, j, mul = 1, length;


	for (length = 0; word[length] != '\0'; length++);
	
	for(i = 0; word[i] != '\0'; i++) {
		for (j = 1; j < length - i; j++)
			mul *= 10;
		answer += (word[i] - 48) * mul;
		mul = 1;
	}

	return answer;
}

int main(void)
{
	char word[20];
	int answer;
	scanf("%s", word);
	answer = solution(word);
	printf("%d\n", answer);
}

