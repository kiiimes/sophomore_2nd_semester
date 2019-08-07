#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int key;
	int height;
	struct TreeNode *parent, *lChild, *rChild;
}TreeNode;// TreeNode 구조체 생성

TreeNode *root;//root 전역변수로 생성

TreeNode* getNode(TreeNode *par) {
	TreeNode *p = (TreeNode*)malloc(sizeof(TreeNode));
	p->parent = par;
	p->lChild = NULL;
	p->rChild = NULL;
	p->key = NULL;
	p->height = 0;
	return p;
}//노드에 대한 parent, lChild, rChild, key, height 등을 여기서 설정하고 생성해준다.

void init() {
	root = (TreeNode*)malloc(sizeof(TreeNode));
	root->key = NULL;
	root->parent = NULL;
	root->lChild = NULL;
	root->rChild = NULL;
	root->height = 0;
}//root 초기화

void expandExternal(TreeNode *p) {
	p->lChild = getNode(p);
	p->rChild = getNode(p);
	p->height = 1;
}//노드 p에 대해 외부 노드를 생성해주고 높이를 조정해준다.

int isExternal(TreeNode *p) {
	if (p->lChild == NULL&&p->rChild == NULL)return 1;
	else return 0;
}//외부노드인지 확인하는 함수

int isInternal(TreeNode *p) {
	if (p->lChild != NULL&&p->rChild != NULL)return 1;
	else return 0;
}//내부 노드인지 확인하는 함수

TreeNode* treeSearch(TreeNode *v, int k) {
	if (isExternal(v))return v;

	if (k == v->key) return v;
	else if (k > v->key)return treeSearch(v->rChild, k);
	else return treeSearch(v->lChild, k);
}// 삽입할 키 k 가 들어갈 자리를 찾아주거나 탐색하는 키 k의 위치를 찾아주는 treeSearch 함수

int calcAbs(int a, int b) {
	if (a > b) return a - b;
	else return b - a;
}//두 값 중 큰 값에서 작은 값을 빼서 절댓값을 계산하는 함수

int calcMax(int a, int b) {
	if (a > b) return a;
	else return b;
}//둘 중 큰 값을 반환하는 함수

int heightUpdateAndBalanceCheck(TreeNode *w) {
	int balance;
	TreeNode *l;
	TreeNode *r;
	
	if (w == NULL) return;
	l = w->lChild;
	r = w->rChild;
	if (!isExternal(l)) l->height = calcMax(l->rChild->height, l->lChild->height) + 1;
	if (!isExternal(r)) r->height = calcMax(r->lChild->height, r->rChild->height) + 1;
	//w가 NULL 일때는 return 시켜주고 아닌 경우에는 각각 왼쪽 부트리와 오른쪽 부트리중 높이가 큰거에 +1하여 반환한다.

	balance = calcAbs(r->height, l->height);
	return balance < 2;
}//왼쪽 부트리의 높이와 오른쪽 부트리의 높이를 비교해서 큰 쪽에 +1을 하여 각각의 높이의 밸런스가 1보다 큰지 확인하는 함수

