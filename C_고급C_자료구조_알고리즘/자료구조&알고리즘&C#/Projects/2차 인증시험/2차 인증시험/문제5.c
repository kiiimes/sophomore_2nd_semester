#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct resaurant {
	int mon, aft, din;
}restau;


void main() {
	restau *p;
	int n, i,j, *sav,max,sum=0,cnt=0;

	scanf("%d", &n);//식당 개수

	p = (restau*)malloc(n * sizeof(restau));
	sav = (int*)malloc(n * sizeof(int));

	for (i = 0; i < n; i++) {
		scanf("%d %d %d", &(p->mon), &(p->aft), &(p->din));
	}
	

	for (i = 0; i < n; i++) {
		sav[i] = p[i].mon;
		if (sav[i] < p[i].aft) {
			sav[i] = p[i].aft;
		}
		if (sav[i] < p[i].din) {
			sav[i] = p[i].din;
		}//각 행에서 큰거 고름 
	}
	max = sav[0];
	for (i = 0; i < n; i++) {
		if (max < sav[i]) {
			max = sav[i];
			cnt = i;
			
		}
	}

	sum += max;

	for (i = 0; i < n; i++) {
		if (i == cnt) {

		}
	}








}