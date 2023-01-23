#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

//오류 처리 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//노드 pre 뒤에 새로운 노드 삽입 
ListNode* insert_next(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));

	p->data = value; 
	p->link = pre->link; // p는 전에꺼가 가르키던걸 가르킴
	pre->link = p; // 전꺼는 p를 가르킨다
	return head;
}

ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head; // p->link 는 헤드를 가르키고
	head = p;// 헤드는 p 가 된다

	return head;
}

//O(n)
ListNode* insert_last(ListNode* head, int value)
{
	ListNode* temp = head; // temp 의 이동으로 마지막을 찾는다 
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = NULL; // 마지막이니까 null 값을 가진다 

	if (head == NULL)
		head = p;
	else {
		while (temp->link != NULL) // temp->link 가 널일때까지 (temp 가 마지막이면)
			temp = temp->link; //템프 이동

		temp->link = p; // 템프 링크에 마지막꺼 p를 넣어준다
	}
	return head; // 리턴
}

// pre가 가르키는 노드의 다음 노드를 삭제한다.
ListNode* delete_next(ListNode* head, ListNode* pre) // 전껄 앎
{
	ListNode* removed;

	removed = pre->link; // 전의 link = 자신껏 리무브로
	pre->link = removed->link; // 전꺼를 리무브의 링크로 
	free(removed); // 해제 

	return head;
}

//맨 앞에 것 삭제
ListNode* delete_first(ListNode* head)
{
	ListNode* removed;

	if (head == NULL) error("삭제할 항목이 없음");

	removed = head; // 헤드꺼
	head = removed->link; // 헤드는 리무브 다음꺼
	free(removed); // 해제

	return head;
}

//마지막꺼 삭제하기 O(n)
ListNode* delete_last(ListNode* head)
{
	ListNode *temp = head;
	ListNode* prevTemp = head; // prevTemp -> temp 따라다님 (temp 전의꺼를 저장한다) 
	ListNode *removed;

	if (head == NULL) error("삭제할 항목이 없음");
	if (temp->link == NULL) { // 항목이 한개일때 temp->link == NULL
		removed = temp->link; 
		temp->link = NULL;
		free(removed);

		return NULL;
	}
	else {
		while (temp->link != NULL) { // temp 가 마지막거로 감
			prevTemp = temp; // prev는 temp를 따라다닌다
			temp = temp->link; // 템프는 이동
		}


		//마지막걸 찾으면 , 프리는 마지막 전 꺼
		removed = temp;
		prevTemp->link = NULL; // 프리꺼를 널로 바꿈
		free(removed); // 마지막껀 해제
		return head;
	}
}

void print_list(ListNode* head)
{
	ListNode* p;
	for (p = head; p != NULL; p = p->link) // p->head , p!= NULL(link 아님) , p=p->link 
		printf("%d->", p->data);
	printf("NULL \n"); // 마지막은 널
}

ListNode* search(ListNode* head, int x)
{
	ListNode* p;
	p = head;

	while (p != NULL) {
		if (p->data == x) return p;
		p = p->link;
	}
	return NULL;
}

ListNode* concat(ListNode* head1, ListNode* head2)
{
	ListNode* p;
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1;
	else {
		p = head1;
		while (p->link != NULL)
			p = p->link;
		p->link = head2;
		return head1;
	}
}

ListNode* reverse(ListNode* head) // 역순으로 만들기
{
	ListNode* p, * q, * r;
	p = head;
	q = NULL;
	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}

	return q;
}

//item 이 리스트에 있으면 1 을 아니면 0 을 반환 
int is_in_list(ListNode* head, element item)
{
	ListNode* p;
	for (p = head; p != NULL; p = p->link) // p->link아님 !! -> 이건 마지막 데이터 비교 안됨
		if (p->data == item)
			return 1;
	return 0;
}

//단순 연결 리스트에 존재하는 노드의 수를 반환
int get_length(ListNode* head)
{
	int count = 0;
	ListNode* p;

	for (p = head; p != NULL; p = p->link)
		count++;
	return count;
}

//단순연결리스트의 모든 데이터 값을 더한 합을 반환
int get_total(ListNode* head)
{
	int total = 0;
	ListNode* p;

	for (p = head; p != NULL; p = p->link)
		total += p->data;
	return total;
}

//pos 위치(0 이 첫 번째 노드)에 있는 노드의 data 를 반환
element get_entry(ListNode* head, int pos)
{
	ListNode* p = head;
	int i = 0;
	
	if (pos < 0 && pos >= get_length(head)) // pos 위치 확인 먼저
		return -1; // 오류-> error 메세지로 표현 하는게 더 좋음
	else {
		for (i = 0; i < pos; i++) // pos 전까지 증가시키기
			p = p->link;
		return p->data; // p는 p->link 이므로 pos 가 되었음 
	}

	//ver2
	//i = 0;
	//while (p != NULL) { 
	//	if (i == pos)
	//		return p->data;
	//	i++;
	//	p = p->link;
	//}
}

ListNode* delete_by_key(ListNode* head, int key)
{
	ListNode* p = head;
	int i = 0; 
	
	if (head == NULL) // 하나도 없음
		return NULL; // error
	while (p != NULL) { // p를 뒤로 이동마지막까지 
		if (p->data == key) // 찾으면 
			return delete_pos(head, i); // i와 함께 pos 로 넘김
		p = p->link; // p 이동 
		i++; //위치
	}

	printf("%d값을 지닌 노드는 존재하지 않는다\n", key);
	return head;


	/*ListNode* p = head;
	ListNode* removed;
	ListNode* preKey = NULL; // 전에 꺼를 찾는다 . 전에꺼가 따라간다 

	if (head == NULL)
		return NULL;
	else {
		while (p != NULL) {
			if (key == p->data) {
				removed = p;
				preKey->link = removed->link;
				free(removed);
				return head;
			}
			preKey = p;
			p = p->link;
		}
	}

	return head;*/
}

