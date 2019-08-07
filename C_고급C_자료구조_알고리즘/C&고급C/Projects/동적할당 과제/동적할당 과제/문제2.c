#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct len{
	float x,y;
}len;


void main(){
	len *p,st;
	int i,n,j,a;
	float *sav;
	scanf("%d",&n);
	
	p=(len*)calloc(n,sizeof(len));

	for(i=0;i<n;i++){
		scanf("%f %f",&(p[i].x),&(p[i].y));
	}

	scanf("%f %f",&(st.x),&(st.y));

	sav=(float*)calloc(n,sizeof(float));

	for(i=0;i<n;i++){
		sav[i]=((st.x)-(p[i].x))*((st.x)-(p[i].x))+((st.y)-(p[i].y))*((st.y)-(p[i].y));
	}

	for(i=0;i<n;i++){
		a=1;
		for(j=0;j<n;j++){
			if(sav[i]>sav[j])a++;
		}
		if(a==1){
			a=i;
			break;
		}
	}

printf("%.1f %.1f",p[a].x,p[a].y);



	

}