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

//간선 삭제 연산
void delete_edge(GraphType* g, int u, int v)
{
	GraphNode* node;
	GraphNode* remove;

	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}

	if (g->adj_list[u]->vertex == v) {
		g->adj_list[u] = g->adj_list[u]->link;
	}
	else {
		for (node = g->adj_list[u]; node->link != NULL; node = node->link) {
			if (node->link->vertex == v) {
				node->link = node->link->link;
				break;
			}
		}
	}

	if (g->adj_list[v]->vertex == u) {
		g->adj_list[v] = g->adj_list[v]->link;
	}
	else {
		for (node = g->adj_list[v]; node->link != NULL; node = node->link) {
			if (node->link->vertex == u) {
				node->link = node->link->link;
				break;
			}
		}
	}
}

void print_graph(GraphType* g)
{
	GraphNode* node;

	for (int i = 0; i < g->n; i++) {
		printf("정점 %d의 인접리스트 ", i);
		for (node = g->adj_list[i]; node != NULL; node = node->link) {
			printf(" -> %d", node->vertex);
		}
		printf("\n");
	}
	printf("\n");
}

int main(void)
{
	int num;
	char key;
	int u, v;

	printf("그래프(인접리스트)\n");
	printf("정점 수 입력 : ");
	scanf("%d", &num);
	printf("\n");

	GraphType g;
	graph_init(&g);
	for (int k = 0; k < num; k++)
		insert_vertex(&g, k);

	printf("간선삽입(i), 간선삭제(d), 종료(q): ");
	scanf(" %c", &key);

	while (key != 'q') {
		switch (key) {
		case 'i':
			printf("간선삽입(u, v): ");
			scanf("%d, %d", &u, &v);
			insert_edge(&g, u, v);
			break;
		case 'd':
			printf("간선삭제(u, v): ");
			scanf("%d, %d", &u, &v);
			delete_edge(&g, u, v);
			break;
		}
		print_graph(&g);
		printf("간선삽입(i), 간선삭제(d), 종료(q): ");
		scanf(" %c", &key);
	}

}