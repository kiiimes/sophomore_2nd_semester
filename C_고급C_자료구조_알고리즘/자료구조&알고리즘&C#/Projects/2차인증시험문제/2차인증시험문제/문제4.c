#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct city {
	char name[21];
	double w, k;//w는 위도 k는 경도
}city;

void main() {
	city *ct;
	int n,i;
	double max,min;
	char maxn[21],minn[21];

	scanf("%d", &n);
	getchar();

	ct = (city*)malloc(n * sizeof(city));

	for (i = 0; i < n; i++) {
		scanf("%s %lf %lf", (ct + i)->name, &((ct + i)->w), &((ct + i)->k));
	}
	
	max = ct[0].w;
	strcpy(maxn, ct[0].name);
	for (i = 0; i < n; i++) {
		if (max < ct[i].w) {
			max = ct[i].w;
			strcpy(maxn, ct[i].name);

		}
	}
	
	min = ct[0].k;
	strcpy(minn, ct[0].name);
	for (i = 0; i < n; i++) {
		if (min > ct[i].k) {
			min = ct[i].k;
			strcpy(minn, ct[i].name);
		}
	}

	printf("%s %s", maxn, minn);





}