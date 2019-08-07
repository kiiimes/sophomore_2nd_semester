#include<stdio.h>
#include<stdlib.h>

typedef struct vertex{
	int name;
	int label;
}vertex;

int **A;
int *q, f, r;
int n, m, s;
struct vertex *V;

void makeMat(){
	int a, b, i, j;

	for (i = 0; i<n; i++){
		V[i].name = i + 1;
	}

	A = (int **)malloc(sizeof(int *)*n);

	for (i = 0; i<n; i++){
		A[i] = (int *)malloc(sizeof(int)*n);
	}

	for (i = 0; i<n; i++){
		for (j = 0; j<n; j++){
			A[i][j] = 0;
		}
	}

	for (i = 0; i<m; i++){
		scanf("%d %d", &a, &b);

		A[a - 1][b - 1] = 1;
		A[b - 1][a - 1] = 1;
	}
}
int isEmpty(){
	if ((r + 1) % n == f) return 1;
	else return 0;
}

void init(){
	f = 0;
	r = n - 1;
}

void enqueue(int e){
	r = (r + 1) % n;
	q[r] = e;
}

int dequeue(){
	int e;

	e = q[f];
	f = (f + 1) % n;

	return e;
}

void BFS1(int s){
	vertex *v, *w;
	int i, j, k;
	int num;

	v = &V[s];
	enqueue(v->name);

	v->label =-2;

	while (isEmpty() == 0){
		num = dequeue();
		for (i = 0; i<n; i++){
			if (A[num - 1][i] == 2){
				w = &V[i];
				if (w->label == 2){
					printf("%d\n", w->name);

					A[num - 1][i] = 3;
					A[i][num - 1] = 3;
					w->label = -2;

					enqueue(w->name);
				}
				else{
					A[num - 1][i] = -1;
					A[i][num - 1] = -1;
				}
			}
		}
	}
}

void BFS(int s){
	int i, j;

	for (i = 0; i<n; i++) V[i].label = 2;

	for (i = 0; i<n; i++){
		for (j = 0; j<n; j++){
			if (A[i][j] == 1) A[i][j] = 2;
		}
	}

	if (V[s].label == 2){
		printf("%d\n", V[s].name);
		BFS1(s);
	}
}

int main(){
	int i, j;

	scanf("%d %d %d", &n, &m, &s);
	V = (vertex *)malloc(sizeof(vertex)*n);
	q = (int *)malloc(sizeof(int)*n);

	init();

	makeMat();

	BFS(s - 1);

	return 0;
}