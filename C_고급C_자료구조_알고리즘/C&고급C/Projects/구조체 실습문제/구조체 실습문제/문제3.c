#include <stdio.h>
struct now{
	int t1,t2,t3;


};
int main(){
	struct now time[2];
	int i,a,b;

	for(i=0;i<2;i++){
	scanf("%d %d %d",&time[i].t1,&time[i].t2,&time[i].t3);
	}
	a=(time[0].t1)*3600+(time[0].t2)*60+time[0].t3;
	b=(time[1].t1)*3600+(time[1].t2)*60+time[1].t3;

	a=b-a;

	time[0].t1=a/3600;
	time[0].t2=(a%3600)/60;
	time[0].t3=a%60;

	printf("%d %d %d",time[0].t1,time[0].t2,time[0].t3);

	

	return 0;
}