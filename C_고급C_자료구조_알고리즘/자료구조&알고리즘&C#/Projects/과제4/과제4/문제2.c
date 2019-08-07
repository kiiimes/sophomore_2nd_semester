#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int key;
	int height;
	struct TreeNode *parent, *lChild, *rChild;
}TreeNode;// TreeNode ����ü ����

TreeNode *root;//root ���������� ����

TreeNode* getNode(TreeNode *par) {
	TreeNode *p = (TreeNode*)malloc(sizeof(TreeNode));
	p->parent = par;
	p->lChild = NULL;
	p->rChild = NULL;
	p->key = NULL;
	p->height = 0;
	return p;
}//��忡 ���� parent, lChild, rChild, key, height ���� ���⼭ �����ϰ� �������ش�.

void init() {
	root = (TreeNode*)malloc(sizeof(TreeNode));
	root->key = NULL;
	root->parent = NULL;
	root->lChild = NULL;
	root->rChild = NULL;
	root->height = 0;
}//root �ʱ�ȭ

void expandExternal(TreeNode *p) {
	p->lChild = getNode(p);
	p->rChild = getNode(p);
	p->height = 1;
}//��� p�� ���� �ܺ� ��带 �������ְ� ���̸� �������ش�.

int isExternal(TreeNode *p) {
	if (p->lChild == NULL&&p->rChild == NULL)return 1;
	else return 0;
}//�ܺγ������ Ȯ���ϴ� �Լ�

int isInternal(TreeNode *p) {
	if (p->lChild != NULL&&p->rChild != NULL)return 1;
	else return 0;
}//���� ������� Ȯ���ϴ� �Լ�

TreeNode* treeSearch(TreeNode *v, int k) {
	if (isExternal(v))return v;

	if (k == v->key) return v;
	else if (k > v->key)return treeSearch(v->rChild, k);
	else return treeSearch(v->lChild, k);
}// ������ Ű k �� �� �ڸ��� ã���ְų� Ž���ϴ� Ű k�� ��ġ�� ã���ִ� treeSearch �Լ�

int calcAbs(int a, int b) {
	if (a > b) return a - b;
	else return b - a;
}//�� �� �� ū ������ ���� ���� ���� ������ ����ϴ� �Լ�

int calcMax(int a, int b) {
	if (a > b) return a;
	else return b;
}//�� �� ū ���� ��ȯ�ϴ� �Լ�

int heightUpdateAndBalanceCheck(TreeNode *w) {
	int balance;
	TreeNode *l;
	TreeNode *r;
	
	if (w == NULL) return;
	l = w->lChild;
	r = w->rChild;
	if (!isExternal(l)) l->height = calcMax(l->rChild->height, l->lChild->height) + 1;
	if (!isExternal(r)) r->height = calcMax(r->lChild->height, r->rChild->height) + 1;
	//w�� NULL �϶��� return �����ְ� �ƴ� ��쿡�� ���� ���� ��Ʈ���� ������ ��Ʈ���� ���̰� ū�ſ� +1�Ͽ� ��ȯ�Ѵ�.

	balance = calcAbs(r->height, l->height);
	return balance < 2;
}//���� ��Ʈ���� ���̿� ������ ��Ʈ���� ���̸� ���ؼ� ū �ʿ� +1�� �Ͽ� ������ ������ �뷱���� 1���� ū�� Ȯ���ϴ� �Լ�

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
	}//���� ���� ȸ���ϴ� ����
	else if (x->key < y->key&&y->key < z->key) {
		a = x;
		b = y;
		c = z;
		T0 = a->lChild;
		T1 = a->rChild;
		T2 = b->rChild;
		T3 = c->rChild;
	}//������ ���� ȸ���ϴ� ����
	else if (z->key < x->key&&x->key < y->key) {
		a = z;
		b = x;
		c = y;
		T0 = a->lChild;
		T1 = b->lChild;
		T2 = b->rChild;
		T3 = c->rChild;
	}//���� ���� ȸ���ϴ� ����
	else {
		a = y;
		b = x;
		c = z;
		T0 = a->lChild;
		T1 = b->lChild;
		T2 = b->rChild;
		T3 = c->rChild;
	}//������ ���� ȸ���ϴ� ���� 

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
	}//z �� ��Ʈ�� �ϴ� ��Ʈ���� b�� ��Ʈ�� �ϴ� ��Ʈ���� ��ü

	b->lChild = a;
	a->parent = b;
	//a�� b�� ���� �ڽ����� �����.

	a->lChild = T0;
	T0->parent = a;
	a->rChild = T1;
	T1->parent = a;
	//T0�� T1�� a�� ���� �� ������ ��Ʈ���� �����.

	b->rChild = c;
	c->parent = b;
	//c�� b�� ������ �ڽ����� �����.

	c->lChild = T2;
	T2->parent = c;
	c->rChild = T3;
	T3->parent = c;
	//T2�� T3�� ���� c�� ���� �� ������ ��Ʈ���� �����.

	return b;
}

