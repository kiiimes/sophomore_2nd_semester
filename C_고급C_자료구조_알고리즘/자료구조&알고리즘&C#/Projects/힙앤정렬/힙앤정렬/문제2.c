#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int item;
	struct TreeNode *llink, *rlink;
}TreeNode;

typedef struct TreeType {
	TreeNode *root;
}TreeType;

TreeNode* get_node(int data) {
	TreeNode *p = (TreeNode*)malloc(sizeof(TreeNode));
	p->item = data;
	p->llink = NULL;
	p->rlink = NULL;
	return p;
}

TreeNode* ins_order(TreeType *t, int pos) {

}

TreeNode* get_node(TreeNode *p,int ld, int rd) {
	TreeNode *lp, *rp;
	lp = (TreeNode*)malloc(sizeof(TreeNode));
	rp = (TreeNode*)malloc(sizeof(TreeNode));

	lp->item = ld;
	lp->llink = NULL;
	lp->rlink = NULL;

	rp->item = rd;
	rp->llink = NULL;
	rp->rlink = NULL;

	p->llink = lp;
	p->rlink = rp; 
		
}

void insert_node(TreeType *t, int rootd, int ld, int rd) {

}

void main() {
	TreeType *t;
	int i, n,rootd,ld,rd;
	t = (TreeType*)malloc(sizeof(TreeType));

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d %d %d", &rootd, &ld, &rd);
		insert_node(t, rootd, ld, rd);
	}


}