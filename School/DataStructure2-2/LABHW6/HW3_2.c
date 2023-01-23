#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

//���� ó�� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//��� pre �ڿ� ���ο� ��� ���� 
ListNode* insert_next(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));

	p->data = value; 
	p->link = pre->link; // p�� �������� ����Ű���� ����Ŵ
	pre->link = p; // ������ p�� ����Ų��
	return head;
}

ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head; // p->link �� ��带 ����Ű��
	head = p;// ���� p �� �ȴ�

	return head;
}

//O(n)
ListNode* insert_last(ListNode* head, int value)
{
	ListNode* temp = head; // temp �� �̵����� �������� ã�´� 
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = NULL; // �������̴ϱ� null ���� ������ 

	if (head == NULL)
		head = p;
	else {
		while (temp->link != NULL) // temp->link �� ���϶����� (temp �� �������̸�)
			temp = temp->link; //���� �̵�

		temp->link = p; // ���� ��ũ�� �������� p�� �־��ش�
	}
	return head; // ����
}

// pre�� ����Ű�� ����� ���� ��带 �����Ѵ�.
ListNode* delete_next(ListNode* head, ListNode* pre) // ���� ��
{
	ListNode* removed;

	removed = pre->link; // ���� link = �ڽŲ� �������
	pre->link = removed->link; // ������ �������� ��ũ�� 
	free(removed); // ���� 

	return head;
}

//�� �տ� �� ����
ListNode* delete_first(ListNode* head)
{
	ListNode* removed;

	if (head == NULL) error("������ �׸��� ����");

	removed = head; // ��岨
	head = removed->link; // ���� ������ ������
	free(removed); // ����

	return head;
}

//�������� �����ϱ� O(n)
ListNode* delete_last(ListNode* head)
{
	ListNode *temp = head;
	ListNode* prevTemp = head; // prevTemp -> temp ����ٴ� (temp ���ǲ��� �����Ѵ�) 
	ListNode *removed;

	if (head == NULL) error("������ �׸��� ����");
	if (temp->link == NULL) { // �׸��� �Ѱ��϶� temp->link == NULL
		removed = temp->link; 
		temp->link = NULL;
		free(removed);

		return NULL;
	}
	else {
		while (temp->link != NULL) { // temp �� �������ŷ� ��
			prevTemp = temp; // prev�� temp�� ����ٴѴ�
			temp = temp->link; // ������ �̵�
		}


		//�������� ã���� , ������ ������ �� ��
		removed = temp;
		prevTemp->link = NULL; // �������� �η� �ٲ�
		free(removed); // �������� ����
		return head;
	}
}

