#include <stdio.h>
int sum(int n){
	int z;
	z=n*(n+1)/2;
	return z;
}
/*int main(){
int a,b;
int suum;
scanf("%d %d",&a,&b);

suum=sum(b)-sum(a)+a;
printf("%d",suum);
}*///실습문제2
/*int main(){
int x,i,suum=0;
scanf("%d",&x);
for(i=1;i<=x;i++){
suum+=sum(i);
}
printf("%d",suum);
}*///실습문제3
void print_row1(int x){
	int i;
	for(i=1;i<=x;i++){
		printf("%d",x);
	}
}
void print_row2(int x1){
	int i;
	printf("%d",x1);
	for(i=1;i<=x1-2;i++){
		printf(" ");
	}
	printf("%d",x1);
}
/*int main(){
int n,i;
scanf("%d",&n);
print_row1(n);
printf("\n");
for(i=1;i<=n-2;i++){
print_row2(n);
printf("\n");
}

print_row1(n);
return 0;
}*///실습문제4
void print_triangle(int x){
	int i,j;
	for(i=1;i<=x;i++){
		for(j=1;j<=i;j++){
			printf("*");
		}
		printf("\n");
	}
}
/*int main(){
int n,i;
for(i=1;;i++){
scanf("%d",&n);
if(n<=0){
break;
}
print_triangle(n);
}
return 0;
}*///실습문제5
int max1,max2;
void update_max(int x){
	int a;
	if(max1<=max2){
		a=max1;
		max1=max2;
		max2=a;
	}
	if(x>=max1){
		max2=max1;
		max1=x;
	}
	else if(x>=max2){
		max2=x;
	}

}
/*int main(){
int num1,i;
scanf("%d %d",&max1,&max2);
for(i=1;;i++){
scanf("%d",&num1);
if(num1==0){
break;
}
update_max(num1);
}
printf("%d %d",max1,max2);

return 0;
}*///실습문제 9
int an1,an2,an3;
int count_strike(int x,int y,int z){
	int count=0;
	if(an1==x){
		count++;
	}
	if(an2==y){
		count++;
	}
	if(an3==z){
		count++;
	}
	return count;

}
int count_ball(int x,int y,int z){
	int count=0;
	if(an1==y||an1==z){
		count++;
	}
	if(an2==x||an2==z){
		count++;
	}
	if(an3==x||an3==y){
		count++;
	}
	return count;	
}
/*int main(){
int i,a,b,c;
scanf("%d %d %d",&an1,&an2,&an3);

for(i=1;;i++){
scanf("%d %d %d",&a,&b,&c);
printf("%dS%dB",count_strike(a,b,c),count_ball(a,b,c));
if(an1==a&&an2==b&&an3==c){
break;
}
}
return 0;
}*///실습문제 11
void print_line(int x, int y, int z){
	int i,j,k;
	for(i=1;i<=x;i++){
		printf(" ");
	}
	for(j=1;j<=y;j++){
		printf("*");
	}
	for(k=1;k<=z;k++){
		printf(" ");
	}
}
/*int main(){
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		print_line(n-i,i*2-1,n-i);
		printf("\n");

	}
	return 0;
}*///실습문제 12
/*int is_prime(int x){
	int count=0,i;
	for(i=1;i<=x;i++)
	if(x%2==0){
		count++;
	}
	if(

}*/
/*int main(){
	int x[5],i,a;
	for(i=0;i<5;i++){
		scanf("%d",&x[i]);
	}
	a=x[0];
	for(i=0;i<4;i++){
		if(x[i]>=x[i+1]){
			a=x[i];
			x[i]=x[i+1];
			x[i+1]=a;
		}
	}
	for(i=0;i<5;i++)
		printf("%d",x[i]);


	return 0;
}*///배열 실습문제2
/*int main(){
	int x[10],i,count1=0,count2=0,count3=0;
	for(i=0;i<10;i++){
	scanf("%d",&x[i]);
	}
	for(i=0;i<10;i++){
		if(x[i]==1){
			count1++;
		}
		else if(x[i]==2){
			count2++;
		}
		else if(x[i]==3){
			count3++;
		}

	}
	printf("1:");
	for(i=1;i<=count1;i++)
		printf("*");
	printf("\n2:");
	for(i=1;i<=count2;i++)
		printf("*");
	printf("\n3:");
	for(i=1;i<=count3;i++)
		printf("*");

	return 0;
}*///실습문제4
/*int main(){
	int x[5],i,max1,max2;
	for(i=0;i<5;i++){
	scanf("%d",&x[i]);
	}
	max1=x[0];
	max2=x[1];
	for(i=2;i<5;i++){
		if(max1<=x[i]){
			max2=max1;
			max1=x[i];}
		else if(max2<=x[i]){
			max2=x[i];
		}
	}
	printf("%d\n%d",max1,max2);
	return 0;

}*///실습문제 4
/*int main(){
	char x[7];
	int i,count=0;
	for(i=0;i<7;i++){
		scanf("%c",&x[i]);
	}
	for(i=0;i<5;i++){
		if(x[i]=='c'&&x[i+1]=='a'&&x[i+2]=='t')
			count++;
		}
	printf("%d",count);


	return 0;
}*///실습문제 5
int main(){
	char x[5];
	int i,j,k,count=0,z;
	for(i=0;i<5;i++){
		scanf("%c",&x[i]);
	}
	for(i=0;i<5;i++){
		for(k=0;k<i;k++){
			printf("%d",x[5-k]);
		}
		for(j=1;j<=i;j++){
			count++;
			if(count==i){
				printf("*");
			}
		}
		for(z=0;z<4-i;z++){
			printf("%d",x[z]);
		}
		printf("\n");
	}

	return 0;
}






