#define SIZE 100//전처리기
#include <stdio.h>
#include <string.h>
#include <stdlib.h>// 기본 헤더파일 포함
#pragma warning (disable : 4996)

typedef struct contact
{
   char name[21];//이름 배열 20byte
   s + 1(NULL)
   char num[16];//전화번호 배열 15bytes + 1 (NULL)
   char bir[9];//생일 배열 9bytes + 1 (NULL)

}contact;//구조체 선언
void sort(contact *info, int *current_pos)
{
   int i, j;
   contact temp;//자리바꾸는데 이용할 임시 저장 구조체 변수 선언

   for (i = 1; i < *current_pos + 1; i++)
   {
      for (j = 0; j < *current_pos + 1 - i; j++)
      {
         if (strcmp(info[j].name, info[j + 1].name) > 0)//오름차순 정렬
         {
            temp = info[j];
            info[j] = info[j + 1];
            info[j + 1] = temp;//자리바꿈
         }
      }
   }//버블정렬
}//sort함수
int Check_Overflow(int *current_pos)
{
   if (*current_pos > 100) return 1;//오버플로우일 경우 1 return
   else return 0;//아닐 경우 0 return
}//오버플로우 체크함수
void Registration(contact *info, int *current_pos)
{
   if (!Check_Overflow(current_pos))//오버플로우 체크함수로 확인하여 오버플로우 아니면
   {
      printf("Name:");
      scanf("%s", info[*current_pos].name);
      printf("Phone_number:");
      scanf("%s", info[*current_pos].num);
      printf("Birth:");
      scanf("%s", info[*current_pos].bir);
      sort(info, current_pos);
      printf("<<%d>>\n", (*current_pos) + 1);//current_pos는 배열을 사용할때 위치기 때문에 실제 저장 개수는 +1을 해줌
      (*current_pos)++;
   }//입력받음
   else if (Check_Overflow(current_pos))
   {
      printf("OVERFLOW\n");
   }//오버플로우일 경우 OVERFLOW 출력
}
void ShowAll(contact *info, int *current_pos)
{
   int i;

   for (i = 0; i < *current_pos; i++)
   {
      printf("%s %s %s\n", info[i].name, info[i].num, info[i].bir);
   }//처음부터 CURRENT_POS위치까지 출력
}
void Delete(contact *info, int *current_pos)
{
   char namet[21];//이름비교위해 지역변수 선언
   int i, j;

   if (*current_pos == 0)
   {
      printf("NO MEMBER\n");
   }//current_pos가 0일경우 현재 배열에 값이 없으므로 NO MEMBER 출력
   else
   {
      printf("Name:");
      scanf("%s", namet);//namet변수에 비교할 이름 입력받음

      for (i = 0; i < *current_pos; i++)//반복문 처음부터 현재 위치까지
      {
         if (strcmp(namet, info[i].name) == 0)//strcmp함수를 이용 값이 0이 나올경우 같은 문자열
         {
            for (j = i; j < *current_pos; j++)
            {
               info[j] = info[j + 1];
            }// i부터  current_pos까지 한칸씩 앞으로 당김
            for (j = 0; info[*current_pos].name[j]; j++)
            {
               info[*current_pos].name[j] = '\0';
               info[*current_pos].num[j] = '\0';
               info[*current_pos].bir[j] = '\0';
            }//마지막 current_pos위치에 있는 문자열들 널문자로 초기화

            (*current_pos)--;// 한칸씩 앞당겨졌으므로 current_pos에서 1을 뺌
         }
      }

   }
}
void FindByBirth(contact *info, int *current_pos)
{
   int mon;//비교할 생일 달 변수 선언
   int i;

   printf("Birth:");
   scanf("%d", &mon);//정수형으로 입력 받은후

   for (i = 0; i < *current_pos; i++)
   {
      if (mon < 10)//10월보다 이전 달의 경우
      {
         if (info[i].bir[4] == '0')//월의 첫자리는 0
         {
            if (info[i].bir[5] == mon + '0')//월의 둘째자리는 mon으로 입력받은 정수값 + 아스키코드값(0)
            {
               printf("%s %s %s\n", info[i].name, info[i].num, info[i].bir);//같은 경우 출력
            }
         }
      }
      else if (mon >= 10)//10월 이후 달의 경우
      {
         if (info[i].bir[4] == '1')//월의 첫자리는 1
         {
            if (info[i].bir[5] == mon % 10 + '0')//월의 둘째자리는 mon을 10으로 나눈 나머지 값 + 아스키코드(0)
            {
               printf("%s %s %s\n", info[i].name, info[i].num, info[i].bir);//같은경우 출력
            }
         }
      }
   }
}

int main()
{
   int n;//메뉴에서 입력받을 변수 선언
   contact info[SIZE];//전처리기에서 선언한 SIZE크기만큼 선언
   int current_pos = 0;//현재 작업이 이루어지고 있는 위치 변수 선언



   while (1)//무한반복
   {
      printf("*****Menu*****\n");
      printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
      printf("Enter_the_menu_number:");//프로그램 메뉴 출력

      scanf("%d", &n);//n입력받음

      switch (n)//입력 받은 n에 따라 결정
      {
      case 1: Registration(info, &current_pos); break;
      case 2: ShowAll(info, &current_pos); break;
      case 3: Delete(info, &current_pos); break;
      case 4: FindByBirth(info, &current_pos); break;//각각 메뉴에 해당하는 함수 호출
      case 5: return 0;//프로그램 종료
      }

   }
}