TreeNode* restructure(TreeNode *x) {
	TreeNode *y = x->parent;
	TreeNode *z = y->parent;
	TreeNode *a, *b, *c;
	TreeNode *T0, *T1, *T2, *T3;

	if (z->key < y->key &&y->key< x->key) {
		a = z;
		b = y;
		c = x;
		T0 = a->lChild;
		T1 = b->lChild;
		T2 = c->lChild;
		T3 = c->rChild;
	}//왼쪽 단일 회전하는 과정
	else if (x->key < y->key&&y->key < z->key) {
		a = x;
		b = y;
		c = z;
		T0 = a->lChild;
		T1 = a->rChild;
		T2 = b->rChild;
		T3 = c->rChild;
	}//오른쪽 단일 회전하는 과정
	else if (z->key < x->key&&x->key < y->key) {
		a = z;
		b = x;
		c = y;
		T0 = a->lChild;
		T1 = b->lChild;
		T2 = b->rChild;
		T3 = c->rChild;
	}//왼쪽 이중 회전하는 과정
	else {
		a = y;
		b = x;
		c = z;
		T0 = a->lChild;
		T1 = b->lChild;
		T2 = b->rChild;
		T3 = c->rChild;
	}//오른쪽 이중 회전하는 과정 

	if (z == root) {
		root = b;
		b->parent = NULL;
	}
	else if (z->parent->lChild == z) {
		z->parent->lChild = b;
		b->parent = z->parent;
	}
	else {
		z->parent->rChild = b;
		b->parent = z->parent;
	}//z 를 루트로 하는 부트리를 b를 루트로 하는 부트리로 대체

	b->lChild = a;
	a->parent = b;
	//a를 b의 왼쪽 자식으로 만든다.

	a->lChild = T0;
	T0->parent = a;
	a->rChild = T1;
	T1->parent = a;
	//T0와 T1를 a의 왼쪽 및 오른쪽 부트리로 만든다.

	b->rChild = c;
	c->parent = b;
	//c를 b의 오른쪽 자식으로 만든다.

	c->lChild = T2;
	T2->parent = c;
	c->rChild = T3;
	T3->parent = c;
	//T2와 T3를 각각 c의 왼쪽 및 오른쪽 부트리로 만든다.

	return b;
}

void searchAndRepairAfterInsertion(TreeNode *w) {
	TreeNode *z = w;
	TreeNode *y,*x;

	while (heightUpdateAndBalanceCheck(z)) {
		if (z == root) return;
		z = z->parent;
	}//w위치에서 불균형한 노드를 찾을 때까지 위로 올라가고 불균형 노드가 없으면 return

	if (z->lChild->height > z->rChild->height) y = z->lChild;
	else y = z->rChild;
	//z의 자식들중 높이가 높은 것을 y로 한다.

	if (y->lChild->height > y->rChild->height) x = y->lChild;
	else if (y->lChild->height < y->rChild->height) x = y->rChild;
	else x = y->rChild;
	//y의 자식들 중 높이가 높은 것을 x로 한다.

	restructure(x);
	//x를 개조한다.

	while (heightUpdateAndBalanceCheck(z)) {
		if (z == root) return;
		z = z->parent;
	}//parent 노드로 올라가면서 높이를 갱신한다.
	return;
}

void insertItem(int k) {
	TreeNode *w = treeSearch(root, k);
	if (isInternal(w)) return;
	//이미 해당 키 값이 있으면 노드를 추가시키지 않고 return 시킨다.
	else {
		w->key = k;
		expandExternal(w);
		searchAndRepairAfterInsertion(w);
		return;
	}//키 값을 넣어주고 외부노드를 확장 시키고 높이 균형을 맞춰준다.
}//키 값을 넣어 새로운 노드를 만드는 함수

int findElement(int n) {
	TreeNode *p = treeSearch(root, n);
	if (isExternal(p)) printf("X\n");
	else { 
		printf("%d\n", p->key); 
		return p->key; 
	}
}//treeSearch를 통해서 키 n을 가지는 노드를 반환하고 해당 노드가 외부노드면 X를 프린트하고 값을 찾으면 해당 키 값을 반환하는 함수

void preprint(TreeNode *p) {
	if (isExternal(p)) return;
	printf(" %d", p->key);
	preprint(p->lChild);
	preprint(p->rChild);
}//전위순회하여 프린트 하는 함수

void freeNode(TreeNode *p) {
	if (p == NULL) return;
	freeNode(p->lChild);
	freeNode(p->rChild);
	free(p);
}//free 해주는 함수

void main() {
	char type;
	int num;
	//키 값 입력 받는 변수와 type 변수
	
	init();//초기화

	while (1) {
		scanf("%c", &type);

		switch (type) {
		case 'i':scanf("%d", &num); insertItem(num); break;
		case 's':scanf("%d", &num); findElement(num); break;
		case 'p':preprint(root); printf("\n"); break;
		default:break;
		}
		if (type == 'q') {
			break;
		}
		getchar();
	}//type 별로 기능을 수행하고 q가 입력되면 반복문을 탈출한다.
	
	freeNode(root);//동적할당 해제해주는 함수 호출
}