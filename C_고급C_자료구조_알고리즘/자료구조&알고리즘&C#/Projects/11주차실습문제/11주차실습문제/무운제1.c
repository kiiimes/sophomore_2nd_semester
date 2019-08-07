#include<stdio.h>
#include<stdlib.h>


typedef struct node{
	int num;
	struct node *next;
}node;

typedef struct edge{
	int endPoints1, endPoints2;
	int label;
};

typedef struct vertex{
	int name;
	int label;
	struct node *header;
}vertex;

vertex *V;
edge *E;
int n, m, s;

int isExistEdge(int n1, int n2)
{
	//v1 v2쌍이 간선구조체에 존재하는지 알려줌
	int i;

	for (i = 0; i<m; i++)
	{
		if ((E[i].endPoints1 == n1 && E[i].endPoints2 == n2) || (E[i].endPoints1 == n2 && E[i].endPoints2 == n1))
			return i;
	}
	return -1;

}

void update_vertices(struct node *p, int v1, int v2, int num)
{
	int e1, e2, n1, n2;
	struct node *New, *q, *tmp;
	q = (struct node *)malloc(sizeof(struct node));
	New = (struct node *)malloc(sizeof(struct node));

	q = p;

	if (q->next == NULL)
	{
		New->num = num;
		New->next = NULL;
		q->next = New;

		return;
	}

	while (q->next != NULL){
		tmp = q;
		q = q->next;

		e1 = E[q->num].endPoints1;
		e2 = E[q->num].endPoints2;

		if (e1 == v1){
			n1 = e2;
			n2 = v2;
		}
		else if (e1 == v2){
			n1 = e2;
			n2 = v1;
		}
		else if (e2 == v1){
			n1 = e1;
			n2 = v2;
		}
		else{
			n1 = e1;
			n2 = v1;
		}


		if (V[n1].name>V[n2].name){
			New->num = num;
			New->next = q;
			tmp->next = New;
			return;
		}
	}
	New->num = num;
	New->next = NULL;
	q->next = New;
}

void make_list(int idx){
	int i, x;
	struct node *q;

	q = V[idx].header;
	for (i = 0; i<m; i++)
	{
		x = isExistEdge(idx, i);
		
		if (x != -1)
		{
			update_vertices(q, E[x].endPoints1, E[x].endPoints2, x);

		}
	}


}


void make_graph(int n, int m)
{
	int i, e1, e2;
	struct node *H;

	//정점 초기화
	for (i = 0; i<n; i++)
	{
		H = (struct node *)malloc(sizeof(struct node));
		H->next = NULL;

		V[i].name = i + 1;
		V[i].header = H;
	}

	//간선 구조체 값 넣어주기
	for (i = 0; i<m; i++)
	{
		scanf("%d %d", &e1, &e2);

		E[i].endPoints1 = e1 - 1;
		E[i].endPoints2 = e2 - 1;
	}

	//리스트 만들어주기

	for (i = 0; i<n; i++)
	{
		make_list(i);
	}




}
int opposite(int pnum, int vnum)
{
	if (E[pnum].endPoints1 == vnum) return E[pnum].endPoints2;
	else return E[pnum].endPoints1;

}

void rDFS(int idx)
{
	//정점이 하나 들어와
	int i, n;
	struct node *p;
	struct vertex w, *v;

	v = &V[idx];

	v->label = 1;

	p = v->header->next;

	while (p != NULL){
		if (E[p->num].label == 0)
		{
			n = opposite(p->num, (v->name) - 1);

			w = V[n];

			if (w.label == 0){
				E[p->num].label = -2;
				printf("%d\n", w.name);
				rDFS(n);
			}
			else E[p->num].label = -1;
		}
		p = p->next;
	}
}


void DFS(int s){
	int i, cnt = 0;

	for (i = 0; i<n; i++){
		V[i].label = 0;
	}

	for (i = 0; i<m; i++){
		E[i].label = 0;
	}

	if (V[s - 1].label == 0)
	{
		printf("%d\n", V[s - 1].name);
		rDFS(s - 1);
	}
}

int main()
{
	struct node *p;
	int i;

	scanf("%d %d %d", &n, &m, &s);

	V = (vertex *)malloc(sizeof(vertex)*n);
	E = (edge *)malloc(sizeof(edge)*m);

	make_graph(n, m);

	DFS(s);

	
	return 0;
}