#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int num;
	struct ListNode *link;
}ListNode;

typedef struct Vertex {
	int name;
	int label;
	ListNode* incidentEdges;
}Vertex;

typedef struct Edge {
	int endPoints1, endPoints2;
	int label;
}Edge;

Vertex *v;
Edge *e;
ListNode *head;
int n, m, s, mcount;

void init();
ListNode* getNode(int num);
void insertEdge(int a, int b);
void orderA(ListNode *p, int a, int b);
void orderB(ListNode *p, int a, int b);
void DFS();
int rDFS(int num);
int opposite(int vnum, int ednum);


void main() {
	int i, a, b;
	ListNode* p;

	scanf("%d %d %d", &n, &m, &s);

	init();

	for (i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		insertEdge(a, b);
	}

	DFS();
}

void init() {
	int i;

	mcount = 0;

	v = (Vertex*)malloc(sizeof(Vertex)*n);
	head = (ListNode*)malloc(sizeof(ListNode)*n);
	e = (Edge*)malloc(sizeof(Edge)*m);

	for (i = 0; i < n; i++) {
		v[i].name = i + 1;
		head[i] = *(getNode(NULL));
		v[i].incidentEdges = head + i;
	}
}

ListNode* getNode(int num) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->num = num;
	p->link = NULL;
	return p;
}

void insertEdge(int a, int b) {
	int i, f = 0, temp;
	ListNode *p, *New;

	e[mcount].endPoints1 = a - 1;
	e[mcount].endPoints2 = b - 1;

	for (i = 0; i < n; i++) {
		p = v[i].incidentEdges;
		if (v[i].name == a) {
			if (p->link == NULL) {
				New = getNode(mcount);
				New->link = NULL;
				p->link = New;
				p = p->link;
			}
			else {
				while (p->link != NULL) {
					p = p->link;
				}
				New = getNode(mcount);
				New->link = NULL;
				p->link = New;
				p = p->link;
			}
		}
		if (v[i].name == b) {
			if (p->link == NULL) {
				New = getNode(mcount);
				New->link = NULL;
				p->link = New;
				p = p->link;
			}
			else {
				while (p->link != NULL) {
					p = p->link;
				}
				New = getNode(mcount);
				New->link = NULL;
				p->link = New;
				p = p->link;
			}
		}
	}
	mcount++;
}

void DFS() {
	int i;
	int sav;
	ListNode *p = v[0].incidentEdges->link;

	for (i = 0; i < n; i++) {
		v[i].label = 0;
	}

	for (i = 0; i < m; i++) {
		e[i].label = 0;
	}

	printf("%d\n", v[s - 1].name);
	rDFS(s - 1);
}

int rDFS(int num) {
	ListNode *p = v[num].incidentEdges->link;
	ListNode *ch = v[num].incidentEdges->link;
	int w, min;

	v[num].label = 1;
	while (p != NULL) {
		if (e[p->num].label == 0) {

			if (e[p->num].endPoints1 == num) min = e[p->num].endPoints2;
			else min = e[p->num].endPoints1;

			while (ch != NULL) {
				w = opposite(num, ch->num);
				if (v[w].label == 0) {
					if (min > w) min = w;
				}
				ch = ch->link;
			}

			if (v[min].label == 0) {
				printf("%d\n", v[min].name);
				e[min].label = 1;
				rDFS(min);
			}
			else e[min].label = 2;
		}
		if (e[p->num].endPoints1 == num) {
			if (v[e[p->num].endPoints2].label == 0) {
				e[p->num].label = 1;
				v[e[p->num].endPoints2].label = 1;
				printf("%d\n", v[e[p->num].endPoints2].name);
			}
		}
		else {
			if (v[e[p->num].endPoints1].label == 0) {
				e[p->num].label = 1;
				v[e[p->num].endPoints1].label = 1;
				printf("%d\n", v[e[p->num].endPoints1].name);
			}
		}
		p = p->link;
	}
}

int opposite(int vnum, int ednum) {
	int i;

	if (e[ednum].endPoints1 == vnum) return e[ednum].endPoints2;
	else return e[ednum].endPoints1;

}
