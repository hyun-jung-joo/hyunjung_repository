#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode { //���Ÿ��
	element data;
	struct ListNode* link;
} ListNode;

//���� ó�� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1); // ���α׷� ��ü�� ����
}

//��� pre �ڿ� ���ο� ��� ���� - �ð��� ���⵵ O(1)
ListNode* insert_next(ListNode* head, ListNode* pre, element value) // insert ,pre = preview(���� node)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //(1) ���ο�� �Ҵ� �Ѵ� 

	p->data = value; //(2)
	p->link = pre->link; //(3) ������ link �� p���� ���� ��Ŵ
	pre->link = p; //(4) pre ���� p �� ����
	return head; //(5) ����� ��� ������ ��ȯ
}

//�ð��� ���⵵ O(1)
ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //(1)
	p->data = value; // (2)
	p->link = head; //����������� ���� ���� / �Ǿ��̴ϱ�				
	//(3)
	head = p; //��� �����ͺ���

	//(4)
	return head; // ����� ��� ������ ��ȯ
}

//�ð��� ���⵵ O(n) 
ListNode* insert_last(ListNode* head, int value)
{
	ListNode* temp = head; // �̻縦 �ٴϴ� ���� temp -> ������ �ڸ� ã��
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //(1)
	p->data = value;
	p->link = NULL; // �������̴ϱ� null 
	// (2)
	if (head == NULL) //���� ����Ʈ�̸�
		head = p; // head �� p ��
	else {
		while (temp->link != NULL) // temp->link null �϶�����
			temp = temp->link;

		temp->link = p;
	}
	return head; //����� ��� ������ ��ȯ
}

//������ return �� ���� 
// �����Ѵ� -> memory ���� ���� ��Ų��(free (��� : removed ���)��Ų��)

// pre�� ����Ű�� ����� ���� ��带 �����Ѵ�. - �ð��� ���⵵ O(1)
ListNode* delete_next(ListNode* head, ListNode* pre)
{
	ListNode* removed;

	removed = pre->link; // ��(pre)�� ���� link�� ����Ŵ
	pre->link = removed->link; // (2) ���� ���� removed �� ����Ű�� �ִ� link �� ���� (removed �����׸� ����)
	free(removed); // (3) removed ����
	return head; // (4) ����� ��� ������ ��ȯ
}

//�� �տ� �� ����,  �ð��� ���⵵ O(1) 
ListNode* delete_first(ListNode* head)
{
	ListNode* removed;

	if (head == NULL) error("������ �׸��� ����");

	removed = head; // (1) head�� ���� -> head�� ����Ű�� ���� 
	head = removed->link; // (2) ������ ���� link �� ������ removed�� �������� ����(link)�� ������->��� �̵� 
	free(removed); // (3) �� ������ѵ����� -> removed �� ����
	return head; // (4) ����� ��� ������ ��ȯ
}

//�������� �����ϱ� ->  �ð��� ���⵵ O(n)
ListNode* delete_last(ListNode* head)
{
	ListNode* temp = head;
	ListNode* prevTemp; // temp �� ���󰡴� ���� 
	ListNode* removed;

	if (head == NULL) error("������ �׸��� ����");
	if (temp->link == NULL) { //�ϳ��� ��� -> ������ ����� head
		removed = temp->link; // head�Ÿ� removed�� ����
		temp->link = NULL; // temp �� null �� 
		free(removed); // ����

		return NULL; // null �� return
	}
	else { // �� �̻��� ���
		while (temp->link != NULL) { // null �� �ƴϸ� temp �� ��� �ڷ� �̵�(�̻�) -> �������� ã��
			prevTemp = temp; // temp �� �ٷ� �� ->  preTemp �� ���� ���󰣴�. -> temp �� ���� ���� 
			temp = temp->link; // temp �� �����Ÿ� ����Ų�� 
		}
		// while���� ���������� 
		removed = temp;
		prevTemp->link = NULL; // �������� ���� ������ null �� ! -> ������ ���ֹ�����.
		free(removed); // ����
		return head; //�״�� 
	}
}

void print_list(ListNode* head)
{
	ListNode* p;
	for (p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

ListNode* search(ListNode* head, int x) // x �� �ִ��� ã�� 
{
	ListNode* p;
	p = head; // p �� temp �� ����� ���� �Ѵ�

	while (p != NULL) { // p�� null �� �ƴϸ� �ݺ�, null�� ������ ������ (link �� null �� ������ ���� ������ ���� ���ϰ� ���� -> node �� null �� �������� !) 
		if (p->data == x) return p; // Ž�� ���� : x �� p->data ������ ���ο� ����
		p = p->link; // p �� �������� �̻� 
	}
	return NULL; // Ž�� ������ ��� NULL ��ȯ
}

ListNode* concat(ListNode* head1, ListNode* head2) // �� ���� ����Ʈ�� �ձ� -> head1 �ڿ� head2�� �̾��ش�.
{
	ListNode* p;
	if (head1 == NULL) return head2; // head1�� �ƹ��͵� ������ head2 �� ����
	else if (head2 == NULL) return head1; // ���� �ݴ� ��� 
	else { // �� �� null �� �ƴϸ�
		p = head1;
		while (p->link != NULL) // p�� �̵� -> data �� �̿��ϴ°� �ƴϹǷ� p->link �� null �� ���� ! �������� ã�� ! 
			p = p->link; // p�� �������� �̻�
		p->link = head2; // ���������� head2�� ����
		return head1; // �տ����� return
	}
}

ListNode* reverse(ListNode* head) // �������� �����
{
	// ��ȸ �����ͷ� p, q, r�� ���
	ListNode *p, *q, *r;
	p = head; // p�� �������� ���� ����Ʈ(���� ����Ʈ)
	q = NULL; // q�� �������� ���� ���
	while (p != NULL) { // p(���� ����Ʈ)�� null �� �ƴҶ����� -> �������������� ������ , ������ �������� �����
		r = q; // r�� �������� �� ����Ʈ. r�� q, q�� p�� ���ʷ� ���󰣴�. 
		q = p; // q�� p ���� ����
		p = p->link; // p �� �������� �̵�
		q->link = r; // q�� ��ũ ������ �ٲ۴�. 
	}
	
	return q; // q�� �������� �� ����Ʈ�� ��� ������
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