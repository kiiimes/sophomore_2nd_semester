#include <stdio.h>
#include <stdlib.h>

typedef struct Vertex {
	int name;
	int label;
}Vertex;

typedef struct Edge {
	int endPoint1, endPoint2;
	int label;
}Edge;

Vertex *v;
Edge *e;
int **adjArr;

int n, m, s, cnt;

void init();
int isEmpty(int *L);
void insertEdge(int a, int b);
void insertLast(int *L, int num);
void BFS();
void BFS1(int num);
int opposite(int vnum, int ednum);

void main() {
	int i, a, b;

	scanf("%d %d %d", &n, &m, &s);

	init();

	for (i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		insertEdge(a, b);
	}

	BFS();

}

void init() {
	int i,j;

	adjArr = (int**)malloc(sizeof(int*)*n);
	v = (Vertex*)malloc(sizeof(Vertex)*n);
	e = (Edge*)malloc(sizeof(Edge)*m);

	for (i = 0; i < n; i++) {
		v[i].name = i + 1;
		adjArr[i] = (int*)malloc(sizeof(int)*n);
		for (j = 0; j < n; j++) {
			adjArr[i][j] = -1;
		}
	}

	cnt = 0;
}

int* makeList() {
	int i;
	
	int *p = (int*)malloc(sizeof(int)*n);
	
	for (i = 0; i < n; i++) {
		p[i] = -1;
	}
	return p;
}

void insertEdge(int a, int b) {
	adjArr[a - 1][b - 1] = cnt;
	adjArr[b - 1][a - 1] = cnt;
	e[cnt].endPoint1 = a - 1;
	e[cnt].endPoint2 = b - 1;
	cnt++;
}

void BFS() {
	int i;

	for (i = 0; i < n; i++) {
		v[i].label = 0;
	}

	for (i = 0; i < m; i++) {
		e[i].label = 0;
	}
	
	printf("%d\n", v[s - 1].name);
	BFS1(s - 1);
}

void BFS1(int num) {
	int **L;
	int i,j,k,w;

	L = (int**)malloc(sizeof(int*)*n);
	L[0] = makeList();
	insertLast(L[0], num);//ÀÎµ¦½º ÀúÀå
	v[num].label = 1;
	i = 0;

	while (!isEmpty(L[i])) {
		L[i + 1] = makeList();
		for (j = 0; j < n; j++) {
			if (L[i][j] != -1) {
				for (k = 0; k < n; k++) {
					if (adjArr[L[i][j]][k] != -1) {
						if (e[adjArr[L[i][j]][k]].label == 0) {
							w = opposite(L[i][j], adjArr[L[i][j]][k]);
							if (v[w].label == 0) {
								printf("%d\n", v[w].name);
								e[adjArr[L[i][j]][k]].label = 1;
								v[w].label = 1;
								insertLast(L[i+1],w);
							}
							else e[adjArr[L[i][j]][k]].label = 2;
						}
					}
				}
			}
		}
		i++;
	}

}

void insertLast(int *L,int num) {
	int i;

	for (i = 0; i < n; i++) {
		if (L[i] == -1) {
			L[i] = num;
			break;
		}
	}

}

int isEmpty(int *L) {
	if (L[0] == -1) return 1;
	else return 0;
}

int opposite(int vnum, int ednum) {
	if (e[ednum].endPoint1 == vnum) return e[ednum].endPoint2;
	else return e[ednum].endPoint1;
}