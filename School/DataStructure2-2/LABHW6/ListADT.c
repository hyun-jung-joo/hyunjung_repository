#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode { //노드타입
	element data;
	struct ListNode* link;
} ListNode;

//오류 처리 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1); // 프로그램 자체를 종료
}

//노드 pre 뒤에 새로운 노드 삽입 - 시간의 복잡도 O(1)
ListNode* insert_next(ListNode* head, ListNode* pre, element value) // insert ,pre = preview(이전 node)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //(1) 새로운걸 할당 한다 

	p->data = value; //(2)
	p->link = pre->link; //(3) 원래의 link 를 p꺼에 연결 시킴
	pre->link = p; //(4) pre 꺼를 p 에 연결
	return head; //(5) 변경된 헤드 포인터 반환
}

//시간의 복잡도 O(1)
ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //(1)
	p->data = value; // (2)
	p->link = head; //헤드포인터의 값을 복사 / 맨앞이니까				
	//(3)
	head = p; //헤드 포인터변경

	//(4)
	return head; // 변경된 헤드 포인터 반환
}

//시간의 복잡도 O(n) 
ListNode* insert_last(ListNode* head, int value)
{
	ListNode* temp = head; // 이사를 다니는 역할 temp -> 마지막 자리 찾기
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //(1)
	p->data = value;
	p->link = NULL; // 마지막이니까 null 
	// (2)
	if (head == NULL) //공백 리스트이면
		head = p; // head 에 p 를
	else {
		while (temp->link != NULL) // temp->link null 일때까지
			temp = temp->link;

		temp->link = p;
	}
	return head; //변경된 헤드 포인터 반환
}

//삭제도 return 이 있음 
// 삭제한다 -> memory 에서 해제 시킨다(free (대상 : removed 노드)시킨다)

// pre가 가르키는 노드의 다음 노드를 삭제한다. - 시간의 복잡도 O(1)
ListNode* delete_next(ListNode* head, ListNode* pre)
{
	ListNode* removed;

	removed = pre->link; // 전(pre)의 꺼의 link를 가르킴
	pre->link = removed->link; // (2) 전의 꺼는 removed 가 가르키고 있던 link 의 연결 (removed 다음항목에 연결)
	free(removed); // (3) removed 해제
	return head; // (4) 변경된 헤드 포인터 반환
}

//맨 앞에 것 삭제,  시간의 복잡도 O(1) 
ListNode* delete_first(ListNode* head)
{
	ListNode* removed;

	if (head == NULL) error("삭제할 항목이 없음");

	removed = head; // (1) head를 받음 -> head가 가르키는 것을 
	head = removed->link; // (2) 삭제할 것의 link 를 가져서 removed의 다음꺼로 연결(link)을 시켜줌->헤드 이동 
	free(removed); // (3) 다 연결시켜뒀으니 -> removed 는 해제
	return head; // (4) 변경된 헤드 포인터 반환
}

//마지막꺼 삭제하기 ->  시간의 복잡도 O(n)
ListNode* delete_last(ListNode* head)
{
	ListNode* temp = head;
	ListNode* prevTemp; // temp 를 따라가는 역할 
	ListNode* removed;

	if (head == NULL) error("삭제할 항목이 없음");
	if (temp->link == NULL) { //하나의 노드 -> 삭제될 대상은 head
		removed = temp->link; // head거를 removed에 연결
		temp->link = NULL; // temp 를 null 로 
		free(removed); // 해제

		return NULL; // null 을 return
	}
	else { // 둘 이상의 노드
		while (temp->link != NULL) { // null 이 아니면 temp 는 계속 뒤로 이동(이사) -> 마지막꺼 찾기
			prevTemp = temp; // temp 의 바로 앞 ->  preTemp 는 같이 따라간다. -> temp 가 먼저 전진 
			temp = temp->link; // temp 는 다음거를 가르킨다 
		}
		// while에서 빠져나오면 
		removed = temp;
		prevTemp->link = NULL; // 마지막의 전꺼 연결을 null 로 ! -> 연결을 없애버린다.
		free(removed); // 해제
		return head; //그대로 
	}
}

void print_list(ListNode* head)
{
	ListNode* p;
	for (p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

ListNode* search(ListNode* head, int x) // x 가 있는지 찾기 
{
	ListNode* p;
	p = head; // p 는 temp 와 비슷한 일을 한다

	while (p != NULL) { // p가 null 이 아니면 반복, null을 만나면 끝나기 (link 가 null 일 때까지 가면 끝까지 가지 못하고 멈춤 -> node 가 null 일 때까지로 !) 
		if (p->data == x) return p; // 탐색 성공 : x 와 p->data 같은지 여부에 따라
		p = p->link; // p 가 다음꺼로 이사 
	}
	return NULL; // 탐색 실패일 경우 NULL 반환
}

ListNode* concat(ListNode* head1, ListNode* head2) // 두 개의 리스트를 잇기 -> head1 뒤에 head2를 이어준다.
{
	ListNode* p;
	if (head1 == NULL) return head2; // head1에 아무것도 없을때 head2 만 리턴
	else if (head2 == NULL) return head1; // 위의 반대 경우 
	else { // 둘 다 null 이 아니면
		p = head1;
		while (p->link != NULL) // p가 이동 -> data 를 이용하는게 아니므로 p->link 가 null 일 때로 ! 마지막꺼 찾기 ! 
			p = p->link; // p는 다음꺼로 이사
		p->link = head2; // 마지막꺼에 head2를 연결
		return head1; // 앞에꺼를 return
	}
}

ListNode* reverse(ListNode* head) // 역순으로 만들기
{
	// 순회 포인터로 p, q, r을 사용
	ListNode *p, *q, *r;
	p = head; // p는 역순으로 만들 리스트(원래 리스트)
	q = NULL; // q는 역순으로 만들 노드
	while (p != NULL) { // p(원래 리스트)가 null 이 아닐때까지 -> 마지막꺼까지는 끝낸다 , 마지막 다음에서 멈춘다
		r = q; // r은 역순으로 된 리스트. r은 q, q는 p를 차례로 따라간다. 
		q = p; // q는 p 꺼를 저장
		p = p->link; // p 는 다음꺼로 이동
		q->link = r; // q의 링크 방향을 바꾼다. 
	}
	
	return q; // q는 역순으로 된 리스트의 헤드 포인터
}

int main(void)
{
	ListNode* head1 = NULL, * head2;
	int i;
	for (i = 0; i < 5; i++) {
		head1 = insert_last(head1, i * 10);
		print_list(head1);
	}
	head2 = reverse(head1);
	print_list(head2);
	head2 = insert_pos(head2, 1, 99);
	print_list(head2);
	head2 = delete_last(head2);
	print_list(head2);
	head1 = NULL;
	head1 = insert_first(head1, 100);
	head1 = insert_first(head1, 200);
	print_list(head1);
	head1 = concat(head1, head2);
	print_list(head1);
}