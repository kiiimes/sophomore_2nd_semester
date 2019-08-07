#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct TreeNode {
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;


TreeNode* create_node(int item) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->data = item;
	return node;
}

void insert_node(TreeNode** root,int item, int left, int right) {
	TreeNode *t;
	*root=t;

	if (t == NULL) {
		t = create_node(item);
		if (left == 0) {
			t->left=create_node(NULL);
		}
		else if (right == 0) {
			t->right = create_node(NULL);
		}
		else {
			t->left = create_node(left);
			t->right = create_node(right);
		}
	}
	else {
		while (t != NULL) {
			if (t->data == item) {
				if (left == 0) {
					t->left = create_node(NULL);
				}
				else if (right == 0) {
					t->right = create_node(NULL);
				}
				else {
					t->left = create_node(left);
					t->right = create_node(right);
				}
			}
			else if (t->data > item) {
				t = t->right;
			}
			else {
				t = t->left;
			}
		}
		
	}

}

void main() {
	TreeNode* root=NULL;
	int item, left, right;
	char str[101];

	int n,i,snum;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d %d %d", &item, &left, &right);
		insert_node(&root,item, left, right);
	}

	printf(" %d %d %d", root->data, root->left->data, root->right->data);

	/*scanf("%d", &snum);

	for (i = 0; i < snum; i++) {
		getchar();
		scanf("%s", str);
		search(root);
	}
	*/






}