//pos 위치에 value 를 갖는 노드를 추가
ListNode* insert_pos(ListNode* head, int pos, element value)
{
	ListNode* p = head;
	int i;

	if (pos == 0) // 처음자리면 
		return insert_first(head, value);
	else { // 아니면 
		for (i = 0; i < pos - 1; i++) // pos 전전까지 ! -> next 로 넘김
			p = p->link; // link 니까 하나 더 적게로 고려해야함 
		return insert_next(head, p, value); // p가 pre ! 
	}


	//ListNode* p = head;
	//ListNode* plus = (ListNode*)malloc(sizeof(ListNode));
	//ListNode* prevPos = NULL;
	//int index = 0;

	//plus->data = value;
	//plus->link = NULL;

	//if (head == NULL)
	//	head = p;
	//else if(pos == 0) {
	//	head = insert_first(head, value);
	//}
	//else {
	//	while (p != NULL) {
	//		if (index == pos) {
	//			plus->link = prevPos->link;
	//			prevPos->link = plus;
	//			return head;
	//		}
	//		prevPos = p; // pre 에 p 를 넣기 -> 따라간다 
	//		p = p->link; // p 증가
	//		index++; // 위치를 증가시킨다 
	//	}
	//}

	//return head;
}

// pos 위치의 노드를 삭제
ListNode* delete_pos(ListNode* head, int pos)
{
	ListNode* p = head;
	int i;

	if (head == NULL)
		return NULL; // error
	else if (pos == 0){ // 1개 
		return delete_first(head);
	}
	else { //여러개
		for (i = 0; i < pos - 1; i++) // 전전꺼를 찾음 
			p = p->link;
		return delete_next(head, p); // pre로 p를 보낸다
	}



	/*ListNode* p = head;
	ListNode* removed;
	ListNode* prevPos = NULL;
	int index = 0;

	if (head == NULL)
		return NULL; // error
	else if (pos == 0) {
		return delete_first(head);
	}
	else {
		while (p != NULL) {
			if (index == pos) {
				removed = p;
				prevPos->link = removed->link;
				free(removed);
				return head;
			}
			index++;
			prevPos = p;
			p = p->link;
		}
	}
	
	return head;*/
}

int main(void)
{
	ListNode* list1 = NULL, * list2 = NULL, * list3; // 헤드임 

	//list1 = 30->20->10->를 만든다. 이때 10, 20, 30의 순으로 노드를 삽입한다. 
	list1 = insert_first(list1, 10);
	list1 = insert_first(list1, 20);
	list1 = insert_first(list1, 30);
	// list1을 출력
	printf("list1 = ");
	print_list(list1);

	//list1의 맨 앞 노드를 삭제한다 즉, list1 = 20->10->
	list1 = delete_first(list1);
	// list1을 출력
	printf("list1 = ");
	print_list(list1);

	//list2 = 11->22->33->44->를 만든다. 이때 11, 22, 33, 44의 순으로 노드를 삽입한다. 
	list2 = insert_last(list2, 11);
	list2 = insert_last(list2, 22);
	list2 = insert_last(list2, 33);
	list2 = insert_last(list2, 44);

	// list2를 출력
	printf("list2 = ");
	print_list(list2);

	// list2의 맨 뒤 노드를 삭제한다. 즉, list2 = 11->22->33->
	list2 = delete_last(list2);

	// list2를 출력
	printf("list2 = ");
	print_list(list2);

	//list2를 역순으로 바꾼 리스트를 list3가 가리키게 한다. list3 = 33->22->11->를 만든다.
	list3 = reverse(list2);

	//list3를 출력한다. 
	printf("list3 = ");
	print_list(list3);

	// list1 = 20->30->33->22->11->를 만든다. 즉, list1과 list3를 합쳐서 list1이 가리키게 한다. 
	list1 = concat(list1, list3);

	//list1을 출력한다. 
	printf("list1 = ");
	print_list(list1);

	printf("\n");
	//(A) 주의: 여기서부터는 list1만 사용하여 함수들을 테스트하자
	
	//list1 에 33이 있는지 확인
	int is_in_key = 33;
	if(is_in_list(list1, is_in_key))
		printf("list1에 %d이 있다.\n", is_in_key);
	else
		printf("list1에 %d이 없다.\n", is_in_key);

	//리스트 노드 수 반환
	printf("list1의 길이는 %d 이다.\n", get_length(list1));

	//모든 데이터 값을 더한 합 반환
	printf("list1의 모든 데이터 값의 합은 %d이다.\n", get_total(list1));

	//key 값 삭제
	int delete_key = 33;
	list1 = delete_by_key(list1, delete_key);
	//list1을 출력한다. 
	printf("데이터가 %d인 것을 삭제하면 list1 = ", delete_key);
	print_list(list1);

	//pos 위치에 value값 노드 추가
	int insert_value = 40;
	int insert_poskey = 2;
	list1 = insert_pos(list1, insert_poskey, insert_value);
	//list1을 출력한다.
	printf("%d를 %d자리에 추가하면 list1 = ", insert_value, insert_poskey);
	print_list(list1);

	//pos 위치 노드 삭제
	int delete_poskey = 1;
	list1 = delete_pos(list1, delete_poskey);
	//list1을 출력한다.
	printf("%d 자리 노드를 삭제하면 list1 = ", delete_poskey);
	print_list(list1);
}