#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 3
#define MAX_STRING 100

//element 값이 두가지 ! -> 2개를 넣어야함 한 스택에 
typedef struct {
	int num;
	char nums[MAX_STRING]; // 문자열도 있음
} element;

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

void stack_print(StackType* s) // 포인터로 받는다
{
	int i;

	if (is_empty(s))
		printf("<empty>\n--\n");
	else {
		printf("[%d, %s] <- top\n", s->data[s->top].num, s->data[s->top].nums); //num, nums 는 변수니까 -> 포인터가 아니다
		for (i = s->top - 1; i >= 0; i--)
			printf("[%d, %s]\n", s->data[i].num, s->data[i].nums);
		printf("--\n");
	}
}

void main()
{
	StackType s; // 구조체 변수 
	element e; // element 를 선언한다 -> 구조체 변수임(포인터가 아님) 

	init(&s); // 초기화 
	stack_print(&s); // print 

	e.num = 10; // e.num = 10; 
	strcpy(e.nums, "ten"); // 문자열은 strcpy ! 
	push(&s, e); // 주소를 보낸다 -> 변수니까 
	stack_print(&s);
	

	e.num = 20;
	strcpy(e.nums, "twenty");
	push(&s, e);
	stack_print(&s);

	e.num = 30;
	strcpy(e.nums, "thirty");
	push(&s, e);
	stack_print(&s);

	e.num = 40;
	strcpy(e.nums, "fourty");
	push(&s, e);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	e.num = 50;
	strcpy(e.nums, "fifty");
	push(&s, e);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

}