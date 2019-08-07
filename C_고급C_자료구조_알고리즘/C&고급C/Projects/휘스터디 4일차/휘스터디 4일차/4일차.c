#include<stdio.h>
#include<stdlib.h>

typedef struct _ListNode
{
	//data field  
	int data;

	//link field
	struct _ListNode *link;
}ListNode;
typedef struct _ListHead{
	//int listsize;
	ListNode *link;
}ListHead;

ListNode* InitNode(int data){
	ListNode *pNew=(ListNode*)malloc(sizeof(ListNode));
	pNew->link=NULL;
	pNew->data=data;
	return pNew;
}

void PrintAll(ListHead *pHead)
{

	ListNode *pNow = pHead->link;

	while(pNow!=NULL)
	{
		printf("%d->",pNow->data);
		pNow = pNow->link;
	}
	printf("->NULL\n");

}
void InsertFront(ListHead *pHead,int data){
	ListNode *pNew;
	pNew=InitNode(data);
	pNew->link=pHead->link;
	pHead->link=pNew;


}
void deletefront(ListHead *pHead){
	ListNode *pDel=pHead->link;
	pHead->link=pDel->link;
	free(pDel);


}
void clear(ListHead *pHead){
	
	while(pHead->link!=NULL){
		deletefront(pHead);

	}

}



void main(){
	int i;
	ListHead head;
	head.link=NULL;
	for(i=0;i<5;i++){
		InsertFront(&head,i);
	}
	deletefront(&head);
	deletefront(&head);
	clear(&head);
	
	
}

//삭제하려면 Head를 그 앞에 연결 시키고
//삭제할거를 free(); 시켜줌

