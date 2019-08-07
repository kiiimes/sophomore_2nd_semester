#include <stdio.h>
void main(){
	FILE *fp;
	int n,a,i;
	fp=fopen("data.txt","w");
	for(i=0;;i++){
	if(scanf("%d",&a) == EOF)
		break;
	fprintf(fp,"%d\n",a);
	}
	fclose(fp);
	fp=fopen("data.txt","w+");
	for(i=0;;i++){


	}
	
	




}