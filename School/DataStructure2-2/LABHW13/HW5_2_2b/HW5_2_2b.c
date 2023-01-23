#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#define MAX_VERTICES 50
#define TRUE 1;
#define FALSE 0;

int visited[MAX_VERTICES];

typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
	int n;
	GraphNode* adj_list[MAX_VERTICES];
} GraphType;

void graph_init(GraphType* g)
{
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
}

void insert_vertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int u, int v)
{
	GraphNode* node;
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}

	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;

	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = u;
	node->link = g->adj_list[v];
	g->adj_list[v] = node;
}

void bfs_list(GraphType* g, int v) // 너비 우선 탐색(인접 리스트)
{
	GraphNode* w;
	QueueType q;
	init(&q); // 큐 초기 화
	visited[v] = TRUE; // 정점 v 방문 표시
	enqueue(&q, v); // 시작정점을 큐에 저장

	while (!is_empty(&q)) {
		v = dequeue(&q); // 큐에 저장된 정점 선택
		for (w = g->adj_list[v]; w; w = w->link) //인접 정점 탐색
			if (!visited[w->vertex]) { // 미방문 정점 탐색
				visited[w->vertex] = TRUE; // 방문 표시
				printf("<%d %d>\n", v, w->vertex);
				enqueue(&q, w->vertex); //정점을 큐에 삽입
			}
	}
}

int main(void)
{
	int num;

	printf("Enter 정점:");
	scanf("%d", &num);

	GraphType g;
	graph_init(&g);
	for (int k = 0; k < 5; k++)
		insert_vertex(&g, k);

	insert_edge(&g, 0, 1);
	insert_edge(&g, 0, 2);
	insert_edge(&g, 0, 4);
	insert_edge(&g, 1, 2);
	insert_edge(&g, 2, 3);
	insert_edge(&g, 2, 4);
	insert_edge(&g, 3, 4);

	bfs_list(&g, num);
}