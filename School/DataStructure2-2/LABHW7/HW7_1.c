#include <stdio.h>
#include <stdlib.h>
typedef int element;

typedef struct ListNode { //���Ÿ��
	element data;
	struct ListNode* link;
} ListNode;

void print_list(ListNode* head) //�����ؾ���
{
	ListNode* p;

	if (head == NULL) return; // �ƹ��͵� ���� 
	p = head->link;  // p �� �Ǿ��� ����Ų�� 

	while (p != head) { // p �� head�� �ƴҶ����� 
		printf("%d->", p->data); 
		p = p->link; // p �� �̵� ��Ű�� 
	}
	printf("%d->", p->data); //������ ��� ���	(head)
	printf("\n");
}

ListNode* insert_first(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;

	if (head == NULL) { // �ƹ��͵� ������ 
		head = node; // head �� node�� 
		node->link = head; // �ǵڰ� null �� �Ǹ� �ȵǼ� �ڱ� �ڽ��� ����Ų��. ! 
	}
	else {
		node->link = head->link; // (1) ������ �Ǿ��� ����Ŵ
		head->link = node; // (2) ��带 ����Ŵ 
	}
	return head; //����� ��� �����͸� ��ȯ�Ѵ�.
}

ListNode* insert_last(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) { // �ƹ��͵� ������ 
		head = node;
		node->link = head; // �ڱ��ڽ��� ����Ű�� 
	}
	else {
		node->link = head->link; // (1) ��� �� ����Ű���� ���� ����Ŵ 
		head->link = node; // (2) ���� ���� ����Ŵ
		head = node; // (3) ���� ���� �� ! 
	}
	return head; //����� ��� �����͸� ��ȯ�Ѵ�.
}

ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) { //������ 
		printf("����Ʈ�� ��� ������ ����\n");
			return NULL;
	}
	else if (head == head->link) { //�ϳ��� ��尡 ��������
		removed = head; // ��带 ������ 
		head = NULL; // ���� ���� �ȴ� 
		//head->link = head // head�� null �̶� �Ƚᵵ �Ǵ� �� 
		free(removed);//���� 
	}
	else {
		removed = head->link; // �ǾհŰ� removed
		head->link = removed->link; // head �� ������ ������ ����Ŵ 
		free(removed);// ���� 
	}
	return head;
}

ListNode* delete_last(ListNode* head)
{
	ListNode* removed = head;
	ListNode* p = head; // p �� �������� ã�� 

	if (head == NULL) {
		printf("����Ʈ�� ��� ������ ����\n");
		return NULL;
	}
	else if (head == head->link) { //�ϳ��� ��尡 ��������
		head = NULL;
		//head->link = head // head�� null �̶� �Ƚᵵ �Ǵ� �� 
		free(removed);
	}
	else {
		while (p->link != head) // head �ٷ� ������ ã�� 
			p = p->link;
		p->link = removed->link; // �����갡 ����Ű���� p �� ����Ų�� 
		head = p; // ����� �̵� !! 
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

	p = head->link; // ó�������� ������ -> size = 0
	do {
		size++; // size ���� ���� �Ѵ� (�̻� ����)
		p = p->link;
	} while (p != head->link); // head ���� ������ؼ� head->link ������ / p �� �ٽ� ������ ���ƿö����� 

	return size;
}

//���� ���� ����Ʈ �׽�Ʈ ���α׷�
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

	//������ʹ� ���Ƿ� �� �κ�
	head = delete_last(head);
	print_list(head);
	printf("list�� ���̴� %d\n", get_size(head));

	return 0;
}