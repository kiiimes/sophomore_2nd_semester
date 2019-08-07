#include <stdio.h>
void main(){
	FILE *fp,*fq;
	int i;
	char str[10]={NULL};
	fp=fopen("test1.txt","r");
	fq=fopen("test2.txt","w");
	
	fscanf(fp,"%s",str);

	for(i=0;str[i]!='\0';i++){
		if(str[i]>='a'&&str[i]<='z'){
			str[i]='A'+str[i]-'a';
		}
		else if(str[i]>='A'&&str[i]<='Z'){
			str[i]='a'+str[i]-'A';
		}
	}
	
	fprintf(fq,"%s",str);

	fclose(fq);
	fclose(fp);

}