#include <stdio.h>
struct number{
	int num,sav;
};
int main(){
	struct number st[10]={0};
	int i,j,a,b;

	for(i=0;i<10;i++){
		scanf("%d",&st[i].num);
	}

	for(i=0;i<10;i++){
		st[i].sav=1;
		for(j=0;j<10;j++){
			if(st[i].num<st[j].num){
				st[i].sav++;
			}
		}
		if(st[i].sav==3){
		a=st[i].num;
		}
		else if(st[i].sav==7){
			b=st[i].num;
		}
		

	}
	printf("%d %d",a,b);
	

	return 0;
}







