#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 100
#define MAX_STRING 100

typedef char element; // char 로 element 변경 

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
		fprintf(stderr, "스택 포화 에러\n");
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
		fprintf(stderr, "스택 공백 에러\n");
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
	StackType s; // stackType s 변수 선언

	int i;
	int length = strlen(str);
	init(&s);

	for (i = 0; i < length; i++)
		push(&s, str[i]);

	for (i = 0; i < length / 2; i++) {
		if (pop(&s) != str[i]) // 묹자열과 pop 맨뒤 꺼를 비교하는 식 
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
		printf("palindrome 입니다.\n"); 
	else
		printf("palindrome 이 아닙니다.\n");
}