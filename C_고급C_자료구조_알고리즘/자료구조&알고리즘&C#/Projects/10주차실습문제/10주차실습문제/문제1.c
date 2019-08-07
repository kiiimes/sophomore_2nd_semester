#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int num;
	struct ListNode *link;
}ListNode;

typedef struct vertex {
	int name;
	ListNode* incidentEdges;
}Vertex;

typedef struct edge {
	int weight;
	int endPoints1, endPoints2;
}Edge;

typedef struct graph {
	Vertex *vert;
	Edge *edge;
}Graph;

typedef struct Sav {
	int ver;
	int edg;
}Sav;

ListNode *head;
Graph g;
int N;

ListNode* getNode(int n) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->num = n;
	p->link = NULL;
	return p;
}

ListNode init() {
	ListNode p;
	p.num = NULL;
	p.link = NULL;
	return p;
}

void makeIncidenceLists() {
	int i,j,cnt=0;
	ListNode *p,*New;
	int incid[6] = { 4,2,3,1,3,2 };
	int num[15] = { 0,1,4,5,0,2,1,2,3,4,3,6,7,5,7 };

	for (i = 0; i < 6; i++) {
		head[i] = init();
		p = (head+i);
		g.vert[i].incidentEdges = p;
		
		for (j = 0; j < incid[i]; j++) {
			New = getNode(num[cnt++]);
			p->link = New;
			p = p->link;
		}
	}
}

void makeGraph() {
	int i,j,ind=0;
	int e1[21] = { 0,0,1,2,0,0,4,5 };
	int e2[21] = { 1,2,2,4,3,5,4,4 };
	int w[21] = { 1,1,1,4,1,2,4,3 };
	N = 8;

	g.vert = (Vertex*)malloc(sizeof(Vertex)*6);
	g.edge = (Edge*)malloc(sizeof(Edge)*21);
	head = (ListNode*)malloc(sizeof(ListNode) * 6);

	for (i = 0; i < 6; i++) {
		g.vert[i].name = i + 1;
	}
	for (i = 0; i < 8; i++) {
		g.edge[i].endPoints1 = e1[i];
		g.edge[i].endPoints2 = e2[i];
		g.edge[i].weight = w[i];
	}
	makeIncidenceLists();
}

int findNodeNum(int nod) {
	int i;

	for (i = 0; i < 6; i++) {
		if (g.vert[i].name == nod) return 0;
	}

	return 1;
}

Sav* inPlaceInsertionSort(Sav *s, int cnt) {
	int i, j;
	Sav store;

	for (i = 1; i<cnt; i++) {
		store = s[i];
		j = i - 1;
		while ((j >= 0) && (s[j].ver>store.ver)) {
			s[j + 1] = s[j];
			j = j - 1;
		}
		s[j + 1] = store;
	}

	return s;
}

void printWeight(int nod) {
	ListNode* p ;
	Sav s[21];
	Sav *r;
	int cnt = 0,i,sa;

	if (findNodeNum(nod)) {
		printf("-1\n");
		return;
	}

	for (i = 0; i < 6; i++) {
		if (g.vert[i].name == nod) {
			sa = i;
			break;
		}
	}
	
	p = g.vert[sa].incidentEdges->link;

	while (p != NULL) {
		s[cnt].edg = g.edge[p->num].weight;
		if(g.edge[p->num].endPoints1==sa) s[cnt].ver=g.vert[g.edge[p->num].endPoints2].name;
		else if(g.edge[p->num].endPoints2==sa) s[cnt].ver = g.vert[g.edge[p->num].endPoints1].name;
		cnt++;
		p = p->link;
	}

	if (cnt == 0) return;

	r = inPlaceInsertionSort(s, cnt);

	for (i = 0; i < cnt; i++) {
		printf(" %d %d", r[i].ver, r[i].edg);
	}

	printf("\n");
}

