#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
}TreeNode;

int calc_direc_size(TreeNode *root) {
	int left_dir, right_dir;
	if (root) {
		left_dir = calc_size(root->left);
		right_dir = calc_size(root->right);
		return (root->data + left_dir + right_dir);
	}
}

void main() {

	TreeNode F8 = { 80,NULL,NULL };
	TreeNode F7 = { 130,NULL,NULL };
	TreeNode F6 = { 120,&F7,&F8 };
	TreeNode F5 = { 90,NULL,NULL };
	TreeNode F4 = { 70,NULL,NULL };
	TreeNode F3 = { 50,NULL,&F6 };
	TreeNode F2 = { 30,&F4,&F5 };
	TreeNode F1 = { 20,&F2,&F3 };

	printf("디렉토리 크기=%d\n", calc_direc_size(&F1));
	
}