#include <stdio.h>
struct complex{
	double b1,b2;

};
struct complex add(struct complex ad1,struct complex ad2){
	struct complex na;
	
	na.b1=ad1.b1+ad2.b1;
	na.b2=ad1.b2+ad2.b2;

	return na;
}

int main(){
	struct complex st[2];
	struct complex naa;
	int i;

	for(i=0;i<2;i++){
		scanf("%lf %lf",&st[i].b1,&st[i].b2);
	}
	naa=add(st[0],st[1]);

	printf("%.1lf + %.1lfi",naa.b1,naa.b2);

	
	
	




	return 0;
}