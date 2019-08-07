#include <stdio.h>
#include <stdlib.h>

void main() {
	int n,p[100],i,reverse,*rinfo,j,cnt=0,sav[100];
	int k;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", p + i);
	}

	scanf("%d", &reverse);

	rinfo = (int*)malloc(reverse * sizeof(int));

	for (i = 0; i < reverse; i++) {
		scanf("%d", rinfo + i);
	}

	for (i = 0; i < 2*reverse; i++) {
		cnt = 0;

		for (j = rinfo[i]; j <= rinfo[i+1]; j++) {
			sav[cnt] = p[j];
			cnt++;
		}
		cnt = 0;
		for (k = rinfo[i+1]; k >= rinfo[i]; k--) {
			p[k] = sav[cnt];
			cnt++;
		}
		
		i++;
	}

	for (i = 0; i < n; i++) {
		printf(" %d", p[i]);
	}





}