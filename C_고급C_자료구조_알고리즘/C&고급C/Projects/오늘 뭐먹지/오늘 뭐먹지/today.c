#include <stdio.h>
int main()
	/*{
	float garo,sero;
	scanf("%f %f",&garo,&sero);
	printf("%.2f",garo*sero);
	return 0;
	}*///3�� �ǽ����� �簢�� ����
	/*{
	float n;
	scanf("%f",&n);
	printf("%.0f",n);
	return 0;
	}*///3�� �ݿø�
	/*{
	char a,b,c;
	scanf("%c",&a);
	b=a-'a';
	c='A'+b;
	printf("%c",c);
	return 0;
	}*///3�� �ƽ�Ű�ڵ�1
	/*{
	char a;
	int b;
	scanf("%c",&a);
	printf("%c\n",a);
	b=a-'0';
	printf("%d",b);
	return 0;
	}*///3�� ���� 4, ����4
	/*{
	int a;
	scanf("%x",&a);
	printf("%d\n",a);
	printf("%o",a);
	return 0;}*///3��16����, 8����
	/*{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	printf("%5d\n%5d\n%5d",a,b,c);
	return 0;
	}*///3�� �� 
	/*{
	int i;
	int a,b,c,d,e;

	scanf("%d",&i);

	a=i/10000;
	b=i/1000%10;
	c=i/100%10;
	d=i/10%10;
	e=i%10;

	printf("%d�� %dõ %d�� %d�� %d",a,b,c,d,e);

	return 0;
	}*///4�� ��õ���
	/*{
	int n;
	int hour,min,sec;

	scanf("%d",&n);

	hour=n/3600;
	min=(n-hour*3600)/60;
	sec=n-hour*3600-60*min;
	printf("%d:%02d:%02d",hour,min,sec);
	return 0;
	}*///�ð� ����
	/*{
	int a,b;
	scanf("%d",&a);
	b=a/100%10;
	printf("%d",b);
	return 0;
	}*///100�� �ڸ� ���
	/*{
	int n,b;
	scanf ("%d",&n);
	b=n/100%10;
	b>5 ? (printf("%d",((n/1000)+1)*1000)):(printf("%d",(n/1000)*1000));
	return 0;
	}*///�ݿø�
	/*{
	int n;
	scanf("%d",&n);
	n>=20&&n<=30 ? (printf("%d",n>=20&&n<=30)):(printf("%d",n>=20&&n<=30));
	return 0;
	}*///������� ���迬���� ����� 1�Ǵ� 0
	/*{
	char a;
	scanf("%c",&a);
	(a>='A'&&a<='Z')||(a>='a'&&a<='z') ? (printf("1")):(printf("0"));
	return 0;
	}*///���ĺ��̸� 1 �ƴϸ� 0
	/*{
	int n;
	scanf("%d",&n);
	n%2==0 ? (printf("¦��")):(printf("Ȧ��"));
	return 0;
	}*///¦�� Ȧ�� ���
	/*{
	int n,m;
	scanf("%d %d",&n,&m);
	n>m ? (printf("%d",n)):(printf("%d",m));
	return 0;
	}*///�� �� ū �� ���
	/*{
	int n,m;
	scanf("%d %d",&n,&m);
	n>m ? (printf("%d\n",n/m)):(printf("%d\n",m/n));
	n>m ? (printf("%d",n%m)):(printf("%d",m%n));
	return 0;
	}*///����, ������ ��
	/*{
	int n,m;
	scanf("%d %d",&n,&m);
	if(n*n==m)
	printf("%d*%d=%d",n,n,m);
	else if(m*m==n)
	printf("%d*%d=%d",m,m,n);
	else if(n*n!=m&&m*m!=n)
	printf("none");
	return 0;
	}*///�������� Ȯ��
	/*{
	int n,m,l;
	int max,min;
	scanf("%d %d %d",&n,&m,&l);
	if(n>m)
	max=n,min=m;
	else if(m>n)
	max=m,min=n;

	if(max>l)
	max=max;
	else if(max<l)
	max=l;

	if(min>l)
	min=l;
	else if(min<l)
	min=min;

	printf("%d %d",max,min);
	return 0;
	}*///�ִ� �ּ� ����
	/*{
	int n;
	scanf("%d",&n);
	if(n%2==0&&n%3==0&&n%5==0)
	printf("A");
	else if(n%2==0&&n%3==0&&n%5!=0)
	printf("B");
	else if(n%2==0&&n%3!=0&&n%5==0)
	printf("C");
	else if(n%2!=0&&n%3==0&&n%5==0)
	printf("D");
	else if(n%2==0||n%3==0||n%5==0)
	printf("E");
	else
	printf("N");
	return 0;
	}*///2,3,5 �� ������ �������°ſ� ���� ���ĺ� ���
	/*{
	int n;
	scanf("%d",&n);
	if(n%4==0&&n%100!=0&&n%400!=0)
	printf("����");
	else if(n%4!=0)
	printf("���");
	else if(n%4==0&&n%100==0&&n%400!=0)
	printf("���");
	else if(n%4==0&&n%100==0&&n%400==0)
	printf("����");
	return 0;
	}*///����,���
	/*{
	int n,m;
	scanf("%d %d",&n,&m);
	if(n>m){
	printf("UP");
	scanf("%d",&m);
	if(n>m)
	printf("UP");
	else if(n<m)
	printf("DOWN");
	else if(n==m)
	printf("����");
	}
	else if(n<m){
	printf("DOWN");
	scanf("%d",&m);

	if(n>m)
	printf("UP");
	else if(n<m)
	printf("DOWN");
	else if(n==m)
	printf("����");
	}
	else if(n==m)
	printf("����");

	return 0;
	}*///���ٿ� ����
	/*{
	char n,m;
	scanf("%c",&n);
	if(n>='A'&&n<='Z'){
	m=n-'A';
	n='a'+m;
	printf("%c",n);
	}
	else if(n>='a'&&n<='z'){
	m=n-'a';
	n='A'+m;
	printf("%c",n);
	}
	else
	printf("none");
	return 0;
	}*///�빮 �ҹ��ص� �ƴѰ��
