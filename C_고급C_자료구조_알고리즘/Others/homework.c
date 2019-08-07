/*#include <stdio.h>
int main()*/
/*{
	int a;
	int r1,r2,r3,r4,r5;
	scanf("%d",&a);
	r1=a/10000;
	r2=a%10000/1000;
	r3=a%1000/100;
	r4=a%100/10;
	r5=a%10;

	if(r1==1)
		printf("ÀÏ¸¸");

	else if(r1==2)
		printf("ÀÌ¸¸");

	else if(r1==3)
		printf("»ï¸¸");

	else if(r1==4)
		printf("»ç¸¸");

	else if(r1==5)
		printf("¿À¸¸");

	else if(r1==6)
		printf("À°¸¸");

	else if(r1==7)
		printf("Ä¥¸¸");

	else if(r1==8)
		printf("ÆÈ¸¸");

	else if(r1==9)
		printf("±¸¸¸");
	if(r2==1)
		printf("ÀÏÃµ");
	else if(r2==2)
		printf("ÀÌÃµ");
	else if(r2==3)
		printf("»ïÃµ");
	else if(r2==4)
		printf("»çÃµ");
	else if(r2==5)
		printf("¿ÀÃµ");
	else if(r2==6)
		printf("À°Ãµ");
	else if(r2==7)
		printf("Ä¥Ãµ");
	else if(r2==8)
		printf("ÆÈÃµ");
	else if(r2==9)
		printf("±¸Ãµ");
	if(r3==1)
		printf("ÀÏ¹é");
	else if(r3==2)
		printf("ÀÌ¹é");
	else if(r3==3)
		printf("»ï¹é");
	else if(r3==4)
		printf("»ç¹é");
	else if(r3==5)
		printf("¿À¹é");
	else if(r3==6)
		printf("À°¹é");
	else if(r3==7)
		printf("Ä¥¹é");
	else if(r3==8)
		printf("ÆÈ¹é");
	else if(r3==9)
		printf("±¸¹é");
	if(r4==1)
		printf("ÀÏ½Ê");
	else if(r4==2)
		printf("ÀÌ½Ê");
	else if(r4==3)
		printf("»ï½Ê");
	else if(r4==4)
		printf("»ç½Ê");
	else if(r4==5)
		printf("¿À½Ê");
	else if(r4==6)
		printf("À°½Ê");
	else if(r4==7)
		printf("Ä¥½Ê");
	else if(r4==8)
		printf("ÆÈ½Ê");
	else if(r4==9)
		printf("±¸½Ê");
	if(r5==1)
		printf("ÀÏ");
	else if(r5==2)
		printf("ÀÌ");
	else if(r5==3)
		printf("»ï");
	else if(r5==4)
		printf("»ç");
	else if(r5==5)
		printf("¿À");
	else if(r5==6)
		printf("À°");
	else if(r5==7)
		printf("Ä¥");
	else if(r5==8)
		printf("ÆÈ");
	else if(r5==9)
		printf("±¸");
	return 0;}*/
/*
{
	int a,b,c,d,e,f;
	int sum1,sum2,sum3,sum4,sum5,total;
	scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
	if(a>f)
		sum1=3;
	else if(a<f)
		sum1=-2;
	else if(a==f)
		sum1=-1;
	if(b>f)
		sum2=3;
	else if(b<f)
		sum2=-2;
	else if(b==f)
		sum2=-1;
	if(c>f)
		sum3=3;
	else if(c<f)
		sum3=-2;
	else if(c==f)
		sum3=-1;
	if(d>f)
		sum4=3;
	else if(d<f)
		sum4=-2;
	else if(d==f)
		sum4=-1;
	if(e>f)
		sum5=3;
	else if(e<f)
		sum5=-2;
	else if(e==f)
		sum5=-1;
	total=sum1+sum2+sum3+sum4+sum5;
	if(total<0)
		printf("0");
	else if(total>=0)
		printf("%d",total);
	return 0;}*/
