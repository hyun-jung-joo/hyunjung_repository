#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 100
#define MAX_STRING 100

typedef char element; // char �� element ���� 

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

void init(StackType* s)
{
	s->top = -1;
}

int is_empty(StackType* s)
{
	return (s->top == -1);
}

int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else
		s->data[++(s->top)] = item;
}

element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "<empty>\n--\n");
		exit(1);
	}
	else
		return s->data[(s->top)--];
}

element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
		return s->data[s->top];
}

void stack_print(StackType* s)
{
	int i;

	printf("%d  <- top\n", s->data[s->top]);

	for (i = s->top - 1; i >= 0; i--)
		printf("%d\n", s->data[i]);
}

int palindrome(char str[])
{
	StackType s; // stackType s ���� ����

	int i;
	int length = strlen(str);
	init(&s);

	for (i = 0; i < length; i++)
		push(&s, str[i]);

	for (i = 0; i < length / 2; i++) {
		if (pop(&s) != str[i]) // �L�ڿ��� pop �ǵ� ���� ���ϴ� �� 
			return 0;
	}
	return 1;
}

int main(void)
{
	char word[MAX_STRING]; 

	printf("Enter a word to check palindrome: "); 
	scanf("%s", word); 

	if (palindrome(word)) 
		printf("palindrome �Դϴ�.\n"); 
	else
		printf("palindrome �� �ƴմϴ�.\n");
}