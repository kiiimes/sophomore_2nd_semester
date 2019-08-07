#include <stdio.h>
struct jungchae{
	char name[10];
	int sc;
};
struct jungchae *select_min(struct jungchae *naa){
	int i,j,a;


	for(i=0;i<5;i++){
		a=1;
		for(j=0;j<5;j++){
			if(naa[i].sc>naa[j].sc){
				a++;

			}

		}
		if(a==1){
			return naa+i;

		}


	}




}
int main(){
	struct jungchae na[5],*st;
	int i;
	
	for(i=0;i<5;i++){
		scanf("%s %d",na[i].name,&na[i].sc);
	}

	st=select_min(na);

	printf("%s %d",st->name,st->sc);





	return 0;
}