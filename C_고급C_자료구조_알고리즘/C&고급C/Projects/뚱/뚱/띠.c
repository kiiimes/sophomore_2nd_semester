#include <stdio.h>
int main(){
	int x[100],i,y[11]={0};
	for(i=1;i<100;i++){
		scanf("%d",&x[i]);
		if(x[i]==0){
			break;
		}
		if(x[i]>=100) y[10]++;
		else if(x[i]>=90) y[9]++;
		else if(x[i]>=80) y[8]++;
		else if(x[i]>=70) y[7]++;
		else if(x[i]>=60) y[6]++;
		else if(x[i]>=50) y[5]++;
		else if(x[i]>=40) y[4]++;
		else if(x[i]>=30) y[3]++;
		else if(x[i]>=20) y[2]++;
		else if(x[i]>=10) y[1]++;
		else if(x[i]>0) y[0]++;
		

	}

	for(i=10;i>=1;i--){
		if(y[i]!=0){
			printf("%d0점 이상 : %d명\n",i,y[i]);}
	}
	if(y[0]!=0)
	printf("0점 이상 : %d명",y[0]);
	
	return 0;
}