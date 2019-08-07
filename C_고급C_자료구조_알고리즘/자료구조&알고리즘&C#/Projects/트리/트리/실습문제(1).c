#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct {
	element data;
	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode;// 트리 구조체

void add(TreeNode *p,int item,TreeNode* left,TreeNode *right) {
	
	p->data = item;
	p->left = left;
	p->right = right;
}

void preorder(TreeNode *root) {
	TreeNode *s1 = root->left;
	TreeNode *s2 = root->right;
	printf("%d ", root->data);
	if (root->left != NULL) {
		printf("%d ",s1->data);
	}
	if (root->right != NULL) {
		printf("%d ", s2->data);
	}
}



int main() {
	TreeNode *F1, *F2, *F3, *F4, *F5, *F6, *F7, *F8;
	int n;


	F1 = (TreeNode*)malloc(sizeof(TreeNode));
	F2 = (TreeNode*)malloc(sizeof(TreeNode));
	F3 = (TreeNode*)malloc(sizeof(TreeNode));
	F4 = (TreeNode*)malloc(sizeof(TreeNode));
	F5 = (TreeNode*)malloc(sizeof(TreeNode));
	F6 = (TreeNode*)malloc(sizeof(TreeNode));
	F7 = (TreeNode*)malloc(sizeof(TreeNode));
	F8 = (TreeNode*)malloc(sizeof(TreeNode));

	add(F8,80,NULL,NULL);
	add(F7, 130, NULL, NULL);
	add(F6, 120, F7, F8);
	add(F5, 90, NULL, NULL);
	add(F4, 70, NULL, NULL);
	add(F3, 50, NULL, F6);
	add(F2, 30, F4, F5);
	add(F1, 20, F2, F3);

	scanf("%d", &n);

	switch (n) {
	case 1:preorder(F1); break;
	case 2:preorder(F2); break;
	case 3:preorder(F3); break;
	case 4:preorder(F4); break;
	case 5:preorder(F5); break;
	case 6:preorder(F6); break;
	case 7:preorder(F7); break;
	case 8:preorder(F8); break;
	default:printf("-1");
	}

	free(F1);
	free(F2);
	free(F3);
	free(F4);
	free(F5);
	free(F6);
	free(F7);
	free(F8);
}