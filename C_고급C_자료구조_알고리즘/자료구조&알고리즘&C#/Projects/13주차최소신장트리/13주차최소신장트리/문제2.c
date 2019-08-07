#include <stdio.h>
#include <stdlib.h>

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
	int edg;
	int w;
}Queue;

int N, M, cnt;
int *T;
int rear;
Graph g;
ListNode *head;
Queue *Q;


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
	temp = Q[a];
	Q[a] = Q[b];
	Q[b] = temp;
}

void downHeap(int i) {
	int left = i * 2;
	int right = i * 2 + 1;
	int greater = left;

	if (left > rear) {
		return;
	}

	if (right <= rear) {
		if (Q[right].w < Q[greater].w) {
			greater = right;
		}
	}

	if (Q[i].w <= Q[greater].w)return;

	swap(i, greater);
	downHeap(greater);
}

void buildHeap(int i) {
	if (i > rear) {
		return;
	}
	buildHeap(2 * i);
	buildHeap(2 * i + 1);
	downHeap(i);
}

void enqueue(int i) {
	rear++;
	Q[rear].edg = i;
	Q[rear].w = g.e[i].w;
}

void makeQueue() {
	int i;
	ListNode *p = g.v[0].inc;

	Q = (Queue*)malloc(sizeof(Queue)*(M+1));
	rear = 0;

	for (i = 0; i < M; i++) {
		enqueue(i);
	}
	
	buildHeap(1);

}

int isEmpty() {
	if (rear == 0) return 1;
	else return 0;
}//����ִ� ���� -1�� �ʱ�ȭ

int removeMin() {
	int i;
	int sav;

	sav = Q[1].edg;

	Q[1] = Q[rear];
	Q[rear].edg = -1;

	downHeap(1);

	if (Q[rear].edg == -1) {
		rear--;
	}

	return sav;
}

void unnion(int *D, int u, int v) {
	int i;
	int ucnt = 0, vcnt = 0;
	int su = D[u];
	int sv = D[v];

	for (i = 0; i<N; i++) {
		if (D[i] == D[u]) ucnt++;
		else if (D[i] == D[v]) vcnt++;
	}

	if (ucnt<vcnt) {
		for (i = 0; i<N; i++) {
			if (D[i] == su) D[i] = sv;
		}
	}
	else if(ucnt>=vcnt) {//ucnt>=vcnt
		for (i = 0; i<N; i++) {
			if (D[i] == sv) D[i] = su;
		}
	}
}

int* KruskalMSTDisjoinSets() {
	//����ũ���� �迭 D���� �������� �ε��� ����
	int *D, *T;
	int i, u, v, sav, cnt = 0,sum=0;

	D = (int*)malloc(sizeof(int)*N);
	T = (int*)malloc(sizeof(int)*N);

	for (i = 0; i<N; i++) {
		D[i] = i;
	}

	makeQueue();

	while (!isEmpty()) {
		//�ش� �ε��� ��ȯ
		sav = removeMin();
		u = g.e[sav].end1;
		v = g.e[sav].end2;	
		//printf("\n%d %d\n", u, v);

		//D�� �ε����� ������
		//28���� ��� ���� �夿����� �׷��� �ᱹ�� ���� ���ǹ��� �ɸ��� �ʴ´ٴ� �Ҹ�
		if (D[u] != D[v]) {
			T[cnt++] = sav;
			printf(" %d", g.e[sav].w);
			sum += g.e[sav].w;
			unnion(D, u, v);
		}
	}
	printf("\n%d", sum);
	return T;

}


void main() {

	int i;
	int v, w, o; //����, ����, ����ġ
	int *T;

	scanf("%d %d", &N, &M);

	makeGraph();

	for (i = 0; i < M; i++) {
		scanf("%d %d %d", &v, &w, &o);
		insertEdge(v, w, o);
	}

	T = KruskalMSTDisjoinSets();


}