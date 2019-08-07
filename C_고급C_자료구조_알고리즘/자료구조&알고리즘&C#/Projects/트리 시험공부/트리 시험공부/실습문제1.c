#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode{
	int data;
	struct TreeNode *left, *right;
}TreeNode;

typedef struct Queue {
	TreeNode *data;
	int front, rear;
}Queue;

TreeNode* create_node(int data) {
	TreeNode *t = (TreeNode*)malloc(sizeof(TreeNode));
	t->data = data;
	t->left = NULL;
	t->right = NULL;
	return t;
}

void insert(TreeNode **root,int data) {
	TreeNode *t = *root;
	TreeNode *p = NULL;
	if ((*root) == NULL) {
		*root = create_node(data);
	}
	else {
		while (t != NULL) {
			p = t;
			if (data < t->data) {
				t = t->left;
			}
			else t = t->right;
		}
		
		if (data < p->data) {
			p->left = create_node(data);
		}
		else {
			p->right = create_node(data);
		}
	}
}

void enqueue(TreeNode* t, Queue **q) {
	
}//queue

void levelorder(TreeNode *root) {
	Queue *q = (Queue*)malloc(sizeof(Queue));
	q->front = 0;
	q->rear = 0;
	TreeNode *t = root;

	enqueue(t);
	while (t != NULL) {
		//전위순회처럼 한다음에 각각 서브트리 queue에 저장
		if(
		enqueue(t->left);
		enqueue(t->right);
	}
	
}

void main() {
	TreeNode *root=NULL;
	int n,i,data,dn;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &data);
		insert(&root, data);
	}
	
	scanf("%d", &dn);

}