void searchAndRepairAfterInsertion(TreeNode *w) {
	TreeNode *z = w;
	TreeNode *y,*x;

	while (heightUpdateAndBalanceCheck(z)) {
		if (z == root) return;
		z = z->parent;
	}//w��ġ���� �ұ����� ��带 ã�� ������ ���� �ö󰡰� �ұ��� ��尡 ������ return

	if (z->lChild->height > z->rChild->height) y = z->lChild;
	else y = z->rChild;
	//z�� �ڽĵ��� ���̰� ���� ���� y�� �Ѵ�.

	if (y->lChild->height > y->rChild->height) x = y->lChild;
	else if (y->lChild->height < y->rChild->height) x = y->rChild;
	else x = y->rChild;
	//y�� �ڽĵ� �� ���̰� ���� ���� x�� �Ѵ�.

	restructure(x);
	//x�� �����Ѵ�.

	while (heightUpdateAndBalanceCheck(z)) {
		if (z == root) return;
		z = z->parent;
	}//parent ���� �ö󰡸鼭 ���̸� �����Ѵ�.
	return;
}

void insertItem(int k) {
	TreeNode *w = treeSearch(root, k);
	if (isInternal(w)) return;
	//�̹� �ش� Ű ���� ������ ��带 �߰���Ű�� �ʰ� return ��Ų��.
	else {
		w->key = k;
		expandExternal(w);
		searchAndRepairAfterInsertion(w);
		return;
	}//Ű ���� �־��ְ� �ܺγ�带 Ȯ�� ��Ű�� ���� ������ �����ش�.
}//Ű ���� �־� ���ο� ��带 ����� �Լ�

int findElement(int n) {
	TreeNode *p = treeSearch(root, n);
	if (isExternal(p)) printf("X\n");
	else { 
		printf("%d\n", p->key); 
		return p->key; 
	}
}//treeSearch�� ���ؼ� Ű n�� ������ ��带 ��ȯ�ϰ� �ش� ��尡 �ܺγ��� X�� ����Ʈ�ϰ� ���� ã���� �ش� Ű ���� ��ȯ�ϴ� �Լ�

void preprint(TreeNode *p) {
	if (isExternal(p)) return;
	printf(" %d", p->key);
	preprint(p->lChild);
	preprint(p->rChild);
}//������ȸ�Ͽ� ����Ʈ �ϴ� �Լ�

void freeNode(TreeNode *p) {
	if (p == NULL) return;
	freeNode(p->lChild);
	freeNode(p->rChild);
	free(p);
}//free ���ִ� �Լ�

void main() {
	char type;
	int num;
	//Ű �� �Է� �޴� ������ type ����
	
	init();//�ʱ�ȭ

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
	}//type ���� ����� �����ϰ� q�� �ԷµǸ� �ݺ����� Ż���Ѵ�.
	
	freeNode(root);//�����Ҵ� �������ִ� �Լ� ȣ��
}