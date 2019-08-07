#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int id, data;
	struct TreeNode *left, *right;
}TreeNode;

TreeNode* searchpre(TreeNode* root, int id) {
	TreeNode* sav = NULL;
	if (root) {
		if (root->id == id) {
			return root;
		}
		else if (root->left == NULL) {
			return NULL;
		}
		sav = searchpre(root->left, id);
		if (sav == NULL) {
			sav = searchpre(root->right, id);
		}

	}
}
void insert_node(TreeNode **root, int data,int id) {
TreeNode* p;
TreeNode* t;
TreeNode* new;

t = *root;
p = NULL;

while (t != NULL) {
p = t;
if (id < t->id) {
t = t->left;
}
else {
t = t->right;
}
}

new = (TreeNode*)malloc(sizeof(TreeNode));
new->data = data;
new->id = id;
new->left = new->right = NULL;

if (p != NULL) {
if (id < p->id) {
p->left = new;
}
else p->right = new;
}
else {
*root = new;
}
}

TreeNode* create_node(int item, int id, TreeNode* left, TreeNode* right) {
	TreeNode* new = (TreeNode*)malloc(sizeof(TreeNode));
	new->data = item;
	new->id = id;
	new->left = left;
	new->right = right;
	return new;
}


void preorder(TreeNode* root) {
	if (root) {
		printf(" %d", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(TreeNode *root) {

	if (root) {
		inorder(root->left);
		printf(" %d", root->data);
		inorder(root->right);
	}

}

void postorder(TreeNode *root) {

	if (root) {
		postorder(root->left);
		postorder(root->right);
		printf(" %d", root->data);
	}
}

//좀뒤에 구현 (순환으로 free 해주는게 편할거같음)



void main() {
	TreeNode *root = (TreeNode*)malloc(sizeof(TreeNode));

	TreeNode *F1, *F2, *F3, *F4, *F5, *F6, *F7, *F8;

	int type, i, nid;
	root = NULL;

	scanf("%d %d", &type, &nid);

	F1 = (TreeNode*)malloc(sizeof(TreeNode));
	F2 = (TreeNode*)malloc(sizeof(TreeNode));
	F3 = (TreeNode*)malloc(sizeof(TreeNode));
	F4 = (TreeNode*)malloc(sizeof(TreeNode));
	F5 = (TreeNode*)malloc(sizeof(TreeNode));
	F6 = (TreeNode*)malloc(sizeof(TreeNode));
	F7 = (TreeNode*)malloc(sizeof(TreeNode));
	F8 = (TreeNode*)malloc(sizeof(TreeNode));

	F8 = create_node(80, 8, NULL, NULL);
	F7 = create_node(130, 7, NULL, NULL);
	F6 = create_node(120, 6, F7, F8);
	F5 = create_node(90, 5, NULL, NULL);
	F4 = create_node(70, 4, NULL, NULL);
	F3 = create_node(50, 3, NULL, F6);
	F2 = create_node(30, 2, F4, F5);
	F1 = create_node(20, 1, F2, F3);

	root = F1;


	switch (type) {
	case 1:if (nid > 8 || nid < 1)printf("-1"); preorder(searchpre(root, nid)); break;
	case 2:if (nid > 8 || nid < 1)printf("-1"); inorder(searchpre(root, nid)); break;
	case 3:if (nid > 8 || nid < 1)printf("-1"); postorder(searchpre(root, nid)); break;
	default:;
	}

	free(F8);
	free(F7);
	free(F6);
	free(F5);
	free(F4);
	free(F3);
	free(F2);
	free(F1);


	//free시키려면 모든 노드를 탐색해서 free 시켜줘야함







}