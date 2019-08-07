#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct city {
	char name[22];//이름
	double max;//최고온도
	double min;//최저온도
	double gap;//차이

}city;//시티 정보 구조체

int input_city (city *city){
	int n,i;
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++) {
		scanf("%s %lf %lf", city[i].name, &(city[i].max), &(city[i].min));
		city[i].gap = city[i].max - city[i].min;
	
	}
	return n;
}
city find_largest(city *ccity,int size){
	int i;
	double max;
	city sav;
	
	//size는 도시 개수
	max = ccity[0].gap;
	sav = ccity[0];
	for (i = 0; i < size; i++) {
		if (max < ccity[i].gap) {
			max = ccity[i].gap;
			sav = ccity[i];
		}
	}
	return sav;
}

void main() {
	city ccity[10],sav;
	int num;//도시 개수

	num=input_city(ccity);

	sav=find_largest(ccity, num);

	printf("%s %.1f", sav.name, sav.gap);
	


}