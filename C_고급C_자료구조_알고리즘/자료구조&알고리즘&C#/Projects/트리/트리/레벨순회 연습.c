#include <stdio.h>
#include <stdlib.h>

//레벨순회

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
}TreeNode;

typedefstruct QueNode{
}

void level_order(TreeNode *ptr) {
	QueueType q;
	init(&q);
	if (ptr == NULL) return;
	enqueue(&q, ptr);

	while (!is_empty(&q)) {
		ptr = dequeue(&q);
		printf("%d", ptr->data);
		if(ptr->left)enqueue(&q,ptr->left)
	}
}

void main() {


}