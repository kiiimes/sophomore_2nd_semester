#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct ListNode {
	int num;
	struct ListNode *link;
}ListNode;

typedef struct Vertex {
	int name;
	int d;
	ListNode *inc;
}Vertex;

typedef struct Edges {
	int end1, end2;
	int w;
}Edges;

typedef struct Queue {
	int num;
	int key;
	struct Queue *llink;
	struct Queue *rlink;
}Queue;

typedef struct QueueType {
	Queue* front;
	Queue* rear;
}QueueType;

typedef struct Psort {
	int ver;
	int w;
}Psort;

int n, m, s;
int last;
int rear;
int cnt;

ListNode *head;
Vertex *v;
Edges *e;
QueueType *Q;
Psort *ps;

ListNode* getNode(int num) {
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
	p->num = num;
	p->link = NULL;
	return p;
}

Queue* getNodeQ(int num) {
	Queue *p = (Queue*)malloc(sizeof(Queue));
	p->num = num;
	p->llink = NULL;
	p->rlink = NULL;
	return p;
}

void makeGraph() {
	int i;

	v = (Vertex*)malloc(sizeof(Vertex)*n);
	e = (Edges*)malloc(sizeof(Edges)*m);
	head = (ListNode*)malloc(sizeof(ListNode)*n);
	ps = (Psort*)malloc(sizeof(Psort)*(n-1));

	for (i = 0; i < n; i++) {
		v[i].name = i + 1;
		head[i].num = NULL;
		head[i].link = NULL;
		v[i].inc = head + i;
	}

	cnt = 0;
	last = 0;
}

void insertEdges(int a, int b, int o) {
	ListNode *pa = v[a - 1].inc;
	ListNode *pb = v[b - 1].inc;

	//간선 추가
	e[last].end1 = a - 1;
	e[last].end2 = b - 1;
	e[last].w = o;

	//인접리스트 추가
	while (pa->link != NULL) {
		pa = pa->link;
	}
	pa->link = getNode(last);

	while (pb->link != NULL) {
		pb = pb->link;
	}
	pb->link = getNode(last);
	//간선 인덱스 +1
	last++;
}
void swap(Queue *a, Queue *b) {
	int temp;

	temp = a->num;
	a->num = b->num;
	b->num = temp;

	temp = a->key;
	a->key = b->key;
	b->key = temp;
}//swap이 병신

void inPlaceSelectionSort() {
	Queue* p=Q->front->rlink;
	Queue *min,*sav;
	

	while (p != Q->rear->llink->llink) {
		min = p;
		sav = p->rlink;
		while (sav != Q->rear->llink) {
			if (sav->key < min->key) 
				min = sav;
			sav = sav->rlink;
		}
		swap(min, p);
		p = p->rlink;
	}

}

int isEmpty() {
	if (Q->front->rlink == Q->rear) return 1;
	else return 0;
}//비어있는지 체크

void enqueue(int num,int key) {
	Queue *New = getNodeQ(num);
	New->key = key;
	
	New->llink = Q->rear->llink;
	New->rlink = Q->rear;
	Q->rear->llink->rlink = New;
	Q->rear->llink = New;
	
}
//enqueue 할때 Qu

int dequeue() {
	Queue *p = Q->front->rlink;
	
	p->rlink->llink = Q->front;
	Q->front->rlink = p->rlink;

	free(p);
}

void makeQueue() {
	int i;
	Q = (QueueType*)malloc(sizeof(QueueType)); //Queue head임

	Q->front = getNodeQ(NULL);
	Q->rear = getNodeQ(NULL);
	Q->front->rlink = Q->rear;
	Q->rear->llink = Q->front;

	for (i = 0; i < n; i++) {
		enqueue(i,v[i].d);
	}

	inPlaceSelectionSort();

}

int removeMin(){
	int sav = Q->front->rlink->num;
	dequeue();
	return sav;
}

int opposite(int u, int edg) {
	return (e[edg].end1 + e[edg].end2) - u;
}

int findElement(int z) {
	Queue *p = Q->front->rlink;

	while (p != Q->rear) {
		if (z == p->num) {
			return 1;
		}
		p = p->rlink;
	}
	return 0;
}

void replaceKey(int z, int dz) {
	Queue *p = Q->front->rlink;

	while (p != Q->rear) {
		if (p->num == z) p->key = dz;
		p = p->rlink;
	}
	inPlaceSelectionSort();
}
//정렬은 replaceKey 할때랑 처음만 해주면 될듯
void DijkstraShortestPaths() {
	int i,u,z;
	ListNode *p;
	Queue *k;

	for (i = 0; i < n; i++) {
		v[i].d = INT_MAX;
	}

	v[s - 1].d = 0;
	//1번째 인덱스인애 d가 0

	makeQueue();

	while (!isEmpty()) {
		u = removeMin();
		if ((u != s - 1)&&(v[u].inc->link!=NULL)) {
			ps[cnt].ver = v[u].name;
			ps[cnt++].w = v[u].d;
		}
		p = v[u].inc->link;
		while (p != NULL) {
			z = opposite(u, p->num);
			if (findElement(z)) {
				if ((v[u].d + e[p->num].w) < v[z].d) {
					v[z].d = v[u].d + e[p->num].w;
					replaceKey(z, v[z].d);
				}
			}
			p = p->link;
		}
	}
}

void pinPlaceSelectionSort() {
	int i,j;
	int min;
	Psort temp;


	for (i = 0; i < cnt - 1; i++) {
		min = i;
		for (j = i + 1; j < cnt; j++) {
			if (ps[j].ver < ps[min].ver) min = j;
		}
		temp = ps[i];
		ps[i] = ps[min];
		ps[min] = temp;
	}
}

void main() {

	int i,a,b,w;

	scanf("%d %d %d", &n, &m,&s);

	makeGraph();

	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &w);
		insertEdges(a, b, w);
	}

	DijkstraShortestPaths();

	pinPlaceSelectionSort();

	for (i = 0; i < cnt; i++) {
		printf("%d %d\n", ps[i].ver, ps[i].w);
	}
}