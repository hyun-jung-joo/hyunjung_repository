#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void makeCode(char* src, char* target, int distance)
{
	int i;
	for (i = 0; i < 26; i++) {
		target[i] = src[i] + distance;
		if (target[i] > 'Z')
			target[i] -= 26;
	}
}

void encoding(char* src, char* target, char* code)
{
	int i;
	int length = strlen(src);

	for (i = 0; i < length; i++) {
		if (src[i] >= 'A' && src[i] <= 'Z') {
			int key_code = src[i] - 'A';
			target[i] = code[key_code];
		}
		else
			target[i] = src[i];
	}
}

int main(void)
{
	int distance, i;
	char alphabet[27] = "";
	char code[27] = "";
	char sentence[80] = "";
	char new_sentence[80] = ""; 

	printf("Enter a distance for encoding:");
	scanf("%d", &distance);
	printf("---------------------------------------------\n");

	for (i = 0; i < 26; i++)
		alphabet[i] = 'A' + i;
	makeCode(alphabet, code, distance);

	printf("alphabet\t");
	printf("%s\n", alphabet);
	printf("encoded:\t");
	printf("%s\n", code);
	printf("---------------------------------------------\n\n");

	printf("Enter a sentence to encode: ");
	fgets(sentence, 79, stdin);
	fgets(sentence, 79, stdin);
	encoding(sentence, new_sentence, code);

	printf("original sentence:\t");
	printf("%s", sentence);
	printf("encoded sentence:\t");
	printf("%s\n", new_sentence);

	return 0;
}