/*{
	int an1,an2,an3,gu1,gu2,gu3;
	int i=0,j=0;
	scanf("%d %d %d %d %d %d",&an1,&an2,&an3,&gu1,&gu2,&gu3);

	if(an1==gu1)
		i++;
	else if(an1==gu2||an1==gu3)
		j++;
	if(an2==gu2)
		i++;
	else if(an2==gu1||an2==gu3)
		j++;
	if(an3==gu3)
		i++;
	else if(an3==gu1||an3==gu2)
		j++;

	printf("%dS%dB",i,j);

	return 0;
}*/ //�߱�����
/*{
	int n,i=1;
	scanf("%d",&n);

	while(i<n){
		
	if(n%i==0){
		printf("%d ",i);
	}
	i++;
	}
	printf("%d",n);
	return 0;
}*///������
/*{
	int n,i,j=0;
	scanf("%d",&n);
	do{
		scanf("%d",&i);
		if(i>n)
			printf("%d>?",i);
		else if(i<n)
			printf("%d<?",i);
	j++;
	}while(i!=n);

	printf("%d==?\n%d",i,j);
	return 0;
}*///���ڸ��߱� ����
/*{
	int n,sum=0;
	do{
		scanf("%d",&n);
		sum+=n;
	}while(n!=0);
	printf("%d",sum);
	return 0;
}*///0������ ����
/*{
	int i,j;
	int num1,num2,b,c;

	scanf("%d %d",&num1,&num2);
	
	if(num1>num2)
		b=num2;
	else if(num1<num2)
		b=num1;
	for(i=1;i<=b;i++){
		if(num1%i==0&&num2%i==0)
			c=i;
	}
	printf("%d",c);
	return 0;
}*/
{
	int i,j,n,k,z;
	scanf("%d",&n);

	for(i=1;i<=n;i++){
		for(j=1;j<=n-i;j++){
			printf(" ");}
		for(k=1;k<=2*i-1;k++){
			printf("*");
		}
		for(z=1;z<=n-i;z++){
			printf(" ");
		}

	printf("\n");
	}

		return 0;
}


	
















































