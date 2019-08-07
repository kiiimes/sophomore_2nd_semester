#define SIZE 100//��ó����
#include <stdio.h>
#include <string.h>
#include <stdlib.h>// �⺻ ������� ����
#pragma warning (disable : 4996)

typedef struct contact
{
   char name[21];//�̸� �迭 20byte
   s + 1(NULL)
   char num[16];//��ȭ��ȣ �迭 15bytes + 1 (NULL)
   char bir[9];//���� �迭 9bytes + 1 (NULL)

}contact;//����ü ����
void sort(contact *info, int *current_pos)
{
   int i, j;
   contact temp;//�ڸ��ٲٴµ� �̿��� �ӽ� ���� ����ü ���� ����

   for (i = 1; i < *current_pos + 1; i++)
   {
      for (j = 0; j < *current_pos + 1 - i; j++)
      {
         if (strcmp(info[j].name, info[j + 1].name) > 0)//�������� ����
         {
            temp = info[j];
            info[j] = info[j + 1];
            info[j + 1] = temp;//�ڸ��ٲ�
         }
      }
   }//��������
}//sort�Լ�
int Check_Overflow(int *current_pos)
{
   if (*current_pos > 100) return 1;//�����÷ο��� ��� 1 return
   else return 0;//�ƴ� ��� 0 return
}//�����÷ο� üũ�Լ�
void Registration(contact *info, int *current_pos)
{
   if (!Check_Overflow(current_pos))//�����÷ο� üũ�Լ��� Ȯ���Ͽ� �����÷ο� �ƴϸ�
   {
      printf("Name:");
      scanf("%s", info[*current_pos].name);
      printf("Phone_number:");
      scanf("%s", info[*current_pos].num);
      printf("Birth:");
      scanf("%s", info[*current_pos].bir);
      sort(info, current_pos);
      printf("<<%d>>\n", (*current_pos) + 1);//current_pos�� �迭�� ����Ҷ� ��ġ�� ������ ���� ���� ������ +1�� ����
      (*current_pos)++;
   }//�Է¹���
   else if (Check_Overflow(current_pos))
   {
      printf("OVERFLOW\n");
   }//�����÷ο��� ��� OVERFLOW ���
}
void ShowAll(contact *info, int *current_pos)
{
   int i;

   for (i = 0; i < *current_pos; i++)
   {
      printf("%s %s %s\n", info[i].name, info[i].num, info[i].bir);
   }//ó������ CURRENT_POS��ġ���� ���
}
void Delete(contact *info, int *current_pos)
{
   char namet[21];//�̸������� �������� ����
   int i, j;

   if (*current_pos == 0)
   {
      printf("NO MEMBER\n");
   }//current_pos�� 0�ϰ�� ���� �迭�� ���� �����Ƿ� NO MEMBER ���
   else
   {
      printf("Name:");
      scanf("%s", namet);//namet������ ���� �̸� �Է¹���

      for (i = 0; i < *current_pos; i++)//�ݺ��� ó������ ���� ��ġ����
      {
         if (strcmp(namet, info[i].name) == 0)//strcmp�Լ��� �̿� ���� 0�� ���ð�� ���� ���ڿ�
         {
            for (j = i; j < *current_pos; j++)
            {
               info[j] = info[j + 1];
            }// i����  current_pos���� ��ĭ�� ������ ���
            for (j = 0; info[*current_pos].name[j]; j++)
            {
               info[*current_pos].name[j] = '\0';
               info[*current_pos].num[j] = '\0';
               info[*current_pos].bir[j] = '\0';
            }//������ current_pos��ġ�� �ִ� ���ڿ��� �ι��ڷ� �ʱ�ȭ

            (*current_pos)--;// ��ĭ�� �մ�������Ƿ� current_pos���� 1�� ��
         }
      }

   }
}
void FindByBirth(contact *info, int *current_pos)
{
   int mon;//���� ���� �� ���� ����
   int i;

   printf("Birth:");
   scanf("%d", &mon);//���������� �Է� ������

   for (i = 0; i < *current_pos; i++)
   {
      if (mon < 10)//10������ ���� ���� ���
      {
         if (info[i].bir[4] == '0')//���� ù�ڸ��� 0
         {
            if (info[i].bir[5] == mon + '0')//���� ��°�ڸ��� mon���� �Է¹��� ������ + �ƽ�Ű�ڵ尪(0)
            {
               printf("%s %s %s\n", info[i].name, info[i].num, info[i].bir);//���� ��� ���
            }
         }
      }
      else if (mon >= 10)//10�� ���� ���� ���
      {
         if (info[i].bir[4] == '1')//���� ù�ڸ��� 1
         {
            if (info[i].bir[5] == mon % 10 + '0')//���� ��°�ڸ��� mon�� 10���� ���� ������ �� + �ƽ�Ű�ڵ�(0)
            {
               printf("%s %s %s\n", info[i].name, info[i].num, info[i].bir);//������� ���
            }
         }
      }
   }
}

int main()
{
   int n;//�޴����� �Է¹��� ���� ����
   contact info[SIZE];//��ó���⿡�� ������ SIZEũ�⸸ŭ ����
   int current_pos = 0;//���� �۾��� �̷������ �ִ� ��ġ ���� ����



   while (1)//���ѹݺ�
   {
      printf("*****Menu*****\n");
      printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
      printf("Enter_the_menu_number:");//���α׷� �޴� ���

      scanf("%d", &n);//n�Է¹���

      switch (n)//�Է� ���� n�� ���� ����
      {
      case 1: Registration(info, &current_pos); break;
      case 2: ShowAll(info, &current_pos); break;
      case 3: Delete(info, &current_pos); break;
      case 4: FindByBirth(info, &current_pos); break;//���� �޴��� �ش��ϴ� �Լ� ȣ��
      case 5: return 0;//���α׷� ����
      }

   }
}