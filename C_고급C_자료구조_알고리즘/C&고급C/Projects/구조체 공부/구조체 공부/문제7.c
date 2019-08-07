#include <stdio.h>
#include <string.h>
typedef struct sav{
	int a,soon;

}sav;

void main(){
	sav s[10];
	int i,j,cnt;

	for(i=0;i<10;i++){
		scanf("%d",&(s[i].a));

	}

	for(i=0;i<10;i++){
		cnt=1;
		for(j=0;j<10;j++){
			if(s[i].a<s[j].a)cnt++;
		}
		s[i].soon=cnt;
		
	}
	for(i=0;i<10;i++){
		if(s[i].soon==3||s[i].soon==7){
			printf("%d ",s[i].a);
		}
	}
	
}