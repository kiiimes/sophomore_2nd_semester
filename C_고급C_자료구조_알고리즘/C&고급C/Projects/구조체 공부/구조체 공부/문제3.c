#include <stdio.h>
#include <string.h>
typedef struct tim{
	int h,m,s;

}tim;

void main(){
	tim a[2];
	int i,sum[2];

	for(i=0;i<2;i++){
		scanf("%d %d %d",&(a[i].h),&(a[i].m),&(a[i].s));
	}

	for(i=0;i<2;i++){
		sum[i]=(a[i].h)*3600+(a[i].m)*60+(a[i].s);
	}
	sum[0]=sum[1]-sum[0];

	printf("%d %d %d",sum[0]/3600,sum[0]%3600/60,sum[0]%3600%60);

}