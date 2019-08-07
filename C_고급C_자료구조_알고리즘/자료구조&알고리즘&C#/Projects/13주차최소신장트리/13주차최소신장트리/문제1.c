#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct ListNode {
	int name;
	struct ListNode *link;
}ListNode;

typedef struct Vertex {
	int d;
	int p;
	int name;
	ListNode *inc;
}Vertex;

typedef struct Edges {
	int end1, end2;
	int w;
}Edges;

typedef struct Graph {
	Vertex *v;
	Edges *e;
}Graph;

typedef struct Queue {
	int key;
	int ver;
}Queue;

typedef struct QueueType {
	Queue *v;
	int rear;
	int front;
}QueueType;

int N, M, cnt;
int *L;
int rear;
Graph g;
ListNode *head;
QueueType Q;

void makeGraph() {
	int i;

	g.v = (Vertex*)malloc(sizeof(Vertex)*N);
	g.e = (Edges*)malloc(sizeof(Edges)*M);
	head = (ListNode*)malloc(sizeof(ListNode)*N);

	for (i = 0; i < N; i++) {
		g.v[i].name = i + 1;
		head[i].name = NULL;
		head[i].link = NULL;
		g.v[i].inc = head + i;
	}

	cnt = 0;
}

ListNode* getNode(int ind) {
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
	p->name = ind;
	p->link = NULL;
	return p;
}


void insertEdge(int v, int w, int o) {
	ListNode *pa = g.v[v - 1].inc;
	ListNode *pb = g.v[w - 1].inc;

	//���� �߰�
	g.e[cnt].end1 = v - 1;
	g.e[cnt].end2 = w - 1;
	g.e[cnt].w = o;

	//��������Ʈ �߰�
	while (pa->link != NULL) {
		pa = pa->link;
	}
	pa->link = getNode(cnt);

	while (pb->link != NULL) {
		pb = pb->link;
	}
	pb->link = getNode(cnt);
	//���� �ε��� +1
	cnt++;
}

void swap(int a, int b) {
	Queue temp;
	temp = Q.v[a];
	Q.v[a] = Q.v[b];
	Q.v[b] = temp;
}

void downHeap(int i) {
	int left = i * 2;
	int right = i * 2 + 1;
	int greater;

	if (left > Q.rear) return;
	greater = left;

	if (right <= Q.rear) {
		if (Q.v[right].key > Q.v[greater].key) {
			greater = right;
		}
	}

	if (Q.v[i].key >= Q.v[greater].key)return;

	swap(i, greater);
	downHeap(greater);
}

void buildHeap(int i) {
	if (i > Q.rear) {
		return;
	}
	buildHeap(2 * i);
	buildHeap(2 * i + 1);
	downHeap(i);
}

void enqueue(int i) {
	Q.rear++;
	Q.v[Q.rear].ver = i;
	//printf("!!%d!!", Q.v[Q.rear].ver);
	Q.v[Q.rear].key = INT_MAX;
}

void makeQueue() {
	int i;
	ListNode *p = g.v[0].inc;

	Q.v = (Queue*)malloc(sizeof(Queue)*(N + 1));
	Q.rear = 0;
	Q.front = 0;

	for (i = 0; i < N; i++) {
		enqueue(i);
	}

	buildHeap(1);
}

int isEmpty() {
	if (Q.front == Q.rear) return 1;
	else return 0;
}

int removeMin() {
	int i;
	int sav;

	sav = Q.v[1].ver;// ������ vertex ����
	Q.v[1] = Q.v[Q.rear];
	Q.rear--;

	downHeap(1);//�ٿ���	

	return sav;
}

int opposite(int u, int e) {
	if (g.e[e].end1 == u) return g.e[e].end2;
	else if (g.e[e].end2 == u) return g.e[e].end1;
}//O

int findQueue(int v) {
	int i;

	for (i = 1; i <= Q.rear; i++) {
		if (Q.v[i].ver == v) return 1;
	}
	return 0;
}//O

void replaceKey(int z, int e) {
	int i;
	int sav;

	//inc�� �ش��ϴ� Q�� �� ���� ���ص��� �ֳĸ� �� removeMin �Ҷ� ����� ������ �ϰ� ������ �̾���

	for (i = 1; i <= Q.rear; i++) {
		if (Q.v[i].ver == z) {
			Q.v[i].key = e;
			downHeap(1);
		}
	}

}

void PrimJarnikMST() {
	int i;
	int s = 0;
	int z;
	int u;
	int sum = 0;
	ListNode *p;

	for (i = 0; i < N; i++) {
		g.v[i].d = INT_MAX;
		g.v[i].p = NULL;
	}

	makeQueue();

	g.v[s].d = 0;//s�� ���� 0���� ����

				 //�и� ver�� 2��� �ߴµ� ������ 0�ϰ� �Ǿ�����
	while (!isEmpty()) {
		u = removeMin();
		printf(" %d", g.v[u].name);
		sum += g.v[u].d;
		p = g.v[u].inc->link;
		while (p != NULL) {
			z = opposite(u, p->name);
			if (findQueue(z) && (g.e[p->name].w < g.v[z].d)) {
				g.v[z].d = g.e[p->name].w;
				g.v[z].p = p->name;
				replaceKey(z, g.e[p->name].w);
			}
			p = p->link;
		}
	}
	printf("\n%d", sum);
}

void main() {
	//��������Ʈ�� �켱����ť ������ ������ �ؾߵ�

	int i;
	int v, w, o; //����, ����, ����ġ

	scanf("%d %d", &N, &M);

	makeGraph();

	for (i = 0; i < M; i++) {

		scanf("%d %d %d", &v, &w, &o);
		insertEdge(v, w, o);
	}

	PrimJarnikMST();
}