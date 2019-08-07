#include <stdio.h>
int main1()
{
	int num1;
	scanf("%d",&num1);
	printf("%o\n%x",num1,num1);
	return 0;
}
int main2()
{
	int n;
	scanf("%d",&n);
	if(n<1000)
	{
		printf("0");
			}
	else if(n>=1000){
	
		printf("%d",(n+5000)/10000*10000);

	}

	return 0;}
int main3()
{
	int grade,num1,num2;
	scanf("%d %d %d",&grade,&num1,&num2);
	if(grade>=1&&grade<=3){
		printf("%d %d",num1/num2,num1%num2);
	}
	else if(grade>=4&&grade<=6){
		printf("%.2f",(float)num1/num2);
	}

	return 0;
}
int main4()
{
	int i;
	char n;
	for(i=1;;i++){
	scanf("%c",&n);
	if(n>='A'&&n<='Z')
	{
		printf("%c",'a'+(n-'A'));
	}
	else if(n>='a'&&n<='z')
	{
		printf("%c",'A'+(n-'a'));
	}
	else if(n>='0'&&n<='9')
	{
		break;
	}
	else
	{
		printf("");
	}
	}

	return 0;
	
}
int main5()
{
	int a, b, c, d, e, f, g, h, i;
   int O = 0, S = 0, B = 0;
   scanf("%d%d%d", &a, &b, &c);
   scanf("%d%d%d", &d, &e, &f);
   scanf("%d%d%d", &g, &h, &i);

   if (a == d || a == g)
   {
      if (a == d && a == g)
      {
         O++;
      }
      else 
      {
         S++;
      }
   }

   else if (a == e || a == f || a == h || a == i)
   {
      B++;
   }

   if (b == e || b == h)
   {
      if (b == e && b == h)
      {
         O++;
      }
      else
      {
         S++;
      }
   }

   else if (b == d || b == f || b == g || b == i)
   {
      B++;
   }
   
   if (c == f || c == i)
   {
      if (c == f && c == i)
      {
         O++;
      }
      else
      {
         S++;
      }
   }
   
   else if (c == d || c == e || c == g || c == h)
   {
      B++;
   }

   printf("%dO\n%dS\n%dB",O,S,B);
	return 0;
}
int main6()
{
	int i,j,count1,n,s,sum=0,a;
	scanf("%d %d",&n,&s);
	for(i=n;sum<=s;i++){
		count1=0;
		for(j=1;j<=i;j++){
			if(i%j==0){
				count1++;
			}
		}
			if(count1==2){
				sum+=i;
				a=i;

			}
		
		}
	printf("%d\n%d",sum,a);
	
		
	return 0;
}
int main7()
{
	int i,j,k,n;
	char a;
	scanf("%d",&n);
	if(n%2==0){
	for(i=1;i<=n/2;i++){
		for(j=1;j<=n/2-i;j++){
			printf("+");
		}
		for(k=1;k<=n/2-(j-1);k++){
			printf("#");
		}
	printf("\n");
	}
	for(i=0;i<=n/2-1;i++){
		for(j=0;j<i;j++){
			printf("+");
		}
		for(k=1;k<=n/2-i;k++){
			printf("#");
		}
printf("\n");
	}
	}
	if(n%2!=0){
		for(i=1;i<=n/2+1;i++){
		for(j=1;j<=n/2+1-i;j++){
			printf("+");
		}
		for(k=1;k<=n/2+1-(j-1);k++){
			a='A';
			printf("%c",a-1+k);
		}
	printf("\n");
	}
		for(i=1;i<=n/2;i++){
		for(k=1;k<=n/2-(i-1);k++){
			a='A';
			printf("%c",a-1+k);
		}
		for(j=1;j<=i;j++){
			printf("+");
		}
	printf("\n");
	}
	}
	return 0;
}
int main()
{
	int pro_num=0;
	scanf("%d\n",&pro_num);
	switch(pro_num){
	case 1:main1();break;
	case 2:main2();break;
	case 3:main3();break;
	case 4:main4();break;
	case 5:main5();break;
	case 6:main6();break;
	case 7:main7();break;

	}

	return 0;
}