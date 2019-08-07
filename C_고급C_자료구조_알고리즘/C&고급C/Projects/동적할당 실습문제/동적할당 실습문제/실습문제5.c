#include <stdio.h>
#include <stdlib.h>
int main(){
	int n,i,count1=0,count2=0;
	char *p,a,b;
	p=(char*)malloc((n+1)*sizeof(char));
	scanf("%d",&n);
	getchar();
	scanf("%s",p);
	getchar();
	scanf("%c %c",&a,&b);

	for(i=0;i<n;i++){
		if(p[i]==a){
			count1++;
		}
		if(p[i]==b){
			count2++;
		}
	}
	printf("%d %d",count1,count2);


	free(p);

	return 0;
}