#include <stdio.h>
int main()
/*{
	int a;
	scanf("%d",&a);
	printf("%d만%d천%d백%d십%d",a/10000,a/1000%10,a/100%10,a/10%10,a%10);
	return 0;
}*/
/*{
	int a;
	scanf("%d",&a);
	printf("%d:%02d:%02d",a/3600,(a-(a/3600*3600))/60,a%60);
	return 0;}*/
/*{
	int a;
	scanf("%d",&a);
	printf("%d",a/100%10);
	return 0;}*/
/*{
	float a;
	scanf("%f",&a);
	printf("%.0f",a/(2*3.14)*a/(2*3.14)*3.14);
	return 0;}*/
/*{
	int a;
	scanf("%d",&a);
	printf("%d",(a+500)/1000*1000);]


	return 0;
}*/
/*{
	int a;
	scanf("%d",&a);
	a>=20&&a<=30?printf("1"):printf("0");
	return 0;}*/
/*{
	 int a,b;
	 scanf("%d%d",&a,&b);
	 a>b ? (printf("%d\n%d",a/b,a%b)):(printf("%d\n%d",b/a,b%a));
	 return 0;}*/
/*{
	char a;
	scanf("%c",&a);
	a>='A'&&a<='Z'&&a>='a'&&a<='z'?(printf("1")):(printf("0"));
	return 0;}*/
/*{ int a;
printf("날짜를 입력하세요:");
scanf("%d",&a);
switch(a%7)
{ case 1:printf("화요일");break;
  case 2:printf("수요일");break;
  case 3:printf("목요일");break;
  case 4:printf("금요일");break;
  case 5:printf("토요일");break;
  case 6:printf("일요일");break;
  default:printf("월요일");break;}
return 0;}*/
/*{
	int a;
	printf("주민번호 뒷자리 첫 번째 번호를 입력하세요.");
	scanf("%d",&a);
	switch(a)
	{case 1:case 3:case 9:printf("남성");break;
	 case 0:case 2:case 4:printf("여성");break;
	default:printf("외국인");break;
	}return 0;}*/
/*{
	char a;
	scanf("%c",&a);
	switch(a)
	{
	case 'T':case 't':printf("Tigers");break;
	case 'E':case 'e':printf("Eagles");break;
	case 'B':case 'b':printf("Bears");break;
	default:printf("none");
	}return 0;}*/
{
	int a;
	int b;
	int c;
    int d;
	scanf("%d",&a);
	switch(a)
	{case 0:case 3:case 4:case 7:printf("13*13=");scanf("%d",&b);if(b==169)printf("맞음");else printf("틀림");break;
	case 1:case 2:case 9:printf("17*17=");scanf("%d",&c);if(c==289)printf("맞음");else printf("틀림");break;
		case 5:case 6:case 8:printf("19*19=");scanf("%d",&d);if(d==169)printf("맞음");else printf("틀림");break;
		default:printf("none");}
	return 0;}







