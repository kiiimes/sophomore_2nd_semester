#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
}TreeNode;

TreeNode* create_node(int data) {
	TreeNode *t = (TreeNode*)malloc(sizeof(TreeNode));
	t->data = data;
	t->left = NULL;
	t->right = NULL;
	return t;
}

TreeNode* search(TreeNode *root, int key) {
	TreeNode *t = root;
	TreeNode *sav1, *sav2;
	if (t == NULL) {
		return NULL;
	}
	if (t->data == key) {
		return t;
	}
	else {
		sav1 = search(t->left, key);
		sav2 = search(t->right, key);
		if (sav1 != NULL) {
			if (sav1->data == key) {
				return sav1;
			}
		}
		else if (sav2 != NULL) {
			if (sav2->data == key) {
				return sav2;
			}
		}
		else {
			return NULL;
		}
		t

int insert_node(TreeNode **root,int key,int ldata,int rdata) {
	TreeNode *t;

	if (*root == NULL) {
		*root=create_node(key);
		(*root)->left = create_node(ldata);
		(*root)->right = create_node(rdata);
		return;
	}

	t=search(*root, key);
	if (ldata != 0) {
		t->left = create_node(ldata);
	}
	else {
		t->left = NULL;
	}
	if (rdata != 0) {
		t->right = create_node(rdata);
	}
	else {
		t->right = NULL;
	}

	return;
}

void search_print(TreeNode *root, char info[]) {
	int i;


	for (i = 0; info[i] != '\0'; i++) {
		printf(" %d", root->data);
		if (info[i] == 'R') {
			root = root->right;
		}
		else if (info[i] == 'L') {
			root = root->left;
		}
	}
	printf(" %d", root->data);

}

int freedom(TreeNode **root) {
	if (*root == NULL) {
		return;
	}
	if ((*root)->left == NULL && (*root)->right == NULL) {
		free(*root);
		return;
	}
	else {
		freedom(&((*root)->left));
		freedom(&((*root)->right));
		free(*root);
		return;
	}
}

void main() {
	int num,i,ln,rn,item,scnum;
	TreeNode *root=NULL;
	char info[101];

	scanf("%d", &num);

	for (i = 0; i < num; i++) {
		scanf("%d %d %d", &item, &ln, &rn);
		insert_node(&root, item, ln, rn);
	}
	
	scanf("%d", &scnum);

	for (i = 0; i < scnum; i++) {
		getchar();
		scanf("%s", info);
		search_print(root, &info);
		printf("\n");
	}

	freedom(&root);
}