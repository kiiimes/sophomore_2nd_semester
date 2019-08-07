#include <stdio.h>
#include <stdlib.h>

int M;

typedef struct ListNode {
	int key;
	struct ListNode *link;
}ListNode;

typedef struct ListType {
	ListNode *head;
}ListType;

ListNode* getNode(int n,ListNode *next) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->key = n;
	p->link = next;
	return p;
}

void insertItem(ListType *list, int n) {
	int i;
	ListNode *New;


		if (list[n%M].head == NULL) list[n%M].head = getNode(n, NULL);
		else {
			New = getNode(n, list[n%M].head);
			list[n%M].head = New;
		}
	
}

void initBucketArray(ListType *list) {
	int i;

	for (i = 0; i < M; i++) {
		list[i].head = NULL;
	}

}

ListNode* findNode(ListType *list, int n) {
	ListNode *p = list[n%M].head;
	int cnt = 1;

	while (p != NULL) {
		if (p->key == n) { 
			printf("%d", cnt);
			return p;
		}
		p = p->link;
		cnt++;
	}
	printf("0");
	return NULL;
}

//search
void findElement(ListType *list,int n) {
	ListNode *p = list[n%M].head;
	int cnt = 1;

	while (p != NULL) {
		if (p->key == n) {
			printf("%d\n", cnt);
			return ;
		}
		p = p->link;
		cnt++;
	}
	printf("0\n");
	
}

//delete
int removeElement(ListType *list, int n) {
	ListNode *p = list[n%M].head;
	ListNode *prev=list[n%M].head;
	int cnt = 1;

	while (p != NULL) {
		if (p->key == n) {
			printf("%d\n", cnt);
			if (p == list[n%M].head) {
				if(p->link==NULL) list[n%M].head = NULL;
				else list[n%M].head = p->link;
			}
			else prev->link = p->link;
			free(p);
			return;
		}
		prev = p;
		p = p->link;
		cnt++;
	}
	printf("0\n");


}

void printNode(ListType* list) {
	int i=0;
	ListNode *p = list[i].head;

	for (i = 0; i < M; i++) {
		p = list[i].head;
		while ( p != NULL) {
			printf("%d ", p->key);
			p = p->link;
		}
	}
	printf("\n");

}//저장된 키들을 순서대로 인쇄

void freedom(ListType *list) {
	ListNode *prev;
	ListNode *p;
	int i;

	for (i = 0; i < M; i++) {
		p=list[i].head;
		while (p != NULL) {
			prev = p;
			p = p->link;
			free(prev);
		}
		free(list[i].head);
	}

}

 void main() {
	ListType *list;
	int n;
	char type;

	scanf("%d", &M);

	list = (ListType*)malloc(sizeof(ListType)*M);

	initBucketArray(list);

	while (1) {
		getchar();
		scanf("%c", &type);
		switch (type) {
		case 'i':scanf("%d", &n); insertItem(list,n); break;
		case 's':scanf("%d", &n); findElement(list, n); break;
		case 'd':scanf("%d", &n); removeElement(list, n); break;
		case 'p':printNode(list); break;
		default:break;
		}
		if (type == 'e') {
			break;
		}
	}

	free(list);// 이거 다시해야됨
}