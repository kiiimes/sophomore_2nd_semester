#include <stdio.h>
#include <stdlib.h>


typedef struct TreeNode {
	int key;
	struct TreeNode *parent;
	struct TreeNode *lchild;
	struct TreeNode *rchild;
}TreeNode;

typedef struct TreeType {
	TreeNode* root;
}TreeType;

TreeType *t;

int findElement() {
	
}

TreeNode* getNode(int n, TreeNode *par) {
	TreeNode *p = (TreeNode*)malloc(sizeof(TreeNode));
	p->key = n;
	p->lchild = NULL;
	p->rchild = NULL;
	p->parent = par;
	return p;
}

int isExternal(TreeNode *p) {
	if (p->lchild == NULL||p->rchild == NULL) return 1;
	else return 0;
}

void insertItem(int n) {
	TreeNode *p;
	TreeNode *New;
	if (t->root==NULL) {
		t->root=getNode(n,NULL);
		return;
	}
	p = t->root;
	while (!isExternal(p)) {
		if (n > p->key) p = p->rchild;
		else if (n < p->key) p = p->lchild;
	}
	
	New=getNode(n,p);

	if (n > p->key) p->rchild = New;
	else p->lchild = New;

}

void prePrint(TreeNode *p) {
	if (p==NULL) return;
	printf("%d", p->key);
	prePrint(p->lchild);
	prePrint(p->rchild);

}//전위순회 프린트


void main() {
	char type;
	int num;
	t = (TreeType*)malloc(sizeof(TreeType));
	t->root = NULL;

	scanf("%c", &type);

	while (type != 'q') {

		switch (type) {
		case 'i':scanf("%d", &num); insertItem(num); getchar(); break;
		case 's':scanf("%d", &num); getchar(); break;
		case 'd':scanf("%d", &num); getchar(); break;
		case 'p':prePrint(t->root); printf("\n");getchar();  break;
		default:break;
		}
		scanf("%c", &type);
	}

	





}