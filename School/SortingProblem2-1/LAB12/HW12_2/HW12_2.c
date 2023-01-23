#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void remove_duplicated_char(char* word)
{
	int i, j, k;
	int length = strlen(word);

	for (i = 0; i < length; i++) {
		for (j = i + 1; j < length; j++) {
			if (word[i] == word[j]) {
				for (k = j; k < length; k++) {
					word[k] = word[k + 1];
				}
			}
		}
	}
}

void makeCode(char *src, char* code, int distance, char *key)
{
	int i, j, k;
	int count = 0;
	int length = strlen(key);
	int longlength = distance + length;
		
	for (i = distance - 1, k = 0; count != distance; i--, k++) {
		int flag = 1;
		char c = src[26 - k - 1];
		for (j = 0; j < length; j++) {
			if (c == key[j]) {
				i++;
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			code[i] = c;
			count++;
			if (code[i] > 'Z')
				code[i] -= 26;
		}
	}

	for (i = distance, j = 0; i < longlength; i++, j++) {
		code[i] = key[j];
	}

	for (i = longlength, j = 0; i < 26 + longlength; i++, j++) {
		code[i] = src[j];
	}

	remove_duplicated_char(code);
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
	char key[30] = "";
	char alphabet[27] = "";
	char code[80] = "";
	char sentence[80] = "";
	char encoded_sentence[80] = "";

	printf("Enter a key to use for encoding<대문자로 된 단어입력>:");
	scanf("%s", key);
	remove_duplicated_char(key);
	printf("%s\n", key);
	printf("Enter a distance for encoding:");
	scanf("%d", &distance);
	printf("---------------------------------------------\n");
	
	for (i = 0; i < 26; i++)
		alphabet[i] = 'A' + i;
	makeCode(alphabet, code, distance, key);

	printf("alphabet\t");
	printf("%s\n", alphabet);
	printf("encoded:\t");
	printf("%s\n", code);
	printf("---------------------------------------------\n\n");
	
	printf("Enter a sentence to encode: ");
	fgets(sentence, 79, stdin);
	fgets(sentence, 79, stdin);
	encoding(sentence, encoded_sentence, code);
	

	printf("original sentence:\t");
	printf("%s", sentence);
	printf("encoded sentence:\t");
	printf("%s", encoded_sentence);
	
	return 0;
}