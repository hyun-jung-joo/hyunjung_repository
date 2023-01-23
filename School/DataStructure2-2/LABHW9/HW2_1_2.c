#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

typedef struct {
	char name[100]; // �̸� -> �迭�� 
	char gender; // ����  -> ���� �ʿ����� ���� .. !
} element; // element Ÿ�� ! 

typedef struct QueueNode { 
	element data;
	struct QueueNode* link;
} QueueNode;

typedef struct { 
	QueueNode* front, * rear;
} LinkedQueueType;

void init(LinkedQueueType* q)
{
	q->front = q->rear = NULL;
}

int is_empty(LinkedQueueType* q)
{
	return (q->front == NULL);
}

int is_full(LinkedQueueType* q) 
{
	return 0;
}

void enqueue(LinkedQueueType* q, element item)
{
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	if (temp == NULL)
		printf("�޸𸮸� �Ҵ��� �� �����ϴ�");
	else {
		temp->data = item; 
		temp->link = NULL; 
		if (is_empty(q)) { 
			q->front = temp;
			q->rear = temp;
		}
		else { 
			q->rear->link = temp; 
			q->rear = temp;
		}
	}
}

element dequeue(LinkedQueueType* q)
{
	QueueNode* temp = q->front;
	element item;
	if (is_empty(q)) 
		printf("ť�� ��� �����ϴ�");
	else {
		item = temp->data; 
		q->front = q->front->link; 
		if (q->front == NULL) 
			q->rear = NULL;
		free(temp);
		return item; 
	}
}

void print_queue(LinkedQueueType* q)
{
	QueueNode* p;

	if (!is_empty(q)) {
		for (p = q->front; p != NULL; p = p->link)
			printf("%s ", p->data.name);
	}
	printf("\n"); 
}

int get_count(LinkedQueueType* q)
{
	QueueNode* p;
	int count = 0;

	if (is_empty(q))
		return 0;
	else {
		for (p = q->front; p != NULL; p = p->link)
			count++;
		return count;
	}
}

void check(LinkedQueueType* q, LinkedQueueType* p, element item) 
{
	if (is_full(q)) 
		printf("���� ����ڰ� �����ϴ�. ����ڰ� ��á���� ���ȸ�� �̿�\n");
	else { 
		if (is_empty(p)) { 
			printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�.\n"); 
			enqueue(q, item); 
		}
		else { 
			enqueue(q, item); 
			printf("Ŀ���� ź���߽��ϴ�! %s�� %s\n", dequeue(q).name, dequeue(p).name); 
		}
	}
}

void main()
{
	LinkedQueueType manQ;
	LinkedQueueType womanQ;
	element newPerson;
	char key;
 
	init(&manQ);
	init(&womanQ);
	printf("���� �ּ� ���α׷��Դϴ�.\n");
	
	do {
		printf("i<nsert, ���Է�>, c<heck, ����� üũ>, q<uit>:");
		scanf(" %c", &key); 

		switch (key) {
			case 'i': 
				printf("�̸��� �Է�: ");
				scanf("%s", newPerson.name);
			
				printf("������ �Է�<m or f>: ");
				scanf(" %c", &newPerson.gender); 
			
				if (newPerson.gender == 'm') 
					check(&manQ, &womanQ, newPerson); 
				else
					check(&womanQ, &manQ, newPerson); 
				break;

			case 'c':
				printf("���� ����� %d�� ", get_count(&manQ));
				print_queue(&manQ);
				printf("���� ����� %d�� ", get_count(&womanQ));
				print_queue(&womanQ);
				break;
		}
	} while (key != 'q');
}