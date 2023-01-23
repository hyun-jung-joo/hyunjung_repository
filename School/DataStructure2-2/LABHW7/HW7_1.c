#include <stdio.h>
#include <stdlib.h>
typedef int element;

typedef struct ListNode { //노드타입
	element data;
	struct ListNode* link;
} ListNode;

void print_list(ListNode* head) //수정해야함
{
	ListNode* p;

	if (head == NULL) return; // 아무것도 없다 
	p = head->link;  // p 는 맨앞을 가르킨다 

	while (p != head) { // p 가 head가 아닐때까지 
		printf("%d->", p->data); 
		p = p->link; // p 를 이동 시키기 
	}
	printf("%d->", p->data); //마지막 노드 출력	(head)
	printf("\n");
}

ListNode* insert_first(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;

	if (head == NULL) { // 아무것도 없으면 
		head = node; // head 에 node를 
		node->link = head; // 맨뒤가 null 이 되면 안되서 자기 자신을 가르킨다. ! 
	}
	else {
		node->link = head->link; // (1) 원래의 맨앞을 가르킴
		head->link = node; // (2) 노드를 가르킴 
	}
	return head; //변경된 헤드 포인터를 반환한다.
}

ListNode* insert_last(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) { // 아무것도 없으면 
		head = node;
		node->link = head; // 자기자신을 가르키게 
	}
	else {
		node->link = head->link; // (1) 헤드 가 가르키던걸 뉴가 가르킴 
		head->link = node; // (2) 헤드는 뉴를 가르킴
		head = node; // (3) 헤드는 뉴가 됨 ! 
	}
	return head; //변경된 헤드 포인터를 반환한다.
}

ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) { //없을때 
		printf("리스트가 비어 삭제를 못함\n");
			return NULL;
	}
	else if (head == head->link) { //하나의 노드가 남았을때
		removed = head; // 헤드를 삭제함 
		head = NULL; // 헤드는 널이 된다 
		//head->link = head // head가 null 이라서 안써도 되는 것 
		free(removed);//해제 
	}
	else {
		removed = head->link; // 맨앞거가 removed
		head->link = removed->link; // head 는 리무브 다음꺼 가르킴 
		free(removed);// 해제 
	}
	return head;
}

ListNode* delete_last(ListNode* head)
{
	ListNode* removed = head;
	ListNode* p = head; // p 로 마지막걸 찾음 

	if (head == NULL) {
		printf("리스트가 비어 삭제를 못함\n");
		return NULL;
	}
	else if (head == head->link) { //하나의 노드가 남았을때
		head = NULL;
		//head->link = head // head가 null 이라서 안써도 되는 것 
		free(removed);
	}
	else {
		while (p->link != head) // head 바로 전꺼를 찾음 
			p = p->link;
		p->link = removed->link; // 리무브가 가르키던걸 p 가 가르킨다 
		head = p; // 헤드의 이동 !! 
		free(removed);
	}

	return head;
}

ListNode* search(ListNode* head, element data)
{
	ListNode* p;

	if (head == NULL) return NULL;

	p = head;
	do {
		if (p->data == data)
			return p;
		p = p->link;
	} while (p != head);

	return NULL;
}

element get_size(ListNode* head)
{
	ListNode* p;
	int size = 0;

	if (head == NULL) return 0;

	p = head->link; // 처음꺼부터 시작함 -> size = 0
	do {
		size++; // size 증가 먼저 한다 (이사 전에)
		p = p->link;
	} while (p != head->link); // head 세고 멈춰야해서 head->link 까지로 / p 가 다시 앞으로 돌아올때까지 

	return size;
}

//원형 연결 리스트 테스트 프로그램
int main(void)
{
	ListNode* head = NULL;

	// list = 10->20->30->40
	head = insert_last(head, 20);
	print_list(head);

	head = insert_last(head, 30);
	print_list(head);
	head = insert_last(head, 40);
	print_list(head);
	head = insert_first(head, 10);
	print_list(head);
	head = delete_first(head);
	print_list(head);

	//여기부터는 임의로 쓴 부분
	head = delete_last(head);
	print_list(head);
	printf("list의 길이는 %d\n", get_size(head));

	return 0;
}