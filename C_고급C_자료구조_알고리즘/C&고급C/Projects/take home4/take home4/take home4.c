#include <stdio.h>
char encrypt(int num,char mun)
{
	char z;
	z='a'+((mun+num-'a')%26);
	return z;
}
int main1() { 
	int k,i;
	char e;
	scanf("%d",&k);
	for(i=1;;i++){
		scanf("%c",&e);
		if(e=='.'){
			break;
		}
		else if(e>='a'&&e<='z'){
			printf("%c",encrypt(k,e));
		}
		else{
			continue;
		}
	}
	return 0;
}
int dab1,dab2;
void complex_add(int x,int y,int k,int s){
	dab1=x+y;
	dab2=k+s;
}
void complex_mul(int a, int b, int c, int d){
	dab1=a*c-b*d;
	dab2=a*d+b*c;
}
int main2() { 
	int snum1,gnum1,snum2,gnum2;
	scanf("%d %d %d %d",&snum1,&gnum1,&snum2,&gnum2);
	complex_add(snum1,snum2,gnum1,gnum2);
	printf("%d %d\n",dab1,dab2);
	complex_mul(snum1,gnum1,snum2,gnum2);
	printf("%d %d",dab1,dab2);
	return 0;
}

int is_prime(int n)
{
	int i, count = 0;
	for(i = 2; i < n; i++)
	{
		if (n % i == 0) count++;
	}
	if(count == 0) return 1;
	else return 0;
}

int next_prime(int n)
{
	n++;
	while(1)
	{
		if(is_prime(n)) break;
		n++;
	}
	return n;
}

int main3() {
	int n;
	int i;
	scanf("%d", &n);

	while(1)
	{
		i = 2;
		if (n % i == 0) printf("%d", i);
		i = next_prime(i);
		if (n < i) break;
	}
}
int is_leapyear(int y)
{
	if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0)) return 1;
	else return 0;
}
int days_in_year (int y)
{
	if(is_leapyear(y)) return 366;
	else return 365;
}
int days_in_month (int y, int m)
{
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) return 31;
	if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
	if (m == 2)
	{
		if (is_leapyear(y)) return 29;
		else return 28;
	}
}

int main4() { 
	int bir_y, bir_m, bir_d;
	int now_y, now_m, now_d;
	int totalday = 0;
	int i;

	scanf("%d %d %d", &bir_y, &bir_m, &bir_d);
	scanf("%d %d %d", &now_y, &now_m, &now_d);

	if (bir_y == now_y)
	{
		if (bir_m == now_m)
		{
			totalday += now_d - bir_d; 
		}
		else
		{
			totalday += days_in_month(bir_y, bir_m);
			totalday += now_d;
			totalday -= bir_d;


			for(i = bir_m+1; i < now_m; i++)
			{
				totalday += days_in_month(now_y, i);
			}
		}
	}
	else
	{
		totalday += days_in_month(bir_y, bir_m);
		totalday -= bir_d;
		totalday += now_d;

		for(i = bir_m+1; i <= 12; i++)
		{
			totalday += days_in_month(bir_y, i);
		}
		for(i = 1; i < now_m; i++)
		{
			totalday += days_in_month(now_y, i);
		}
		for(i = bir_y+1; i < now_y; i++)
		{
			totalday += days_in_year(i);
		}
	}

	printf("%d", totalday);

}
int main() { 
	int pro_num=0;
	scanf("%d\n",&pro_num);
	switch(pro_num){ 
	case 1: main1(); break; 
	case 2: main2(); break; 
	case 3: main3(); break; 
	case 4: main4(); break;
	}
	return 0;
}