/*
{
	int a,b;
	scanf("%d %d",&a,&b);
	if(b==1||b==2||b==5||b==7||b==8||b==10||b==12)
		printf("31");
	else if(b==4||b==6||b==9||b==11)
		printf("30");
	else if(a%4==0&&a/4%100!=0&&b==2)
		printf("29");
	else if(a%4==0&&a/4/100%400==0&&b==2)
		printf("29");
	else if(a%4!=0&&b==2)
		printf("28");
	else if(a%4==0&&a/4%100==0&&a/4/100%400!=0&&b==2)
		printf("28");
	return 0;
}
*//*
{
	int a,b,x,y;
	scanf("%d %d %d %d",&a,&b,&x,&y);
	if(y==-b/a*x+b)
		printf("0");
	else if(y>-b/a*x+b&&y>0&&x<0)
		printf("1");
	else if(y>-b/a*x+b&&y>0&&x>0)
		printf("2");
	else if(y>-b/a*x+b&&y<0&&x>0)
		printf("7");
	else if(y<-b/a*x+b&&y>0&&x<0)
		printf("3");
	else if(y<-b/a*x+b&&y>0&&x>0)
		printf("4");
	else if(y<-b/a*x+b&&y<0&&x<0)
		printf("5");
	else if(y<-b/a*x+b&&y<0&&x>0)
		printf("6");
	else if(a<1||a>99||b<1||b>99)
		printf("Incorrect!");
	return 0;}*/

#include <stdio.h>
int main1()
{
	int p,o,l;
	scanf("%d %d %d",&p,&o,&l);
	if(l==1)
		printf("%d + %d = %d",p,o,p+o);
	else if(l==2)
		printf("%d - %d = %d",p,o,p-o);
	else if(l==3)
		printf("%d * %d = %d",p,o,p*o);
	else if(l==4&&o!=0)
		printf("%d / %d = %d",p,o,p/o);
	else if(l==4&&o==0)
		printf("Incorrect!");
	else if(l==5&&o!=0)
		printf("%d %% %d = %d",p,o,p%o);
	else if(l==5&&o==0)
		printf("Incorrect!");
	else if(l!=1||l!=2||l!=3||l!=4||l!=5)
		printf("Incorrect!");
	return 0;
}
	int main2()
{
   int nMonth, nYear;
   scanf("%d %d", &nYear, &nMonth);

   switch (nMonth)
   {
   case 1:
   case 3:
   case 5:
   case 7:
   case 8:
   case 10:
   case 12:
      printf("31");
      break;
   case 4:
   case 6:
   case 9:
   case 11:
      printf("30");
      break;
   case 2:
      if ((nYear % 4 == 0 && nYear % 100 != 0) || (nYear % 400 == 0))
         printf("29");
      else
         printf("28");
      break;
   default:
      break;
   }
   return 0;
}
int
main3()
{

}
int
main4()
{

}
int
main5()
{
}
int
main()
{
   int
      pro_num= 0;
   scanf
      ("%d\n",&pro_num);
   switch (
      pro_num
      ) {
   case 1: main1(); break;
   case 2: main2(); break;
      case 3: main3();break;
   }
   return 0;
}


