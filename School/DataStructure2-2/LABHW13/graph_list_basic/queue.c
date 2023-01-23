#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

QueueType* createQueue()
{
	QueueType* newQueue = (QueueType*)malloc(sizeof(QueueType));
	newQueue->front = -1;
	newQueue->rear = -1;
	return newQueue;
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
	return ((q->rear + 1) % SIZE == q->front); // rear + 1 �Ѱſ� max ���� �ذ� ( �ִ� �Ѿ�°� ����) == ����Ʈ
}

void enqueue(QueueType* q, int data)
{
	if (is_full(q)) // full 
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % SIZE; // rear �ϳ� ���� ����  
	q->queue[q->rear] = data; // item �� �ø� rear �ڸ��� �־��ش� 
}

int dequeue(QueueType* q)
{
	if (is_empty(q)) // ����ִ��� Ȯ���ϱ� 
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % SIZE; // front �� �÷��ش� %max 
	return q->queue[q->front]; // �ø� front �ڸ��� �ִ� ���� return 
}