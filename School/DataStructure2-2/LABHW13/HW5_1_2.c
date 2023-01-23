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

//���� ���� ����
void delete_edge(GraphType* g, int u, int v)
{
	GraphNode* node;
	GraphNode* remove;

	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "�׷���: ���� ��ȣ ����");
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
		printf("���� %d�� ��������Ʈ ", i);
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

	printf("�׷���(��������Ʈ)\n");
	printf("���� �� �Է� : ");
	scanf("%d", &num);
	printf("\n");

	GraphType g;
	graph_init(&g);
	for (int k = 0; k < num; k++)
		insert_vertex(&g, k);

	printf("��������(i), ��������(d), ����(q): ");
	scanf(" %c", &key);

	while (key != 'q') {
		switch (key) {
		case 'i':
			printf("��������(u, v): ");
			scanf("%d, %d", &u, &v);
			insert_edge(&g, u, v);
			break;
		case 'd':
			printf("��������(u, v): ");
			scanf("%d, %d", &u, &v);
			delete_edge(&g, u, v);
			break;
		}
		print_graph(&g);
		printf("��������(i), ��������(d), ����(q): ");
		scanf(" %c", &key);
	}

}