int main()
{
   int nMonth, nYear;
   scanf("%d %d", &nYear, &nMonth);
   
   switch (nMonth)
   {
   case 1 : 
   case 3 : 
   case 5:
   case 7 :
   case 8:
   case 10 :
   case 12:
      printf("31");
      break;
   case 4:
   case 6:
   case 9:
   case 11:
      printf("30");
      break;
   case 2:
      if ((nYear % 4 == 0 && nYear % 100 != 0) || (nYear % 400 == 0))
         printf("29");
      else
         printf("28");
      break;
   default :
      break;
   }
	}

	/*if(u==1||u==3||u==5||u==7||u==8||u==10||u==12)
	{
		printf("31");
	}
	else if(u==4||u==6||u==9||u==11)
	{
		printf("30");
	}
	else if(t%4==0)
	{
		if(t%100==0)
		{
			if(t%400==0)
			{
				printf("29\n");
			}
			else
			{
				printf("28\n");
			}
		}
		else
		{	
			printf("29\n");
		}
	}

	//else if(t%4==0&&t/4%100!=0&&u==2)
	//	printf("29");
	//else if(t%4==0&&t%400==0&&u==2)
	//	printf("29");
	//else if(t%4!=0&&u==2)
	//	printf("28");
	//else if(t%4==0&&t/4%100==0&&t%400!=0&&u==2)
	//	printf("28");
	*/
}
int main3()
{
  	int a,b,x,y;
	scanf("%d %d %d %d",&a,&b,&x,&y);
	if(y==(double)(-b/a)*(x-a)+b)
		printf("0");
	else if(y>(double)(-b/a)*(x-a)+b&&y>0&&x<0)
		printf("1");
	else if(y>(double)(-b/a)*(x-a)+b&&y>0&&x>0)
		printf("2");
	else if(y>(double)(-b/a)*(x-a)+b&&y<0&&x>0)
		printf("7");
	else if(y<(double)(-b/a)*(x-a)+b&&y>0&&x<0)
		printf("3");
	else if(y<(double)(-b/a)*(x-a)+b&&y>0&&x>0)
		printf("4");
	else if(y<(double)(-b/a)*(x-a)+b&&y<0&&x<0)
		printf("5");
	else if(y<(double)(-b/a)*(x-a)+b&&y<0&&x>0)
		printf("6");
	else if(a<1||a>99||b<1||b>99)
		printf("Incorrect!");
}
int main4()
{
	int c;
	int r1,r2,r3,r4,r5;
	scanf("%d",&c);
	r1=c/10000;
	r2=c%10000/1000;
	r3=c%1000/100;
	r4=c%100/10;
	r5=c%10;

	if(r1==1)
		printf("ÀÏ¸¸");
	else if(r1==2)
		printf("ÀÌ¸¸");
	else if(r1==3)
		printf("»ï¸¸");
	else if(r1==4)
		printf("»ç¸¸");
	else if(r1==5)
		printf("¿À¸¸");
	else if(r1==6)
		printf("À°¸¸");
	else if(r1==7)
		printf("Ä¥¸¸");
	else if(r1==8)
		printf("ÆÈ¸¸");
	else if(r1==9)
		printf("±¸¸¸");
	if(r2==1)
		printf("ÀÏÃµ");
	else if(r2==2)
		printf("ÀÌÃµ");
	else if(r2==3)
		printf("»ïÃµ");
	else if(r2==4)
		printf("»çÃµ");
	else if(r2==5)
		printf("¿ÀÃµ");
	else if(r2==6)
		printf("À°Ãµ");
	else if(r2==7)
		printf("Ä¥Ãµ");
	else if(r2==8)
		printf("ÆÈÃµ");
	else if(r2==9)
		printf("±¸Ãµ");
	if(r3==1)
		printf("ÀÏ¹é");
	else if(r3==2)
		printf("ÀÌ¹é");
	else if(r3==3)
		printf("»ï¹é");
	else if(r3==4)
		printf("»ç¹é");
	else if(r3==5)
		printf("¿À¹é");
	else if(r3==6)
		printf("À°¹é");
	else if(r3==7)
		printf("Ä¥¹é");
	else if(r3==8)
		printf("ÆÈ¹é");
	else if(r3==9)
		printf("±¸¹é");
	if(r4==1)
		printf("ÀÏ½Ê");
	else if(r4==2)
		printf("ÀÌ½Ê");
	else if(r4==3)
		printf("»ï½Ê");
	else if(r4==4)
		printf("»ç½Ê");
	else if(r4==5)
		printf("¿À½Ê");
	else if(r4==6)
		printf("À°½Ê");
	else if(r4==7)
		printf("Ä¥½Ê");
	else if(r4==8)
		printf("ÆÈ½Ê");
	else if(r4==9)
		printf("±¸½Ê");
	if(r5==1)
		printf("ÀÏ");
	else if(r5==2)
		printf("ÀÌ");
	else if(r5==3)
		printf("»ï");
	else if(r5==4)
		printf("»ç");
	else if(r5==5)
		printf("¿À");
	else if(r5==6)
		printf("À°");
	else if(r5==7)
		printf("Ä¥");
	else if(r5==8)
		printf("ÆÈ");
	else if(r5==9)
		printf("±¸");
}
int main5()
{
	int q,w,e,r,i,f;
	int sum1,sum2,sum3,sum4,sum5,total;
	scanf("%d %d %d %d %d %d",&q,&w,&e,&r,&i,&f);
	if(q>f)
		sum1=3;
	else if(q<f)
		sum1=-2;
	else if(q==f)
		sum1=-1;
	if(w>f)
		sum2=3;
	else if(w<f)
		sum2=-2;
	else if(w==f)
		sum2=-1;
	if(e>f)
		sum3=3;
	else if(e<f)
		sum3=-2;
	else if(e==f)
		sum3=-1;
	if(r>f)
		sum4=3;
	else if(r<f)
		sum4=-2;
	else if(r==f)
		sum4=-1;
	if(i>f)
		sum5=3;
	else if(i<f)
		sum5=-2;
	else if(i==f)
		sum5=-1;
	total=sum1+sum2+sum3+sum4+sum5;
	if(total<0)
		printf("0");
	else if(total>=0)
		printf("%d",total);
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