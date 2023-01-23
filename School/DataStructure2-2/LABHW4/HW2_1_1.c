#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_QUEUE_SIZE 3 // max = 3 ���� ���� 

typedef struct { 
	char name[100]; // �̸� -> �迭�� 
	char gender; // ���� 
} element; // element Ÿ�� ! 

typedef struct {
	element queue[MAX_QUEUE_SIZE]; // element Ÿ�� ť 
	int front, rear;
} QueueType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(QueueType* q)
{
	q->front = q->rear = 0; // ����ť�� 0���� �ʱ�ȭ , ������ -1 
}

int is_empty(QueueType* q)
{
	return (q->front == q->rear); // ������ empty ! 
}

int is_full(QueueType* q) // ������ 1�� ���̰� �� �� full 
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front); // rear + 1 �Ѱſ� max ���� �ذ� ( �ִ� �Ѿ�°� ����) == ����Ʈ
}

void enqueue(QueueType* q, element item) 
{
	if (is_full(q)) // full 
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; // rear �ϳ� ���� ����  
	q->queue[q->rear] = item; // item �� �ø� rear �ڸ��� �־��ش� 
}

element dequeue(QueueType* q)
{
	if (is_empty(q)) // ����ִ��� Ȯ���ϱ� 
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE; // front �� �÷��ش� %max 
	return q->queue[q->front]; // �ø� front �ڸ��� �ִ� ���� return 
}


element peek(QueueType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	return q->queue[(q->front + 1) % MAX_QUEUE_SIZE]; // front + 1 %max �Ѱſ� ���� return 
}

void print_queue(QueueType* q)
{
	if (!is_empty(q)) {
		int i = q->front; // i �� front ������ 
		do {
			i = (i + 1) % MAX_QUEUE_SIZE; // i + 1 �ϸ鼭 ��� max ������ ������ i �� 
			printf("%s ", q->queue[i].name); // .name ( ��� ������ - �����Ͱ� �ƴ�) 
			//if (i == q->rear)
				//break;
		} while (i != q->rear); // ���⸦ rear �� ! -> rear ���� �о��� do while �̴ϱ� ->  �� ������ ������ (���� ����) 
	}
	printf("\n");
}

// �� �κ� ����! 
int get_count(QueueType* q) 
{
	if (q->rear < q->front) // front �� rear ���� ũ�ٸ�(rear �� �ѹ��� ����) ! �� �տ� ���� ���� ���� -> ������ ���� �� ���� �̸� �����ؾ���
		return (q->rear + MAX_QUEUE_SIZE - q->front); // rear + max �Ѱſ��� front �� ������� -> ���� ����
	else
		return (q->rear - q->front); // �װ� �ƴϸ� rear���� front�� ���ش� (rear > front) 
}

//�Լ��� �����ֱ� ! 
void check(QueueType* q, QueueType* p, element item) // q �� ���� ������ ť, p�� ���� ť 
{
	if (is_full(q)) // �� á�� (���� ���� ť��) -> ��Ī�� �ȵȴ�. 
		printf("���� ����ڰ� �����ϴ�. ����ڰ� ��á���� ���ȸ�� �̿�\n");
	else { // �ڽ� ���� ť�� �ڸ��� ������ 
		if (is_empty(p)) { // ������ empty �̸� -> ��� : enqueue �ȴ� 
			printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�.\n"); // ��� 
			enqueue(q, item); // enqueue �ڽ� ���� ť��  
		}
		else { // ������ ������ -> ��Ī ��밡 ����
			enqueue(q, item); // �켱 enqueue �� �ϰ� ! �ڽ� ���� ť�� 
			printf("Ŀ���� ź���߽��ϴ�! %s�� %s\n", dequeue(q).name, dequeue(p).name); //  2 ������ dequeue !  - ���� ���� , ���� ���� 
		}
	}
}

void main()
{
	QueueType manQ;
	QueueType womanQ;
	element newPerson;
	char key;

	//�Ѵ� �ʱ�ȭ 
	init(&manQ);
	init(&womanQ);
	printf("���� �ּ� ���α׷��Դϴ�.\n");
	//do while �� �켱 �����ϰԲ�
	do {
		printf("i<nsert, ���Է�>, c<heck, ����� üũ>, q<uit>:");
		scanf(" %c", &key); // space�� ���� ����

		switch (key) {
		case 'i': // insert
			printf("�̸��� �Է�: ");
			scanf("%s", newPerson.name);
			//while(getchar() != '\n');
			printf("������ �Է�<m or f>: ");
			scanf(" %c", &newPerson.gender); // space�� ���� ����ֱ�


			//�̷��� �Ȱ��� �κ��� �Լ��� ����� ���� ���� ! -> check �Լ��� + ��Ī�� ����
			if (newPerson.gender == 'm') // ���ڸ�
				check(&manQ, &womanQ, newPerson); // manQ���� 
			else
				check(&womanQ, &manQ, newPerson); // woman
			break;

		case 'c':
			printf("���� ����� %d��: ", get_count(&manQ));
			print_queue(&manQ);
			printf("���� ����� %d��: ", get_count(&womanQ));
			print_queue(&womanQ);
			break;
		}
		//while(getchar() != '\n');
	} while (key != 'q');
}

