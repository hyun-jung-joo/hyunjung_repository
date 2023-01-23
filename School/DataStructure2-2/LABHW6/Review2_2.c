#include <stdio.h>
#include <stdlib.h> 

typedef int element;
// 자기 참조 구조체의 정의(선언)
typedef struct ListNode {
	element number;
	struct ListNode* link;
}ListNode;

// 6) 반복을 이용하여 노드리스트를 출력
// 출력 예: 1->10->20->30->44->
// 힌트: temp를 head부터 시작하여 전진하면서 temp가 가리키는 number를 출력. temp가 NULL이 될때까지.
void displayList1(ListNode* head) // 출력하고 temp 가 이사가는 방법
{
	ListNode* temp = head;

	while (temp != NULL){ // while(temp->link != NULL) 이랑 비교 -> temp->link 이면 마지막껄 출력 해주지 않는다 ! 
		printf("%d->", temp->number);
		temp = temp->link;
	}
}

// 7) 순환을 이용하여 노드리스트를 출력
// 출력 예: 1->10->20->30->44->
void displayList2(ListNode* head)
{
	if (head != NULL) { // 헤드를 직접 이동 시킨다 
		printf("%d->", head->number);
		displayList2(head->link); // 헤드를 헤드의 링크걸로 옮긴다 
	}
}

int main(void)
{
	ListNode* head, * newNode, * temp;

	// 1)
	// ListNode타입의 메모리(노드)를 생성한 후 newNode가 가리키게하고 10과 NULL을 넣어 노드값을 채우고
	// 이를 head가 가르키게한다. 즉 head는 노드 하나를 가리킨다.
	// 즉, head --> 10,NULL
	newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->number = 10;
	newNode->link = NULL;
	head = newNode; // newNode 연결


	// 2)
	// 같은 방법으로 newNode가 가리키는 메모리(노드)를 생성한후 20과 NULL을 넣어 노드값을 채우고 
	// // 아래처럼 되게 한다, 즉, 노드리스트 끝에 새로운 노드를 삽입한다.
	// head --> 10,--> 20,NULL

	newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->number = 20;
	newNode->link = NULL;
	head->link = newNode;// newNode 연결

	// 3)
	// 다시 newNode가 가리키는 메모리(노드)를 생성한후 30과 NULL을 넣어 노드값을 채우고
	// 아래처럼 되게 한다. 즉, 노드리스트 끝에 새로운 노드를 삽입한다.
	// head --> 10,--> 20,--> 30,NULL

	newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->number = 30;
	newNode->link = NULL;
	head->link->link = newNode; // newNode 연결

	// 4)
	// 다음과 같이 되게 한다.
	// head --> 10,--> 20,--> 30,--> 44,NULL
	// 노드리스트 끝에 새로운 노드를 삽입할 때,
	// temp포인터를 사용하여 head가 가리키는 노드리스트의 마지막을 가리키게 한 후
	// 이 temp를 사용하여 새노드(44,NULL)을 끝에 연결해보자. 
	newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->number = 44;
	newNode->link = NULL;
	
	temp = head;
	while (temp->link != NULL) // 마지막을 찾음
		temp = temp->link; // 다음으로 넘어감
	temp->link = newNode; // temp에 newNode 를 연결해준다 

	// 5)
	// 다음과 같이 되게 한다. 즉 노드리스트의 앞에 1을 갖는 노드를 삽입
	// head --> 1,--> 10,--> 20,--> 30,--> 44,NULL
	newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->number = 1;
	newNode->link = NULL;

	newNode->link = head; //head 보다 앞으로간다
	head = newNode; // 헤드 이동 시키기 

	// 6)7) displayList1, displayList2를 완성한 후 호출해본다
	displayList1(head);
	printf("\n");
	displayList2(head);
}