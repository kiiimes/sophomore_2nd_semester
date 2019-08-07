#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;//노드 데이터
	struct ListNode* link;//다음 노드의 주소
}ListNode;

ListNode *create_node(element data, ListNode* link) {
	ListNode* list;

	list = (ListNode*)malloc(sizeof(ListNode));

	list->data = data;
	list->link = link;

	return list;
	
}//노드 생성 함수

void insert_node(ListNode **phead, ListNode *p, ListNode *New) {
	int i;
	if (*phead == NULL) {
		*phead = New;
		New->link = NULL;
		return ;
	}
	
	else if (p == NULL) {
		New->link = *phead;
		phead = New;
	}

	else {
		New->link = p->link;
		p->link = New;
	}
}//노드 추가 함수

void remove_node(ListNode **phead, ListNode *p, ListNode *now) {
	//p가 null 인경우랑 중간 노드 삭제하는 경우 끝노드 삭제하는 경우
	if (p == NULL) {
		*phead = now->link;
		
	}
	else if (now->link == NULL) {
		p->link = NULL;
		
	}
	else {
		p->link = now->link;
	}
	free(now);
	now->link = NULL;

}//삭제 함수

void display(ListNode *head) {
	ListNode *p;

	p = head;

	while (p->link != NULL) {
		printf("%d->", p->data);
		p = p->link;
	}
	printf("NULL");

}//보여주는 함수
//여기서는 head를 굳이 이중포인터 쓸 필요 없음 왜냐면 헤드가 바뀔 일이 없기 때문

ListNode* search(ListNode *head,ListNode *p) {//p가 찾으려는 노드
	
	while (head != NULL) {
		if (p == head) {
			return head;
		}
		head = head->link;
	}
}

void main() {
	ListNode *list1 = NULL, *list2 = NULL;
	ListNode *p;

		insert_node(&list1, create_node(30, NULL));
		insert_node(&list1, create_node(20, NULL));
	





}