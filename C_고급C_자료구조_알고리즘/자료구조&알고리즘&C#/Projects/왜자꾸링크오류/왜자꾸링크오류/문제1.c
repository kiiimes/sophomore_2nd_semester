#include <stdio.h>
#include <stdlib.h>

void main() {
	int n,p[100],renum,*rearr,i,j,*sav,cnt=0;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d",p + i);
	}

	scanf("%d", &renum);

	rearr = (int*)malloc(renum *2* sizeof(int));
	sav = (int*)malloc(renum * 2 * sizeof(int));

	for (i = 0; i < renum * 2; i++) {
		scanf("%d", rearr + i);
	}
	
	for (i = 0; i < renum * 2; i++) {
		cnt = 0;
		for (j = rearr[i]; j <= rearr[i + 1]; j++) {
			sav[cnt] = p[j];
			cnt++;
		}
		cnt = 0;
		for (j = rearr[i + 1]; j >= rearr[i]; j--) {
			p[j] = sav[cnt];
			cnt++;
		}

	}

	for (i = 0; i < n; i++) {
		printf(" %d", p[i]);
	}
	
	free(rearr);
	free(sav);




}