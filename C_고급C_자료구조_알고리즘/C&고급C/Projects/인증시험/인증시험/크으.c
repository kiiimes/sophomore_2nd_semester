#include <stdio.h>
int main1() {
	int x[5],i,ave=0;
	for(i=0;i<5;i++){
	scanf("%d",&x[i]);
	}
	for(i=0;i<5;i++){
	ave+=x[i];
	}
	ave=ave/5;
	for(i=0;i<5;i++){
	if(ave<x[i]){
	printf("%d\n",x[i]);
	}
	}
}
int main2() {
	int x[5],i,n;
	for(i=0;i<5;i++){
		scanf("%d",&x[i]);
	}
	for(i=0;i<4;i++){
		if(x[i]>x[i+1]){
			n=x[i+1];
			x[i+1]=x[i];
			x[i]=n;
		}
	}
	for(i=0;i<5;i++){
		printf("%d\n",x[i]);
	}

	return 0;
}
int main3() { 
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
	for(i=1;i<=count1;i++){
		printf("*");
	}
	printf("\n2:");
	for(i=1;i<=count2;i++){
		printf("*");
	}
	printf("\n3:");
	for(i=1;i<=count3;i++){
		printf("*");
	}
	return 0;
}
int main4(){
	int x[5]={0},i,max1,max2;
	for(i=0;i<5;i++){
		scanf("%d",&x[i]);
	}

	if(x[0] > x[1]){
		max1=x[0];
		max2=x[1];
	}
	else{
		max1=x[1];
		max2=x[0];
	}
	for(i=2;i<5;i++){
		if(max1<=x[i]){
			max2=max1;
			max1=x[i];
		}
		else if(max2<=x[i]){
			max2=x[i];
		}

	}
	printf("%d\n%d",max1,max2);
	return 0;
}

int main5()
{
	char x[7],i,count=0;
	for(i=0;i<7;i++){
		scanf("%c",&x[i]);
	}
	for(i=0;i<6;i++){
		if(x[i]=='c'){
			if(x[i+1]=='a'){
				if(x[i+2]=='t'){
					count++;
				}
			}
		}

	}
	printf("%d",count);
	return 0;
}
int main6(){
	char x[5],i,j,k;
	for(i=0;i<5;i++){
		scanf("%c",&x[i]);
	}
	for(i=0;i<5;i++){
		for(k=5-i;k<=4;k++){
			printf("%c",x[k]);
		}
		for(j=0;j<5-i;j++){
			printf("%c",x[j]);
		}
		printf("\n");
	}
	return 0;

}
int main8()
	{
   int i, n, j;
   char a[6][5] = { { 'Z','E','R','O','-' },{ 'O','N','E','-','-' },{ 'T','W','O','-','-' },
   { 'T','H','R','E','E' },{ 'F','O','U','R' },{ 'F','I','V','E','-' } };
   for (i = 0; i<3; i++)
   {
      scanf("%d", &n);
      for (j = 0; j<5; j++)
         printf("%c", a[n][j]);
      printf("\n");
   }
   return 0;
}
int main() { 
	int pro_num=0;
	scanf("%d\n",&pro_num);
	switch(pro_num){ 
	case 1: main1(); break; 
	case 2: main2(); break; 
	case 3: main3(); break; 
	case 4: main4(); break;
	case 5: main5(); break;
	case 6: main6(); break;
	case 8: main8(); break;
	}
	return 0;
}



