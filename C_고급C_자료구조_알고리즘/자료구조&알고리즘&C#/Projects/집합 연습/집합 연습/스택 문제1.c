void inorder_stack(TreeNode* root) {
	TreeNode* indexnode = root;
	Stack* s=(Stack*)malloc(sizeof(Stack));
	
	while (1) {
		while (indexnode != NULL) {
			push(indexnode);
			indexnode = indexnode->left;//�������� �̵�
		}
		if (!is_empty(indexnode)) {
			indexnode = pop(s);
			printf("%d", indexnode->data);
			indexnode = indexnode->right;
		}
		else break;
	}
}//���ÿ� ��带 ���� �� �� �ִ���? �ñ� �ñ� 