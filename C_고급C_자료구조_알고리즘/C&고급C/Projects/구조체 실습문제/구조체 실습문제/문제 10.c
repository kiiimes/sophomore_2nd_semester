#include <stdio.h>
struct result{
	int max,min,pon,pons,gab;

};
void passorfail(struct result *p){
	p->gab=p->max-p->min;

	if(p->gab>=p->pons){
		printf("%d F",p->gab);

	}
	else if(p->gab<p->pons){
		printf("%d P",p->gab);

	}

}




int main(){
	struct result a;
	int i;

	scanf("%d %d %d",&a.max,&a.min,&a.pons);

	passorfail(&a);


	return 0;
}