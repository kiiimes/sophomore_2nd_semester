#include <stdio.h>
typedef struct tim {
	int h, m, s;

}tim;


void main() {
	tim t1[2];
	int i,sav[2];

	for (i = 0; i < 2; i++) {
		scanf("%d %d %d",&t1[i].h, &t1[i].m, &t1[i].s);
		sav[i] = t1[i].h * 3600 + t1[i].m * 60 + t1[i].s;
	}

	sav[0]=sav[1] - sav[0];

	printf("%d %d %d", sav[0] / 3600, (sav[0]-(sav[0]/3600 *3600))/ 60, sav[0]-(sav[0]/3600*3600)- (sav[0] - (sav[0] / 3600 * 3600))/60*60);

}