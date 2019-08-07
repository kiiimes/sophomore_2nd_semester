#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
	char str[30],a[30]={'NULL'};
	int st,i,j,k=0,cnt=0;

	scanf("%s",str);

	st=strlen(str);
	for(i=st-1;i>=0;i--){
		cnt=0;
		for(j=0;j!=i;j++){
			if(str[i]==str[j]){
				cnt++;
			}
		}
		if(cnt==0){
			a[k]=str[i];
			k++;
		}

	}
	for(i=0;i<=st;i++){
		str[i]='\0';
	}


	st=strlen(a);
	for(i=0;i<st;i++){
		k--;
		str[i]=a[k];
	}

	printf("%s",str);


}