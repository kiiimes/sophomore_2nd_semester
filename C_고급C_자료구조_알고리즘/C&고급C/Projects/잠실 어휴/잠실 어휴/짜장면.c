#include <stdio.h>
int main()

	/*{
	int i,j,sum=0;
	for (i=0;i<10;i++)
	{
	sum=i+1;
	for(j=1;j<=10;j++){
	printf(" %d",sum%10);
	sum+=1;
	}
	printf("\n");
	sum=0;
	}
	return 0;
	}*///중첩 반복문 1~~0 나머지
/*{
	int n,a,b,c,i,k=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		a=i%10;
		b=i/10;
		c=0;
		while(a==3){
			k++;
			break;
		}
		while(b>10){
			b=b/10;
			c=b%10;
			if(b==3){
				k++;
			}
			if(c==3){
				k++;
			}
		}
	}
	printf("%d",k);
	return 0;
}*///아직 못함
/*{
	int i,j,n,sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=i;j++){
			sum++;
			printf("%d",sum%10);
			
		}
		printf("\n");		
	}
	return 0;
}*///숫자로 된 삼각형 완성!!!!
/*{
	int num1,a,sum=11,b,c;
	scanf("%d",&num1);
	while(sum/10!=0){
		sum=0;
		while(num1/10!=0){
			
			a=num1%10;
			num1=num1/10;
			sum=sum+a;
		}
		sum+=num1;
		b=sum/10;
		c=sum%10;
		sum=b+c;
		printf("%d",sum);
	}
}*///디지털근
/*{
	int n,i,j,k,sum=0;
	scanf("%d",&n);
	for(i=1;i<=6;i++){
		for(j=1;j<=6;j++){
			for(k=1;k<=6;k++){
				sum=i+j+k;
				if(sum==n){
					printf("%d %d %d\n",i,j,k);
				}
			}
		}
	}
	return 0;
}*///주사위 문제
/*{
	int n,i,sum=0;
	scanf("%d",&n);
	
	for(i=1;;i++){
		sum+=i;
		if(i==n){
			break;
		}
	}
	printf("%d",sum);

	return 0;
}*///합구하는 문제
/*{
	int i,sum=0;
	for(i=1;i<=10;i++){
		if(i%2==0){
			continue;
		}
		sum+=i;
	}
	printf("%d",sum);

	return 0;
}*///홀수의 합구하는 문제
/*{
	int i;
	for(i=1;i<=20;i++){
		if(i%2==0&&i%3==0){
			continue;
		}
		printf("%d ",i);
	}
	return 0;
}*///2의 배수 앤드 3의 배수
{
	int a,i;
	scanf("%d",&a);
	if(a==7){
		printf("%21d\n",1);
		for(i=2;i<=31;i++){
			printf("%3d",i);
			if(i%7==1){
				printf("\n");
			}
		}
	}
		if(a==6){
		printf("%18d%3d\n",1,2);
		for(i=3;i<=31;i++){
			printf("%3d",i);
			if(i%7==2){
				printf("\n");
			}
		}
	}
					if(a==5){
		printf("%15d%3d%3d\n",1,2,3);
		for(i=4;i<=31;i++){
			printf("%3d",i);
			if(i%7==3){
				printf("\n");
			}
		}
	}
				if(a==4){
		printf("%12d%3d%3d%3d\n",1,2,3,4);
		for(i=5;i<=31;i++){
			printf("%3d",i);
			if(i%7==4){
				printf("\n");
			}
		}
	}
					if(a==3){
		printf("%9d%3d%3d%3d%3d\n",1,2,3,4,5);
		for(i=6;i<=31;i++){
			printf("%3d",i);
			if(i%7==5){
				printf("\n");
			}
		}
	}
						if(a==2){
		printf("%6d%3d%3d%3d%3d%3d\n",1,2,3,4,5,6);
		for(i=7;i<=31;i++){
			printf("%3d",i);
			if(i%7==6){
				printf("\n");
			}
		}
	}
							if(a==1){
		printf("%3d%3d%3d%3d%3d%3d%3d\n",1,2,3,4,5,6,7);
		for(i=8;i<=31;i++){
			printf("%3d",i);
			if(i%7==0){
				printf("\n");
			}
		}
	}

	return 0;
}


