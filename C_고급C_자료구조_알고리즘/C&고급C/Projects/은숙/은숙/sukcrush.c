#include <stdio.h>

int main()

{
	int num1, num2, num3, num4, num5;
	int nAns1, nAns2; 
	int place_Maxnum;
	int nNo;
	int a,b,c,d,e,f;

	scanf("%d %d %d %d %d",&num1,&num2,&num3,&num4,&num5);
	scanf("%d",&nNo);
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	nAns1 = num1;
	(nAns1>num2) ? place_Maxnum = 1 : num2, place_Maxnum = 2;
	(nAns1<num3)?nAns1=num3,place_Maxnum = 3 : nAns1;
	(nAns1<num4)?nAns1=num4,place_Maxnum = 4 : nAns1;
	(nAns1<num5)?nAns1=num5,place_Maxnum = 5 : nAns1;
	printf("%d",nAns1);
	nAns2=0;
	nAns2=(nAns1==num1) ? num2 : num1;
	nAns2=(nAns2<num1 && place_Maxnum!=1) ? num1 : nAns1;
	nAns2=(nAns2<num2 && place_Maxnum!=2) ? num2 : nAns2;
	nAns2=(nAns2<num3 && place_Maxnum!=3) ? num3 : nAns2;
	nAns2=(nAns2<num4 && place_Maxnum!=4) ? num4 : nAns2;
	nAns2=(nAns2<num5 && place_Maxnum!=5) ? num5 : nAns2;

	printf("%d\n",nAns2);
	printf("%c %c\n", 'a'+nNo-1,'A'+nNo-1);
	
	((double)f>=(double)((d-b)/(c-a))*(e-a)+b) ? (printf("1")):(printf("0"));
	 return 0;
}