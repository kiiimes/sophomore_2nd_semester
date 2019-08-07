#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
	int n,i,sa=0,sb=0;
	char *p,a,b;
	scanf("%d",&n);
	getchar();

	p=(char*)malloc((n+1)*sizeof(char));

	scanf("%s",p);

	getchar();

	scanf("%c %c",&a,&b);

	for(i=0;i<n;i++){
		if(p[i]==a){
			sa++;
		}
		if(p[i]==b){
			sb++;
		}
	}

	printf("%d %d",sa,sb);

	free(p);

}