#include <stdio.h>
int main1()
{
	
}
int main2()
{
	int t,u;
	scanf("%d %d",&t,&u);
	if(u==1||u==2||u==5||u==7||u==8||u==10||u==12)
		printf("31");
	else if(u==4||u==6||u==9||u==11)
		printf("30");
	else if(t%4==0&&t/4%100!=0&&u==2)
		printf("29");
	else if(t%4==0&&t/4/100%400==0&&u==2)
		printf("29");
	else if(t%4!=0&&u==2)
		printf("28");
	else if(t%4==0&&t/4%100==0&&t/4/100%400!=0&&u==2)
		printf("28");
}
int main3()
{
	
}
int main4()
{
	
}
int main5()
{

}
int main()
{
int pro_num=0;
scanf("%d\n",&pro_num);
switch(pro_num){
case 1: main1(); break;
case 2: main2(); break;
case 3: main3(); break;
case 4: main4(); break;
case 5: main5(); break;
}
return 0;
}