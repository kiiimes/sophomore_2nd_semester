#include <stdio.h>
struct student{
	char name[10];
	int sc1,sc2,sc3;


};
void read_data(struct student ar[10]){
	int i;
	for(i=0;i<10;i++){
		scanf("%s %d %d,",ar[i].name,&ar[i].sc1,&ar[i].sc2,&ar[i].sc3);

	}
}
void cal_avg(struct student ave[10]){
	
	int i,sum[10];

	for(i=0;i<10;i++){
		sum[i]=(ave[i].sc1+ave[i].sc2+ave[i].sc3)/3.00;

	}

}
void sort(struct student jung){
	


}




int main(){
	struct student info[10];
	int i;

	read_data(info);





	return 0;
}