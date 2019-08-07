#include <stdlib.h>
#include <stdio.h>
/*typedef struct _ES
{
	int x,y;
}ES;
int main(){
	ES a;
	scanf("%d %d",&(a.x),&(a.y));
	printf("%d %d",a.x,a.y);

	return 0;
}  */
/*int main(){
	char *p;
	p=(char*)malloc(sizeof(char));
	scanf("%c",p);
	printf("%c",*p);
	free(p);  
	return 0;
}*/
typedef struct _NC{
	int a;
}NC;
int main(){
	NC *p;
	p=(NC*)malloc(sizeof(NC));
	scanf("%d",&p->a);
	printf("%d",p->a);
	 free (p);
	return 0;
}










