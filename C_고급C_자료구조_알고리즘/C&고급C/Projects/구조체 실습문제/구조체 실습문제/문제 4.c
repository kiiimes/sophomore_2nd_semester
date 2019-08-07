#include <stdio.h>
struct fraction{
	int mo,ja;

};
int main(){
	struct fraction s1[2];
	int i;

	for(i=0;i<2;i++){
		scanf("%d %d",&s1[i].ja,&s1[i].mo);

	}

	
	printf("%d/%d",(s1[0].ja)*(s1[1].ja),(s1[0].mo)*(s1[1].mo));

	

	return 0;
}