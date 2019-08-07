#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int key;
	struct TreeNode *parent;
	struct TreeNode *lchild;
	struct TreeNode *rchild;
}TreeNode;

typedef struct TreeType {
	TreeNode *root;
}TreeType;

TreeType w;

TreeNode* getNode(TreeNode *par) {
	TreeNode *p=(TreeNode*)malloc(sizeof(TreeNode));
	p->parent = par;
	p->lchild = NULL;
	p->rchild = NULL;
	p->key = NULL;
	return p;
}

void expandExternal(TreeNode *p) {
	p->lchild = getNode(p);
	p->rchild = getNode(p);
}

void init() {
	w.root = (TreeNode*)malloc(sizeof(TreeNode));
	w.root->key = NULL;
	w.root->parent = NULL;
	w.root->lchild = NULL;
	w.root->rchild = NULL;
}//root 초기화

int isExternal(TreeNode *p) {
	if (p->lchild == NULL&&p->rchild == NULL)return 1;
	else return 0;
}

void insertItem(int n) {
	if (w.root->key==NULL) {
		w.root->key = n;
		expandExternal(w.root);
		return;
	}

	TreeNode *p=w.root;

	while (!isExternal(p)) {
		if (n > p->key)p = p->rchild;
		else p = p->lchild;
	}

	p->key = n;
	expandExternal(p);
	
}

void preprint(TreeNode *p) {
	if (isExternal(p)) return;
	printf("%d ", p->key);
	preprint(p->lchild);
	preprint(p->rchild);
}

TreeNode* treeSearch(TreeNode *p, int n) {
	if (isExternal(p))return p;

	if (n == p->key) return p;
	else if (n > p->key)return treeSearch(p->rchild,n);
	else return treeSearch(p->lchild,n);
}

void findElement(int n) {
	TreeNode *p = treeSearch(w.root, n);
	if (isExternal(p)) printf("X\n");
	else printf("%d\n", p->key);
}

TreeNode* inOrderSucc(TreeNode* p) {
	p = p->rchild;
	while (!isExternal(p)) {
		p = p->lchild;
	}
	return p;
}

TreeNode* sibling(TreeNode *z) {
	if (z->parent->lchild == z)return z->parent->rchild;
	else return z->parent->lchild;
}

int reduceExternal(TreeNode *z) {
	TreeNode *p = z->parent;
	TreeNode *zs = sibling(z);
	int sav;

	if (p == w.root) {
		w.root = zs;
		zs->parent = NULL;
	}
	else {
		TreeNode *g = p->parent;
		zs->parent = g;
		if (p == g->lchild) g->lchild = zs;
		else g->rchild = zs;
	}
	sav = p->key;
	free(z);
	free(p);
	return sav;
}

void removeElement(int n) {
	TreeNode* p=treeSearch(w.root, n);
	TreeNode* sav;
	int dnum;
	if (isExternal(p)) {
		printf("X\n");
		return;
	}

	if (isExternal(p->lchild)) {
		printf("%d\n",reduceExternal(p->lchild));

	}
	else if (isExternal(p->rchild)) {
		printf("%d\n",reduceExternal(p->rchild));
	}
	//둘다 내부노드이면 경우는 1가지임 오른하나 왼 쭉!
	else {
		sav = inOrderSucc(p);
		dnum = p->key;
		p->key=sav->parent->key;
		reduceExternal(sav);
		printf("%d", dnum);
	}

}

void main() {
	char type;
	int num;

	init();

	while (1) {
		scanf("%c", &type);
		switch (type) {
		case 'i':scanf("%d", &num); insertItem(num); break;
		case 's':scanf("%d", &num); findElement(num); break;
		case 'd':scanf("%d", &num); removeElement(num); break;
		case 'p':preprint(w.root); printf("\n"); break;
		default :break;
		}
		getchar();
		if (type == 'q') break;
	}

}