void inorder_stack(TreeNode* root) {
	TreeNode* indexnode = root;
	Stack* s=(Stack*)malloc(sizeof(Stack));
	
	while (1) {
		while (indexnode != NULL) {
			push(indexnode);
			indexnode = indexnode->left;//왼쪽으로 이동
		}
		if (!is_empty(indexnode)) {
			indexnode = pop(s);
			printf("%d", indexnode->data);
			indexnode = indexnode->right;
		}
		else break;
	}
}//스택에 노드를 저장 할 수 있는지? 궁금 궁금 