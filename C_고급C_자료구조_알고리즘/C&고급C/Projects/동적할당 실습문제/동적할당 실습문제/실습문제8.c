#include <stdio.h>
#include <stdlib.h>

int main(){
	int n,i,count=0;
	char *p;
	scanf("%d",&n);
	p=(char*)malloc((n+1)*sizeof(char));

	scanf("%s",p);

	for(i=0;i<n-2;i++){
		if(*(p+i)=='c'&&*(p+i+1)=='a'&&*(p+i+2)=='t'){
			count++;
		}
	}
	printf("%d",count);


	return 0;
}