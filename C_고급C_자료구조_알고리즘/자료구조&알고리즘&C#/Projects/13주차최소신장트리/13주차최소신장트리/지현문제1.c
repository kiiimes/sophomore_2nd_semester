#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)
#define INIF 999999

typedef struct HEAP {
	int index;
	int key;
}HEAP;

typedef struct Graph {
	struct Vertices * vertice;
	struct Edges * edge;
}Graph;

typedef struct Vertices {
	int index;
	struct Head * head;
	int distance;
	struct Node * parent;
}Vertices;

typedef struct Head {
	struct Node * head;
}Head;

typedef struct Node {
	struct Node * link;
	int EdgeNode;
}Node;

typedef struct Edges {
	int weight;
	int vert_s, vert_e;
}Edges;

//================================

Vertices vertices[100];
Edges edges[1000];
Graph G;
int n, m;
HEAP *Heap;
int Hcnt = 1;
int sum = 0;

//================================

void arraySwap(int n1, int n2) {
	HEAP temp; // �ӽ÷� ���� ������ ����

	temp = Heap[n1];
	Heap[n1] = Heap[n2];
	Heap[n2] = temp;
	// A[n1]�� ���� A[n2]�� ���� swap�Ѵ�
}

void downHeap(int i) {//�����̵�(remove�� ���)
	int bigger;
	int left = 2 * i;
	int right = 2 * i + 1;
	int parent = i;
	HEAP tmp;

	if (left > Hcnt)
		return;

	if (Heap[left].key <= Heap[right].key)
		bigger = left;
	else
		bigger = right;

	while (1) {
		if (parent * 2 > Hcnt)
			break;

		if (Heap[parent].key < Heap[bigger].key)
			break;
		else {
			arraySwap(parent, bigger);
			parent = bigger;
		}

		left = 2 * parent;
		right = left + 1;
		if (Heap[left].key <= Heap[right].key)
			bigger = left;
		else
			bigger = right;
	}
}

void buildHeap() {
	int i;
	Heap = (HEAP*)malloc(sizeof(HEAP)*(n + 1));
	Hcnt = n;
	for (i = 1; i <= n; i++) {
		Heap[i].index = vertices[i - 1].index;
		Heap[i].key = vertices[i - 1].distance;
	}
	for (i = Hcnt / 2; i >= 1; i--)
		downHeap(i);
}


int removeMin() {
	int num, i;
	num = Heap[1].index;
	downHeap(1);
	return num;
}

void init_G() {
	int i;
	G.edge = edges;
	G.vertice = vertices;
	for (i = 0; i < n; i++) {
		G.vertice[i].index = i + 1;
		G.vertice[i].head = (Head *)malloc(sizeof(Head));
		G.vertice[i].head->head = NULL;
	}
}

void setVertices(int s) {
	vertices[s - 1].index = s;
}

void initEdge(int i, int s, int e, int w) {
	edges[i].vert_s = s;
	edges[i].vert_e = e;
	edges[i].weight = w;
}

Node * getNode() {
	Node * node;
	node = (Node *)malloc(sizeof(Node));
	node->link = NULL;
	return node;
}

void insert_Node(int loc, int i) { //loc�� vertices��ġ i�� edge��ġ
	Node * node;
	Head * tmp;

	node = getNode();
	node->EdgeNode = i;
	tmp = vertices[loc - 1].head;
	node->link = tmp->head;
	tmp->head = node;
}

void showGraph() {
	int i, num;
	Node * tmp;

	printf("\n=========showGraph============\n");
	for (i = 0; i < n; i++) {
		printf("vertices[%d] : ", i + 1);
		tmp = vertices[i].head->head;
		while (tmp != NULL) {
			num = tmp->EdgeNode;
			printf(" %d", num);
			tmp = tmp->link;
		}
		printf("\n");
	}
}

void replaceKey(int z, int k)
{
	//���� v�� Ű�� kŰ�� ������
	//v�� ������ ã�Ƽ� �� ���� Ű�� k�� �ٲ���ߴ�
	int i;

	for (i = 1; i <= Hcnt; i++)
	{
		if (Heap[i].index == z)
		{
			Heap[i].key = k;
			printf("!!!%d!!!", Heap[i].key);
			//checkH();
		}
	}

}

void init_Q() {
	int i;
	Heap = (HEAP *)malloc(sizeof(HEAP)*(n + 1));
	for (i = 1; i <= n; i++) {
		Heap[i].index = i;
		Heap[i].key = vertices[i - 1].distance;
	}
	Heap[1].key = 0;
	Hcnt = n;
}

int opposite(int u, Node *e) {
	return edges[e->EdgeNode].vert_s + edges[e->EdgeNode].vert_e - u;
}

int is_Exist(int num) {
	int i;
	for (i = 1; i <= Hcnt; i++) {
		if (Heap[i].index == num) {
			return 1;
		}
	}
	//printf("return 0\n");
	return 0;
}

int Weight(int u, int z) {
	int i;
	for (i = 0; i < m; i++) {
		if (edges[i].vert_s == u && edges[i].vert_e == z)
			return edges[i].weight;
		else if (edges[i].vert_s == z && edges[i].vert_e == u)
			return edges[i].weight;
	}
	return -1;
}

void checkH() {
	int i;
	for (i = 1; i <= n; i++) {
		printf("====%d====\nkey : %d   index : %d\n", i, Heap[i].key, Heap[i].index);
	}
}
void PrimJarnikMST() {
	int i;
	int z, u;
	Vertices *s;
	Node * tmp;
	for (i = 0; i < n; i++) {
		vertices[i].distance = INIF;
		vertices[i].parent = NULL;
	}

	s = vertices;
	s->distance = 0; // ó�� ���� d�� 0���� �ʱ�ȭ�Ѵ�.
	buildHeap();
	//checkH();
	//printf("after init\n");


	for (i = 0; i < n; i++) {
		u = Heap[1].index;
		printf(" %d", u);
		sum += vertices[u - 1].distance;
		//checkH();

		//printf("Hcnt = %d\n", Hcnt);

		Heap[1] = Heap[Hcnt];
		Hcnt--;
		downHeap(1);

		tmp = vertices[u - 1].head->head;

		while (tmp != NULL) {

			z = opposite(u, tmp); //�ݴ��� ���� �ε���
								  //printf("z = %d\n", z);
								  //printf("weight : %d\n", Weight(u, z));
			if (is_Exist(z) && Weight(u, z) < Heap[z].key) {
				//printf("exist!\n");

				vertices[z - 1].distance = Weight(u, z);
				//vertices[z - 1].parent = tmp;
				replaceKey(z, Weight(u, z));
				printf("weight : %d\n", vertices[z-1].distance);
				//checkH();

			}
			tmp = tmp->link;

		}
		//printf("\n\n\n");
	}
}


int main() {
	int i, num;
	int vert_s, vert_e, weight;
	Vertices * tmp;
	scanf("%d %d", &n, &m);
	init_G();
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &vert_s, &vert_e, &weight);
		setVertices(vert_s); // ��������
		setVertices(vert_e); // ��������
		initEdge(i, vert_s, vert_e, weight); // ����������ֱ�
		insert_Node(vert_s, i);
		insert_Node(vert_e, i);
	}

	//showGraph();

	PrimJarnikMST();
	printf("\n%d\n", sum);

}