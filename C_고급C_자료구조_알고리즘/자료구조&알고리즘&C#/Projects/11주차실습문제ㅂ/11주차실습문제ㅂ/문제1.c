#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int num;
	struct ListNode *link;
}ListNode;

typedef struct Vertex {
	int name;
	int label;
	ListNode *inc;
}Vertex;

typedef struct Edge {
	int endPoint1, endPoint2;
	int label;
}Edge;

ListNode *head;
Vertex *v;
Edge *e;
int n, m, s,cnt;

void init();
void insertEdge(int a, int b);
ListNode *getNode(int num);
void DFS();
void rDFS(int num);
int opposite(int vnum, int ednum);

void main() {
	int i,a,b;
	ListNode *p;

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

	head = (ListNode*)malloc(sizeof(ListNode)*n);
	v = (Vertex*)malloc(sizeof(Vertex)*n);
	e = (Edge*)malloc(sizeof(Edge)*m);

	for (i = 0; i < n; i++) {
		v[i].name = i + 1;
		head[i].num = NULL;
		head[i].link = NULL;
		v[i].inc = head+i;
	}
	cnt = 0;
}

ListNode *getNode(int num) {
	ListNode* p;
	p = (ListNode*)malloc(sizeof(ListNode));
	p->num = num;
	p->link = NULL;
	return p;
}

void insertEdge(int a, int b) {
	ListNode *pa = v[a-1].inc;
	ListNode *pb = v[b-1].inc;
	ListNode *prev,*New;
	int sav,fa=0,fb=0;

	e[cnt].endPoint1 = a-1;
	e[cnt].endPoint2 = b-1;

	if (pa->link == NULL) {
		pa->link = getNode(cnt);
		fa = 1;
	}
	if (pb->link == NULL) {
		pb->link = getNode(cnt);
		fb = 1;
	}

	prev = pa;
	pa = pa->link;
	while (pa != NULL) {
		if (pa->link != NULL) {
			if ((e[pa->num].endPoint1 + e[pa->num].endPoint2) < (a + b - 2)) {
				if ((e[pa->link->num].endPoint1 + e[pa->link->num].endPoint2) > (a + b - 2)) {
					New = getNode(cnt);
					New->link = pa->link;
					pa->link = New;
					fa = 1;
					break;
				}
			}
		}
		if ((prev == v[a - 1].inc) && (e[pa->num].endPoint1 + e[pa->num].endPoint2) > (a + b - 2)) {
			New = getNode(cnt);
			New->link = prev->link;
			v[a - 1].inc->link = New;
			fa = 1;
			break;
		}
		prev = pa;
		pa = pa->link;
	}
	if(fa==0) prev->link = getNode(cnt);

	prev = pb;
	pb = pb->link;
	while (pb != NULL) {
		if (pb->link != NULL) {
			if ((e[pb->num].endPoint1 + e[pb->num].endPoint2) < (a + b - 2)) {
				if ((e[pb->link->num].endPoint1 + e[pb->link->num].endPoint2) > (a + b - 2)) {
					New = getNode(cnt);
					New->link = pb->link;
					pb->link = New;
					fb = 1;
					break;
				}
			}
		}
		if ((prev == v[b - 1].inc) && (e[pb->num].endPoint1 + e[pb->num].endPoint2) > (a + b - 2)) {
			New = getNode(cnt);
			New->link = prev->link;
			v[b - 1].inc->link = New;
			fb = 1;
			break;
		}
		prev = pb;
		pb = pb->link;
	}
	if(fb==0) prev->link = getNode(cnt);

	cnt++;
}

void DFS() {
	int i;

	for (i = 0; i < n; i++) {
		v[i].label = 0;
	}

	for (i = 0; i < m; i++) {
		e[i].label = 0;
	}

	printf("%d\n",v[s-1].name);
	rDFS(s - 1);

}

void rDFS(int num) {
	ListNode *p = v[num].inc->link;
	int i,w;

	v[num].label = 1;
	while (p != NULL) {
		if(e[p->num].label==0){
			w = opposite(num,p->num);
			if (v[w].label == 0) {
				printf("%d\n",v[w].name);
				e[p->num].label = 1;
				rDFS(w);
			}
			else e[p->num].label = 2;
		}
		p = p->link;
	}
}

int opposite(int vnum,int ednum) {
	if (e[ednum].endPoint1 == vnum) return e[ednum].endPoint2;
	else return e[ednum].endPoint1;
}