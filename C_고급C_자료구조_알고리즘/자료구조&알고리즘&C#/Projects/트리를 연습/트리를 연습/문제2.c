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

TreeNode* create_node(int item, int id, TreeNode* left, TreeNode* right) {
	TreeNode* new = (TreeNode*)malloc(sizeof(TreeNode));
	new->data = item;
	new->id = id;
	new->left = left;
	new->right = right;
	return new;
}

/*TreeNode* search(TreeNode* root) {
	TreeNode* node;
	if(root->id==nid){



	if (root) {
		search(root->left);
		search(root->right);
		
	}
}*/

int calc_size(TreeNode* root) {//sum 을 반환해야함
	int left_dir=0, right_dir=0;
	if (root) {
		left_dir = calc_size(root->left);
		right_dir = calc_size(root->right);
		return (root->data + left_dir + right_dir);
	}
	else {
		return 0;
	}
}

void freedom(TreeNode *root) {
	if (root) {
		freedom(root->left);
		if (root->left == NULL&&root->right == NULL) {
			free(root);
		}
		else {
			freedom(root->right);
		}
	}
}

void main() {
	TreeNode *root = (TreeNode*)malloc(sizeof(TreeNode));

	TreeNode *F1, *F2, *F3, *F4, *F5, *F6, *F7, *F8;

	int type, i, nid,sum=0;
	root = NULL;

	scanf("%d",&nid);

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

/*	printf("%d", searchpre(root, nid)->id);

	if (searchpre(root, nid) == NULL) {
		printf("-1");
	}
	else {
		printf("%d", calc_size(searchpre(root, nid)));
	}*/
	
	freedom(root);

	printf(" %d %d %d", root->data, root->left->data, root->right->data);

	if (root == NULL) {
		printf("성공");
	}
	


}