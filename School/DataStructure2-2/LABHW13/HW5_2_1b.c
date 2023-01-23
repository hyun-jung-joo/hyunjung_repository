#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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
		fprintf(stderr, "�׷���: ������ ���� �ʰ�");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int u, int v)
{
	GraphNode* node;
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "�׷���: ���� ��ȣ ����");
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

void dfs_list(GraphType* g, int v) 
{
	GraphNode* w;
	visited[v] = TRUE; 

	for (w = g->adj_list[v]; w != NULL; w = w->link)
		if (!visited[w->vertex]) {
			printf("<%d, %d>\n", v, w->vertex);
			dfs_list(g, w->vertex);
		}
}

int main(void)
{
	int num;

	printf("Enter ����:");
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

	dfs_list(&g, num);
}