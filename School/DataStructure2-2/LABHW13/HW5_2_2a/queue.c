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
	q->front = q->rear = 0; // 원형큐는 0으로 초기화 , 선형은 -1 
}

int is_empty(QueueType* q)
{
	return (q->front == q->rear); // 같으면 empty ! 
}

int is_full(QueueType* q) // 원형은 1개 차이가 날 때 full 
{
	return ((q->rear + 1) % SIZE == q->front); // rear + 1 한거에 max 나눠 준거 ( 최대 넘어가는거 방지) == 프론트
}

void enqueue(QueueType* q, int data)
{
	if (is_full(q)) // full 
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % SIZE; // rear 하나 증가 먼저  
	q->queue[q->rear] = data; // item 을 늘린 rear 자리에 넣어준다 
}

int dequeue(QueueType* q)
{
	if (is_empty(q)) // 비어있는지 확인하기 
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % SIZE; // front 를 늘려준다 %max 
	return q->queue[q->front]; // 늘린 front 자리에 있는 것을 return 
}