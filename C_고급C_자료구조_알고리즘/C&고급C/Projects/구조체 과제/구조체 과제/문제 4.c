#include <stdio.h>
struct date{
	int year,month,day;

};
struct date *select_min(struct date *a1,struct date *a2){
	int i;

	for(i=0;i<2;i++){
		if(a1->year<a2->year){
			return a1;

		}
		else if(a1->year>a2->year){
			return a2;
		}
		else{
			if(a1->month>a2->month){
				return a2;
			}
			else if(a1->month<a2->month){
				return a1;
			}
			else{
				if(a1->day>a2->day){
					return a2;

				}
				else if(a2->day>a1->day){
					return a1;
				}
				else{
					return a1;
				}
			}


		}

	}

}
int main(){
	struct date st[2],*p;
	int i;
	char n;

	for(i=0;i<2;i++){

		scanf("%d%c%d%c%d",&st[i].year,&n,&st[i].month,&n,&st[i].day);

	}

	p=select_min(st,st+1);

	printf("%d/%d/%d",p->year,p->month,p->day);

	return 0;
}