#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int id;
	int data;
	struct TreeNode *left, *right;
}TreeNode;

TreeNode* create_node(int id, int data, TreeNode* left, TreeNode *right) {
	TreeNode *t = (TreeNode*)malloc(sizeof(TreeNode));

	t->id = id;
	t->data = data;
	t->left = left;
	t->right = right;

	return t;
}

TreeNode* search(TreeNode *root, int key) {
	TreeNode *t = root;
	TreeNode *sav1, *sav2;
	if ( t == NULL) {
		return NULL; 
	}
	if (t->id == key) {
		return t;
	}
	else {
		sav1 = search(t->left,key);
		sav2 = search(t->right, key);
		if (sav1!=NULL){
			if (sav1->id == key) {
				return sav1;
			}
		}
		else if (sav2 != NULL) {
			if (sav2->id == key) {
				return sav2;
			}
		}
		else {
			return NULL;
		}
		
	}
}

int sum(TreeNode *root) {
	TreeNode* t = root;
	int left_size=0, right_size=0;

	if (t != NULL) {
		left_size = sum(t->left);
		right_size = sum(t->right);
		return t->data + left_size + right_size;
	}

}


int main() {
	TreeNode *F1, *F2, *F3, *F4, *F5, *F6, *F7, *F8,*root;
	int key;

	F8 = create_node(8, 80, NULL, NULL);
	F7 = create_node(7, 130, NULL, NULL);
	F6 = create_node(6, 120, F7, F8);
	F5 = create_node(5, 90, NULL, NULL);
	F4 = create_node(4, 70, NULL, NULL);
	F3 = create_node(3, 50, NULL, F6);
	F2 = create_node(2, 30, F4, F5);
	F1 = create_node(1, 20, F2, F3);

	root = F1;
	
	scanf("%d", &key);

	if (key < 1 || key>8) {
		printf("-1");
		return;
	}

	printf("%d", sum(search(root, key)));

	free(F8);
	free(F7);
	free(F6);
	free(F5);
	free(F4);
	free(F3);
	free(F2);
	free(F1);

	return;

}