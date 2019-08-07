#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Student
{
	char name[10];
	int id;
}student;



typedef struct listNode

{
	struct Student data;
	struct listNode* link;
}listNode;

typedef struct
{
	listNode* head;
}linkedList_h;

linkedList_h* createLinkedList_h(void)
{
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;
	return L;
}

//추가

void addListNode(linkedList_h *L, struct Student data)

{
	listNode *prev,*cur;
	listNode *p;
	int cnt = 0;
	p = (listNode*)malloc(sizeof(listNode));
	strcpy(p->data.name, data.name);
	p->data.id = data.id;
	p->link = NULL;

	if (L->head == NULL)

	{

		L->head = p;

		return;

	}
	// 끼어넣는거를 순서를 먼저 파악한 다음에 끼어넣어야 됨

	prev = NULL;

	//밑에 코드는 그냥 끝에 끼어넣는 코드니까 이거를 끝에 끼어 넣지 x
	//새로운 노도를 먼저 끼워 넣을 다음 노드에 연결
	//그다음에 그 전 노드를 새로운 노드에 연결
	
	cur = L->head;
	// (b,a)를 비교한다고 했을때 아스키코드 숫자가 큰게 앞이면 >0 (b-a)>0 으로 생각합시다아아아아아아아아앙ㄱ
	//L->head 가 값이 없는게 아니라 L->head 가 a
	                         //


		while (1)

		{                                  //b                a
			if (prev == NULL&&strcmp(cur->data.name, p->data.name) > 0) {
				p->link = cur;
				L->head = p;
				cnt++;
				break;
			}
			else if(prev == NULL&&strcmp(cur->data.name, p->data.name) < 0&&cur->link==NULL) {
				cur->link = p;
				break;
			}

			                 //a            b                         c                b
			else if (strcmp(prev->data.name, p->data.name) < 0 && strcmp(cur->data.name, p->data.name) > 0) {
				
				prev->link = p;
				p->link = cur;
				cnt++;
				break;

			}
			if (cur->link == NULL) {
				break;
			}
			prev = cur;
			cur = cur->link;




		}
	
	if (cnt == 0) {
		cur->link = p;
	}

	



}



//삭제

void deleteListNode(linkedList_h *L)

{

	listNode *previous;

	listNode *current;



	if (L->head == NULL)

		return;



	if (L->head->link == NULL)

	{

		free(L->head);

		L->head = NULL;

		return;

	}

	else

	{

		previous = L->head;

		current = L->head->link;



		while (current->link != NULL)

		{

			previous = current;

			current = current->link;

		}



		free(current);

		previous->link = NULL;

	}



}



//검색

void searchListNode(linkedList_h *L, char *findName)

{

	listNode* p;

	p = L->head;



	while (p != NULL)

	{

		if (!strcmp(p->data.name, findName))

		{

			printf("해당 학생이 존재합니다.\n");

			break;

		}

		else

			p = p->link;

	}//while (p != NULL)

}





//출력

void printList(linkedList_h* L)

{

	listNode* p;

	p = L->head;



	while (p != NULL)

	{

		printf(" %s %d\n", p->data.name, p->data.id);

		p = p->link;

	}

	printf("\n");

}



//연결리스트



//1. 텍스트파일(data.txt)에 저장되어있는 회원정보 불러오기(읽기모드)



void initGetMember(linkedList_h *L)

{

	FILE * fp = fopen("data.txt", "rt");
	struct Student temp;
	char str[100];

	//오류가 있는지 확인해야하니까 if문으로 null 확인하고 -1 return.

	if (fp == NULL)

	{
		printf("파일 열기 실패\n");
		return;

	}



	while (!feof(fp)) // 파일닫기(fclose) 성공하면 0을 반환, 실패하면 EOF를 반환

	{

		//한 줄씩 읽어온 텍스트를 다시 연결리스트 준다.

		if (fread((void*)&temp, sizeof(temp), 1, fp) == 0)

			break;

		//2. 불러온 정보를 다시 연결리스트에 담기

		addListNode(L, temp);

	}



}



// 3. 추가할 때 -> 해당 메소드를 이용해서 텍스트에 추가하면 됩니다.

int writeTxt(struct Student data)

{
	FILE * fp = fopen("data.txt", "a");
	if (fp == NULL)

	{

		printf("파일 열기 실패\n");

		return -1;

	}


	fwrite((void*)&data, sizeof(data), 1, fp);

	fclose(fp);


	return 0;

}





//4.(1)기존의 txt 리셋
//(2) 삭제후 연결리스트 추가 
void resettxt() {

	FILE * fp = fopen("data.txt", "wt");
	fclose(fp);
}

void deltxt(linkedList_h* L) {

	listNode *tmp;
	FILE * fp = fopen("data.txt", "a");

	tmp = L->head;

	while (tmp != NULL)

	{

		writeTxt(tmp->data);
		tmp = tmp->link;

	}

	fclose(fp);

}




/*

//방법1



strcpy(str, "이름 : ");

strcat(str, data.name);



strcat(str, " / 학번 : ");



int -> 문자열

itoa(data.id, temp, 10);

sprintf(temp, "%d", data.id);

*/



void main(int argc, const char * argv[])

{

	linkedList_h* L;

	int mode = 0;

	char name[10];

	struct Student input;

	L = createLinkedList_h();



	initGetMember(L);

	while (1)

	{

		printf("  ---- 모드 입력 ----\n");

		printf("  1. 출력\n");

		printf("  2. 추가\n");

		printf("  3. 삭제\n");

		printf("  4. 검색\n");

		printf("  5. 종료\n");



		scanf("%d", &mode);



		switch (mode)

		{

		case 1:

			printList(L);

			break;



		case 2:

			//추가

			printf("  이름 입력 : ");

			scanf("%s", input.name);

			printf("  학번 입력 : ");

			scanf("%d", &input.id);

			addListNode(L, input);

			writeTxt(input);

			break;



		case 3:

			deleteListNode(L);


			break;



		case 4:

			printf("  이름 입력 : ");

			scanf("%s", name);

			searchListNode(L, name);

			break;



		case 6:

		default:

			return;

			break;

		case 5:
			deleteListNode(L);
			resettxt();
			deltxt(L);

			break;



		}//switch (mode)

	}//while (1)

}