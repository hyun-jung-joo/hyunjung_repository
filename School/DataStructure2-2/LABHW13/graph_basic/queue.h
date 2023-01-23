#include <stdio.h>
#define SIZE 50
typedef struct QueueType {
    int queue[SIZE];
    int front;
    int rear;
}QueueType;

QueueType* createQueue();
void init(QueueType *q);
void enqueue(QueueType* q, int data);
int dequeue(QueueType* q);
int is_empty(QueueType* q);
int is_full(QueueType* q);