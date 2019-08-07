#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int key;
	struct TreeNode *left, *right;
}TreeNode;

typedef struct Queue {
	struct TreeNode* data[20];
	int front, rear;
}Queue;

void enqueue(Queue **q,TreeNode *node) {
	if (node == NULL) {
		return;
	}
	else if ((*q)->front == ((*q)->rear + 1) % 20) {
		printf("꽉 찼어요");
	}
	else {
		(*q)->rear = ((*q)->rear + 1) % 20;
		(*q)->data[((*q)->rear)] = node;
	}
}

TreeNode* dequeue(Queue **q) {
	(*q)->front = ((*q)->front + 1) % 20;
	return (*q)->data[(*q)->front];
}

TreeNode* create_node(int data) {
	TreeNode *t = (TreeNode*)malloc(sizeof(TreeNode));
	t->key = data;
	t->left = NULL;
	t->right = NULL;
	return t;
}


void insert(TreeNode **root, int data) {
	TreeNode *t = *root;
	TreeNode *p = NULL;
	if (*root == NULL) {
		*root = create_node(data);
	}
	else {
		while (t != NULL) {
			p = t;
			if (data < t->key) {
				t = t->left;
			}
			else if (t->key == data) {
				return;
			}
			else t = t->right;
		}
		if (data < p->key) {
			p->left = create_node(data);
		}
		else p->right = create_node(data);
	}
}

void print(TreeNode *root) {
	Queue *q = (Queue*)malloc(sizeof(Queue));
	q->front = 0;
	q->rear = 0;
	TreeNode *t = root;
	TreeNode *sav;
	enqueue(&q,root);
	if (root == NULL) {
		return;
	}
	while (q->front != q->rear) {
		sav = dequeue(&q);

		if (sav != NULL) {
			printf(" %d", sav->key);
			enqueue(&q, sav->left);
			enqueue(&q, sav->right);
		}
	}
	
}

//탐색

/*TreeNode* search(TreeNode *root,int key) {
	TreeNode *t = root;
	TreeNode *asav,*bsav;
	if (t == NULL) {
	}
	else {
		if (t->key== key) {
			return t;
		}
		asav=search(t->left,key);
		bsav=search(t->right,key);
		
		if (asav != NULL) {

			if (asav->key == key) {
				return asav;
			}
		}
		else if (bsav != NULL) {
			if (bsav->key == key) {
				return bsav;
			}
		}
		
	}
}*/

/*TreeNode* search(TreeNode *root, int key) {
	TreeNode *t = root;
	TreeNode *p = NULL;
	if (t == NULL) {
		return;
	}
	else {
		while (t != NULL) {
			p = t;
			if (t->key == key) {
				return t;
			}
			else if (t->key > key) {
				t = t->left;
			}
			else t = t->right;
		}
		return NULL;
	}
	
}*/

/*TreeNode* search(TreeNode *root) {
	int acount = 0,bcount=0;
	if (root == NULL) {
		return 0;
	}
	else {
		acount = search(root->left);
		bcount = search(root->right);

		return 1 + acount + bcount;
	}
}*/

int maxx(int ah, int bh) {
	if (ah > bh) {
		return ah;
	}
	else return bh;
}

/*int search(TreeNode *root) {
	int aheight = 0, bheight = 0;
	if (root == NULL) {
		return 0;
	}
	else {
		aheight = search(root->left);
		bheight = search(root->right);
		return 1 + maxx(aheight, bheight);
	}
}*/

TreeNode* search(TreeNode **root) {
	TreeNode *temp;
	if ((*root) == NULL) {
		return;
	}
	else {
		if ((*root)->left != NULL&&(*root)->right!=NULL) {
			temp = (*root)->left;
			(*root)->left = (*root)->right;
			printf("%d", (*root)->left->key);
			(*root)->right = temp;
			printf("%d", (*root)->right->key);
			search(&((*root)->left));
			search(&((*root)->right));
		}
	}
}

/*int del(TreeNode *root, int key) {
	TreeNode *t = root,*p=NULL,*succ_p,*succ;
	int sav;

	while (t != NULL||key==t->key) {
		p = t;
		t=(key < t->key) ? t->left : t->right;
	}
	if (t == NULL) {
		return;
	}//key가 여기 트리 안에 없는거니까 그럴땐 그냥 끝내 버리지 뭐 히히 

	if (t->left == NULL&&t->right == NULL) {
		sav = t->key;
		if(root
		if (p->left == t) {
			p->left = NULL;
		}
		else {
			p->right = NULL;
		}
		free(t);
	}
	else if (t->left == NULL || t->right == NULL) {
		if (t->left != NULL) {
			if (p->left == t) {
				p->left = t->left;
			}
			else p->right = t->left;
		}
		else {
			if (p->left == t) {
				p->left = t->right;
			}
			else p->right = t->right;
		}
		free(t);
	}
	else {
		succ_p = NULL;
		succ = t;
		if (p!= NULL) {

		}
		else {
			
		}

	}

}*/





void main() {
	TreeNode *root = NULL;
	char type;
	int data;
	while (1) {
		printf("******************\n");
		printf("i:입력\n");
		printf("d:삭제\n");
		printf("s:탐색\n");
		printf("p:출력\n");
		printf("q:종료\n");
		printf("******************\n");


		scanf("%c", &type);
		getchar();
		switch (type) {
		case 'i':scanf("%d", &data); getchar(); insert(&root, data); break;
		case 'd':break;
		case 's':search(&root); break;
		case 'p':print(root); break;
		case 'q':break;
		}
		if (type == 'q') {
			break;
		}
	}

}