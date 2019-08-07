#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int num;
	struct ListNode *link;
}ListNode;

typedef struct Vertex {
	char name;
	ListNode *outEdges, *inEdges;
	int inDegree;
}Vertex;

typedef struct Edge {
	int origin,destination;
	char name;
}Edge;

typedef struct Graph {
	Vertex *v;
	Edge *e;
}Graph;

typedef struct Queue {
	int num;
	struct Queue *link;
}Queue;

int n, m;
ListNode *outhead,*inhead;
Graph g;
Queue *Q;
int *topOrder;

void initializeGraph() {
	int i;

	g.v = (Vertex*)malloc(sizeof(Vertex)*n);
	g.e = (Edge*)malloc(sizeof(Edge)*m);
	inhead = (ListNode*)malloc(sizeof(ListNode)*n);
	outhead = (ListNode*)malloc(sizeof(ListNode)*n);
	topOrder = (int*)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++) {
		inhead[i].num = -1;
		inhead[i].link = NULL;
		outhead[i].num = -1;
		outhead[i].link = NULL;
	} 
}

void insertVertex(char vName, int i) {
	g.v[i].name = vName;
	g.v[i].inEdges = inhead + i;
	g.v[i].outEdges = outhead + i;
	printf(" %d ", g.v[i].outEdges->num);
	g.v[i].inDegree = 0;
}

int index(char vName) {
	int i;

	for (i = 0; i < n; i++) {
		if (g.v[i].name == vName) return i;
	}
}

ListNode* getNode() {
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
	p->link = NULL;
	p->num = -1;
	return p;
}

void insertFirst(ListNode *H, int i) {
	ListNode *node = getNode();
	if(H->link==NULL)
	node->num = i;
	node->link = H->link;
	printf("%d", node->link->num);
	H->link = node;
	printf("%d", H->link->num);
}

void insertDirectedEdge(char uName, char wName, int i) {
	int u,w;
	
	u = index(uName);
	w = index(wName);

	g.e[i].origin = u;
	g.e[i].destination = w;

	insertFirst(g.v[u].outEdges, i);
	insertFirst(g.v[w].inEdges, i);

	g.v[w].inDegree++;
}

void buildGraph() {
	char vName, uName, wName;
	int i;

	initializeGraph();

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		getchar();
		scanf("%c", &vName);
		insertVertex(vName,i);
	}

	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		getchar();
		scanf("%c %c", &uName, &wName);
		insertDirectedEdge(uName,wName,i);
	}

	ListNode *p = g.v[2].outEdges;

	while (p!= NULL) {
		printf("%d", p->num);
		p = p->link;
	}

}

int isEmpty() {
	if (Q == NULL) return 1;
	else return 0;
}

void enqueue(int v) {
	Queue *New = getNode();
	New->num = v;
	Queue *p = Q;

	if (isEmpty()) {
		Q = New;
		return;
	}

	while (p->link != NULL) {
		p = p->link;
	}
	p->link = New;
}

int dequeue() {
	Queue *sav = Q;
	int s;

	if (Q->link == NULL) {
		s = Q->num;
		free(Q);
		return s;
	}

	Q = Q->link;
	sav->link = NULL;
	s = sav->num;
	free(sav);
	return s;
}

void topologicalSort() {
	int i, t, u,w;
	int *in = (int*)malloc(sizeof(int)*n);
	ListNode *p;

	// 큐초기화 해야됨
	Q = NULL;
	
	for (i = 0; i < n; i++) {
		in[i] = g.v[i].inDegree;
		if (in[i] == 0) enqueue(i);
	}

	t = 1;

	while (!isEmpty()) {
		u = dequeue();
		topOrder[t] = u;
		t++;

		p = g.v[u].outEdges->link;
		while (p != NULL) {
			w = g.e[p->num].destination;
			printf(" %d", w);
			in[w]--;
			if (in[w] == 0) enqueue(w);
			p = p->link;
		}
	}

	if (t <= n) topOrder[0] = 0;
	else topOrder[0] = 1;

}

void main() {
	char vnum, ednum1, ednum2;
	int i;

	buildGraph();

	topologicalSort();

	if (topOrder[0] == 0) {
		write(0);
	}
	else {
		for (i = 1; i <= n; i++) {
			write(g.v[topOrder[i]].name);
		}
	}

}