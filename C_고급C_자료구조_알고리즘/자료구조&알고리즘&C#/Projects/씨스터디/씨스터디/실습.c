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

//�߰�

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
	// ����ִ°Ÿ� ������ ���� �ľ��� ������ ����־�� ��

	prev = NULL;

	//�ؿ� �ڵ�� �׳� ���� ����ִ� �ڵ�ϱ� �̰Ÿ� ���� ���� ���� x
	//���ο� �뵵�� ���� ���� ���� ���� ��忡 ����
	//�״����� �� �� ��带 ���ο� ��忡 ����
	
	cur = L->head;
	// (b,a)�� ���Ѵٰ� ������ �ƽ�Ű�ڵ� ���ڰ� ū�� ���̸� >0 (b-a)>0 ���� �����սôپƾƾƾƾƾƾƾƾӤ�
	//L->head �� ���� ���°� �ƴ϶� L->head �� a
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



//����

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



//�˻�

void searchListNode(linkedList_h *L, char *findName)

{

	listNode* p;

	p = L->head;



	while (p != NULL)

	{

		if (!strcmp(p->data.name, findName))

		{

			printf("�ش� �л��� �����մϴ�.\n");

			break;

		}

		else

			p = p->link;

	}//while (p != NULL)

}





//���

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



//���Ḯ��Ʈ



//1. �ؽ�Ʈ����(data.txt)�� ����Ǿ��ִ� ȸ������ �ҷ�����(�б���)



void initGetMember(linkedList_h *L)

{

	FILE * fp = fopen("data.txt", "rt");
	struct Student temp;
	char str[100];

	//������ �ִ��� Ȯ���ؾ��ϴϱ� if������ null Ȯ���ϰ� -1 return.

	if (fp == NULL)

	{
		printf("���� ���� ����\n");
		return;

	}



	while (!feof(fp)) // ���ϴݱ�(fclose) �����ϸ� 0�� ��ȯ, �����ϸ� EOF�� ��ȯ

	{

		//�� �پ� �о�� �ؽ�Ʈ�� �ٽ� ���Ḯ��Ʈ �ش�.

		if (fread((void*)&temp, sizeof(temp), 1, fp) == 0)

			break;

		//2. �ҷ��� ������ �ٽ� ���Ḯ��Ʈ�� ���

		addListNode(L, temp);

	}



}



// 3. �߰��� �� -> �ش� �޼ҵ带 �̿��ؼ� �ؽ�Ʈ�� �߰��ϸ� �˴ϴ�.

int writeTxt(struct Student data)

{
	FILE * fp = fopen("data.txt", "a");
	if (fp == NULL)

	{

		printf("���� ���� ����\n");

		return -1;

	}


	fwrite((void*)&data, sizeof(data), 1, fp);

	fclose(fp);


	return 0;

}





//4.(1)������ txt ����
//(2) ������ ���Ḯ��Ʈ �߰� 
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

//���1



strcpy(str, "�̸� : ");

strcat(str, data.name);



strcat(str, " / �й� : ");



int -> ���ڿ�

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

		printf("  ---- ��� �Է� ----\n");

		printf("  1. ���\n");

		printf("  2. �߰�\n");

		printf("  3. ����\n");

		printf("  4. �˻�\n");

		printf("  5. ����\n");



		scanf("%d", &mode);



		switch (mode)

		{

		case 1:

			printList(L);

			break;



		case 2:

			//�߰�

			printf("  �̸� �Է� : ");

			scanf("%s", input.name);

			printf("  �й� �Է� : ");

			scanf("%d", &input.id);

			addListNode(L, input);

			writeTxt(input);

			break;



		case 3:

			deleteListNode(L);


			break;



		case 4:

			printf("  �̸� �Է� : ");

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