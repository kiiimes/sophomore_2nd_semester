#include <stdio.h>

typedef struct TreeNode {
	int id;
	int data;
	struct TreeNode *left, *right;
}TreeNode;

TreeNode* create_node(int sid,int sdata,TreeNode *sleft,TreeNode *sright) {
	TreeNode *t = (TreeNode*)malloc(sizeof(TreeNode));
	t->id = sid;
	t->data = sdata;
	t->left = sleft;
	t->right = sright;
	return t;
}	

int get_node_at(TreeNode *root,int nid) {
	TreeNode *t = root;
	if (t->id == nid) {
		return t;
	}
	if (t == NULL) {
		return 0;
	}
	else {
		while (t != NULL) {
			if (t->id == get_node_at(t->left)) {
				return t;
			}
			
		}
		
	}
	
	
}

int search(TreeNode *root,int nid) {
	TreeNode *t = root;
	int op1 = 0, op2 = 0, sum=0;
	if (t == NULL) {
		return 0;
	}

	else {
		if (t->id == nid) {
			sum=t->
		}
		op1 = search(t->left);
		op2 = search(t->right);
		return op1 + op2;

	}
}

void main() {
	TreeNode *F1, *F2, *F3, *F4, *F5, *F6, *F7, *F8,*root;
	int nid;


	F8 = create_node(8, 80, NULL, NULL);
	F7 = create_node(7, 130, NULL, NULL);
	F6 = create_node(6, 120, F7, F8);
	F5 = create_node(5, 90, NULL, NULL);
	F4 = create_node(4, 70, NULL, NULL);
	F3 = create_node(3, 50, NULL, F6);
	F2 = create_node(2, 30, F4, F5);
	F1 = create_node(1, 20, F2, F3);

	scanf("%d", &nid);

	root = F1;

	printf("%d",search(root));


}