void createListNode(int sa, int sb,int ind) {
	ListNode *p = g.vert[sa].incidentEdges->link;
	ListNode *prev=g.vert[sa].incidentEdges;

	while (p != NULL) {
		prev = p;
		p = p->link;
	}
	p= getNode(ind);
	prev->link = p;

	if (sa == sb) return;

	p = g.vert[sb].incidentEdges->link;
	prev = g.vert[sb].incidentEdges;

	while (p != NULL) {
		prev = p;
		p = p->link;
	}
	p = getNode(ind);
	prev->link = p;

}

void createEdge(int sa, int sb, int w) {
	int i, check = 0;

	for (i = 0; i < N; i++) {
		if (g.edge[i].endPoints1 == sa&&g.edge[i].endPoints2 == sb) {
			check = 1;
			g.edge[i].weight = w;
			createListNode(sa, sb, i);
		}
		else if (g.edge[i].endPoints1 == sb&&g.edge[i].endPoints2 == sa) {
			check = 1;
			g.edge[i].weight = w;
			createListNode(sa, sb, i);
		}
	}

	if (check == 0) {
		g.edge[N].endPoints1 = sa;
		g.edge[N].endPoints2 = sb;
		g.edge[N].weight = w;
		createListNode(sa, sb, N);
		N++;
	}
}

int removeEdge(int sa, int sb) {
	int i;

	for (i = 0; i < N; i++) {
		if (g.edge[i].endPoints1 == sa&&g.edge[i].endPoints2 == sb) {
			g.edge[i].weight = 0;
			return i;
		}
		else if(g.edge[i].endPoints2==sa&&g.edge[i].endPoints1==sb) {
			g.edge[i].weight = 0;
			return i;
		}
	}
}

void removeList(int sa,int sb,int rem) {
	ListNode *p = g.vert[sa].incidentEdges->link;
	ListNode *prev=g.vert[sa].incidentEdges;

	while (p != NULL) {
		if (p->num == rem) {
			prev->link = p->link;
			free(p);
			break;
		}
		prev = p;
		p = p->link;
	}
	p = g.vert[sb].incidentEdges->link;
	prev = g.vert[sb].incidentEdges;

	while (p != NULL) {
		if (p->num == rem) {
			prev->link = p->link;
			free(p);
			break;
		}
		prev = p;
		p = p->link;
	}
}

void checkWeight(int a, int b, int w) {
	int i, checkA = 0, checkB = 0,sa,sb,rem;
	ListNode *p;

	for (i = 0; i < 6; i++) {
		if (g.vert[i].name == a) {
			sa = i;
			checkA = 1;
		}
		if (g.vert[i].name == b) {
			sb = i;
			checkB = 1;
		}
	}

	if (checkA != 1 || checkB != 1) {
		printf("-1\n");
		return;
	}
	
	if (w == 0) {
		rem=removeEdge(sa,sb);
		removeList(sa,sb,rem);
	}
	else {
		p = g.vert[sa].incidentEdges->link;
		while (p != NULL) {
			if (g.edge[p->num].endPoints1 == sb&&g.edge[p->num].endPoints2 == sa) {
				g.edge[p->num].weight = w;
				break;
			}
			else if (g.edge[p->num].endPoints1 == sa&&g.edge[p->num].endPoints2 == sb) {
				g.edge[p->num].weight = w;
				break;
			}
			p = p->link;
		}

		if (p==NULL) createEdge(sa, sb, w);
	}
}

void freeList(ListNode *p) {
	if (p == NULL) return;
	freeList(p->link);
	free(p);	
}

void freedom() {
	int i;

	for (i = 0; i < 6; i++) {
		freeList((head[i].link));
	}
	free(head);
	free(g.vert);
	free(g.edge);

}

void main() {
	char type;
	int num, a, b, w;

	makeGraph();

	while (1) {
		scanf("%c", &type);
		switch (type) {
		case 'a':scanf("%d", &num); printWeight(num); break;
		case 'm':scanf("%d %d %d", &a, &b, &w); checkWeight(a, b, w); break;
		}
		if (type == 'q') {
			break;
		}
		getchar();
	}

	freedom();
}