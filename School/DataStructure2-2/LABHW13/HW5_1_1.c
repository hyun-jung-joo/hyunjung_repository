#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50
#define TRUE 1;
#define FALSE 0;

int visited[MAX_VERTICES]; 

typedef struct GraphType {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

void graph_init(GraphType* g) 
{
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
}

void insert_vertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "�׷��� ������ ���� �ʰ�");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int start, int end)
{
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "�׷���: ���� ��ȣ ����");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}

//���� ���� ����
void delete_edge(GraphType* g, int start, int end)
{
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "�׷���: ���� ��ȣ ����");
		return;
	}
	g->adj_mat[start][end] = 0;
	g->adj_mat[end][start] = 0;
}

void print_graph(GraphType* g)
{
	printf("    v0 v1 v2 v3 v4  \n");
	printf("   -----------------\n");

	for (int i = 0; i < g->n; i++) {
		printf("v%d | ", i);
		for (int j = 0; j < g->n; j++) {
			printf("%d  ", g->adj_mat[i][j]);
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

	printf("�׷���(�������)\n");
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