void print_list(ListNode* head)
{
	ListNode* p;
	for (p = head; p != NULL; p = p->link) // p->head , p!= NULL(link �ƴ�) , p=p->link 
		printf("%d->", p->data);
	printf("NULL \n"); // �������� ��
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

ListNode* reverse(ListNode* head) // �������� �����
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

//item �� ����Ʈ�� ������ 1 �� �ƴϸ� 0 �� ��ȯ 
int is_in_list(ListNode* head, element item)
{
	ListNode* p;
	for (p = head; p != NULL; p = p->link) // p->link�ƴ� !! -> �̰� ������ ������ �� �ȵ�
		if (p->data == item)
			return 1;
	return 0;
}

//�ܼ� ���� ����Ʈ�� �����ϴ� ����� ���� ��ȯ
int get_length(ListNode* head)
{
	int count = 0;
	ListNode* p;

	for (p = head; p != NULL; p = p->link)
		count++;
	return count;
}

//�ܼ����Ḯ��Ʈ�� ��� ������ ���� ���� ���� ��ȯ
int get_total(ListNode* head)
{
	int total = 0;
	ListNode* p;

	for (p = head; p != NULL; p = p->link)
		total += p->data;
	return total;
}

//pos ��ġ(0 �� ù ��° ���)�� �ִ� ����� data �� ��ȯ
element get_entry(ListNode* head, int pos)
{
	ListNode* p = head;
	int i = 0;
	
	if (pos < 0 && pos >= get_length(head)) // pos ��ġ Ȯ�� ����
		return -1; // ����-> error �޼����� ǥ�� �ϴ°� �� ����
	else {
		for (i = 0; i < pos; i++) // pos ������ ������Ű��
			p = p->link;
		return p->data; // p�� p->link �̹Ƿ� pos �� �Ǿ��� 
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
	
	if (head == NULL) // �ϳ��� ����
		return NULL; // error
	while (p != NULL) { // p�� �ڷ� �̵����������� 
		if (p->data == key) // ã���� 
			return delete_pos(head, i); // i�� �Բ� pos �� �ѱ�
		p = p->link; // p �̵� 
		i++; //��ġ
	}

	printf("%d���� ���� ���� �������� �ʴ´�\n", key);
	return head;


	/*ListNode* p = head;
	ListNode* removed;
	ListNode* preKey = NULL; // ���� ���� ã�´� . �������� ���󰣴� 

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

//pos ��ġ�� value �� ���� ��带 �߰�
ListNode* insert_pos(ListNode* head, int pos, element value)
{
	ListNode* p = head;
	int i;

	if (pos == 0) // ó���ڸ��� 
		return insert_first(head, value);
	else { // �ƴϸ� 
		for (i = 0; i < pos - 1; i++) // pos �������� ! -> next �� �ѱ�
			p = p->link; // link �ϱ� �ϳ� �� ���Է� ����ؾ��� 
		return insert_next(head, p, value); // p�� pre ! 
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
	//		prevPos = p; // pre �� p �� �ֱ� -> ���󰣴� 
	//		p = p->link; // p ����
	//		index++; // ��ġ�� ������Ų�� 
	//	}
	//}

	//return head;
}

// pos ��ġ�� ��带 ����
ListNode* delete_pos(ListNode* head, int pos)
{
	ListNode* p = head;
	int i;

	if (head == NULL)
		return NULL; // error
	else if (pos == 0){ // 1�� 
		return delete_first(head);
	}
	else { //������
		for (i = 0; i < pos - 1; i++) // �������� ã�� 
			p = p->link;
		return delete_next(head, p); // pre�� p�� ������
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
	ListNode* list1 = NULL, * list2 = NULL, * list3; // ����� 

	//list1 = 30->20->10->�� �����. �̶� 10, 20, 30�� ������ ��带 �����Ѵ�. 
	list1 = insert_first(list1, 10);
	list1 = insert_first(list1, 20);
	list1 = insert_first(list1, 30);
	// list1�� ���
	printf("list1 = ");
	print_list(list1);

	//list1�� �� �� ��带 �����Ѵ� ��, list1 = 20->10->
	list1 = delete_first(list1);
	// list1�� ���
	printf("list1 = ");
	print_list(list1);

	//list2 = 11->22->33->44->�� �����. �̶� 11, 22, 33, 44�� ������ ��带 �����Ѵ�. 
	list2 = insert_last(list2, 11);
	list2 = insert_last(list2, 22);
	list2 = insert_last(list2, 33);
	list2 = insert_last(list2, 44);

	// list2�� ���
	printf("list2 = ");
	print_list(list2);

	// list2�� �� �� ��带 �����Ѵ�. ��, list2 = 11->22->33->
	list2 = delete_last(list2);

	// list2�� ���
	printf("list2 = ");
	print_list(list2);

	//list2�� �������� �ٲ� ����Ʈ�� list3�� ����Ű�� �Ѵ�. list3 = 33->22->11->�� �����.
	list3 = reverse(list2);

	//list3�� ����Ѵ�. 
	printf("list3 = ");
	print_list(list3);

	// list1 = 20->30->33->22->11->�� �����. ��, list1�� list3�� ���ļ� list1�� ����Ű�� �Ѵ�. 
	list1 = concat(list1, list3);

	//list1�� ����Ѵ�. 
	printf("list1 = ");
	print_list(list1);

	printf("\n");
	//(A) ����: ���⼭���ʹ� list1�� ����Ͽ� �Լ����� �׽�Ʈ����
	
	//list1 �� 33�� �ִ��� Ȯ��
	int is_in_key = 33;
	if(is_in_list(list1, is_in_key))
		printf("list1�� %d�� �ִ�.\n", is_in_key);
	else
		printf("list1�� %d�� ����.\n", is_in_key);

	//����Ʈ ��� �� ��ȯ
	printf("list1�� ���̴� %d �̴�.\n", get_length(list1));

	//��� ������ ���� ���� �� ��ȯ
	printf("list1�� ��� ������ ���� ���� %d�̴�.\n", get_total(list1));

	//key �� ����
	int delete_key = 33;
	list1 = delete_by_key(list1, delete_key);
	//list1�� ����Ѵ�. 
	printf("�����Ͱ� %d�� ���� �����ϸ� list1 = ", delete_key);
	print_list(list1);

	//pos ��ġ�� value�� ��� �߰�
	int insert_value = 40;
	int insert_poskey = 2;
	list1 = insert_pos(list1, insert_poskey, insert_value);
	//list1�� ����Ѵ�.
	printf("%d�� %d�ڸ��� �߰��ϸ� list1 = ", insert_value, insert_poskey);
	print_list(list1);

	//pos ��ġ ��� ����
	int delete_poskey = 1;
	list1 = delete_pos(list1, delete_poskey);
	//list1�� ����Ѵ�.
	printf("%d �ڸ� ��带 �����ϸ� list1 = ", delete_poskey);
	print_list(list1);
}