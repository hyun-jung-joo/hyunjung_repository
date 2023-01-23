#include <stdio.h>
#define MAX_STACK_SIZE 3

typedef int element; // element -> int

typedef struct {
	element data[MAX_STACK_SIZE]; // element 
	int top;
} StackType;

void init(StackType* s)
{
	s->top = -1; // -1 로 초기화
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
	if (is_full(s)) { // 다 찼는지 먼저 체크
		fprintf(stderr, "스택 포화 에러\n"); // 
		return;
	}
	else
		s->data[++(s->top)] = item; // top 먼저 증가 시켜서 자리를 주고, 그 새로운 자리에 item 을 넣는다 
}

element pop(StackType* s)
{
	if (is_empty(s)) { // empty 확인
		fprintf(stderr, "<empty>\n--\n");
		exit(1);
	}
	else
		return s->data[(s->top)--]; // s->top 꺼 return 하고 감소 시킨다. -> 뒤에 -- 
}

element peek(StackType* s)
{
	if (is_empty(s)) { // empty 확인
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s->data[s->top]; // top 꺼 return 만 ! 추가나 감소가 없다
}

void stack_print(StackType* s)
{
	int i;

	if (is_empty(s)) // 비었으면
		printf("<empty>\n--\n"); // empty 출력
	else {
		printf("%d  <- top\n", s->data[s->top]); // top 먼저 출력 하기 
		for (i = s->top - 1; i >= 0; i--) // 그 다음꺼부턴 반복문 
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