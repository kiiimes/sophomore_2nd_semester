#include <stdio.h>
#include <stdlib.h>

typedef struct Vertex {
	int name;
}Vertex;

typedef struct Edge {
	int weight;
	int endPoint1, endPoint2;
}Edge;

typedef struct Graph {
	Vertex v[6];
	Edge e[21];
	int matrix[6][6];

}Graph;

typedef struct Sav {
	int ver;
	int edg;
}Sav;

int N;
Graph g;

void init() {
	int i,j;
	int in[8][3] = {
		{0,1,1},
		{ 0,2,1 },
		{ 1,2,1 },
		{ 2,4,4 },
		{ 0,3,1 },
		{ 0,5,2 },
		{ 4,4,4 },
		{ 4,5,3 }
	};	
	int matarr[6][6] = {
		{-1,0,1,4,-1,5},
		{0,-1,2,-1,-1,-1},
		{1,2,-1,-1,3,-1},
		{4,-1,-1,-1,-1,-1},
		{-1,-1,3,-1,6,7},
		{5,-1,-1,-1,7,-1,}		
	};

	for (i = 0; i < 6; i++) {
		g.v[i].name = i + 1;
	}

	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			g.matrix[i][j] = matarr[i][j];
		}
	}

	for (i = 0; i < 8; i++) {
			g.e[i].endPoint1 = in[i][0];
			g.e[i].endPoint2 = in[i][1];
			g.e[i].weight = in[i][2];
		
	}
}

int findNodeNum(int nod) {
	int i;

	for (i = 0; i < 6; i++) {
		if (g.v[i].name == nod) return 0;
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
	Sav s[21];
	Sav *r;
	int cnt = 0, i, sa;

	if (findNodeNum(nod)) {
		printf("-1\n");
		return;
	}

	for (i = 0; i < 6; i++) {
		if (g.v[i].name == nod) {
			sa = i;
			break;
		}
	}

	for (i = 0; i < 6; i++) {
		if (g.matrix[sa][i] == -1)continue;

		s[cnt].edg = g.e[g.matrix[sa][i]].weight;
		if (g.e[g.matrix[sa][i]].endPoint1 == sa) s[cnt].ver = g.v[g.e[g.matrix[sa][i]].endPoint2].name;
		else if (g.e[g.matrix[sa][i]].endPoint2 == sa) s[cnt].ver = g.v[g.e[g.matrix[sa][i]].endPoint1].name;
		cnt++;
	}
	
	if (cnt == 0) return;

	r = inPlaceInsertionSort(s, cnt);

	for (i = 0; i < cnt; i++) {
		printf(" %d %d", r[i].ver, r[i].edg);
	}

	printf("\n");
}

void removeEdge(int sa, int sb) {
}

void createEdge(int sa, int sb, int w) {
	int i, check = 0;

	for (i = 0; i < N; i++) {
		if (g.e[i].endPoint1 == sa&&g.e[i].endPoint2 == sb) {
			check = 1;
			g.e[i].weight = w;
			g.matrix[sa][sb] = i;
			g.matrix[sb][sa] = i;
		}
		else if (g.e[i].endPoint1 == sb&&g.e[i].endPoint2 == sa) {
			check = 1;
			g.e[i].weight = w;
			g.matrix[sa][sb] = i;
			g.matrix[sb][sa] = i;
		}
	}

	if (check == 0) {
		g.e[N].endPoint1 = sa;
		g.e[N].endPoint2 = sb;
		g.e[N].weight = w;
		g.matrix[sa][sb] = N;
		g.matrix[sb][sa] = N;
		N++;
	}
}

void checkWeight(int a, int b, int w) {
	int i, checkA = 0, checkB = 0, sa, sb, rem;

	for (i = 0; i < 6; i++) {
		if (g.v[i].name == a) {
			sa = i;
			checkA = 1;
		}
		if (g.v[i].name == b) {
			sb = i;
			checkB = 1;
		}
	}

	if (checkA != 1 || checkB != 1) {
		printf("-1\n");
		return;
	}
	
	if (w == 0) {
		if (g.matrix[sa][sb] == -1) return;
		g.e[g.matrix[sa][sb]].weight = 0;

		g.matrix[sa][sb] = -1;
		g.matrix[sb][sa] = -1;

	}
	else {
		if (g.matrix[sa][sb] == -1) createEdge(sa, sb, w);
		else {
			g.e[g.matrix[sa][sb]].weight = w;
			g.e[g.matrix[sb][sa]].weight = w;
		}
	}
}

void main() {
	char type;
	int num, a, b, w;
	N = 8;

	init();

	while (1) {
		scanf("%c", &type);
		switch (type) {
		case 'a':scanf("%d", &num); printWeight(num); break;
		case 'm':scanf("%d %d %d", &a, &b, &w); checkWeight(a, b, w);  break;
		}
		if (type == 'q') {
			break;
		}
		getchar();
	}


}