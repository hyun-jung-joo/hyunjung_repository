#include <stdio.h>
#define MAX_STACK_SIZE 3

typedef int element; // element -> int

typedef struct {
	element data[MAX_STACK_SIZE]; // element 
	int top;
} StackType;

void init(StackType* s)
{
	s->top = -1; // -1 �� �ʱ�ȭ
}

int is_empty(StackType* s)
{
	return (s->top == -1); // -1 
}

int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item)
{
	if (is_full(s)) { // �� á���� ���� üũ
		fprintf(stderr, "���� ��ȭ ����\n"); // 
		return;
	}
	else
		s->data[++(s->top)] = item; // top ���� ���� ���Ѽ� �ڸ��� �ְ�, �� ���ο� �ڸ��� item �� �ִ´� 
}

element pop(StackType* s)
{
	if (is_empty(s)) { // empty Ȯ��
		fprintf(stderr, "<empty>\n--\n");
		exit(1);
	}
	else
		return s->data[(s->top)--]; // s->top �� return �ϰ� ���� ��Ų��. -> �ڿ� -- 
}

element peek(StackType* s)
{
	if (is_empty(s)) { // empty Ȯ��
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
		return s->data[s->top]; // top �� return �� ! �߰��� ���Ұ� ����
}

void stack_print(StackType* s)
{
	int i;

	if (is_empty(s)) // �������
		printf("<empty>\n--\n"); // empty ���
	else {
		printf("%d  <- top\n", s->data[s->top]); // top ���� ��� �ϱ� 
		for (i = s->top - 1; i >= 0; i--) // �� ���������� �ݺ��� 
			printf("%d\n", s->data[i]);
		printf("--\n");
	}
}

void main()
{
	StackType s;

	init(&s);
	stack_print(&s);
	
	push(&s, 10);
	stack_print(&s);

	push(&s, 20);
	stack_print(&s); 

	push(&s, 30);
	stack_print(&s);

	push(&s, 40);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	push(&s, 50);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	return 0;
}