#include <stdio.h>

int max(int *p, int n,int sav) {
	
	
	if (n == 1) {
		if (sav < p[n - 1]) {
			sav = p[n - 1];
		}
		return sav;
	}
	else {
		if (sav < p[n - 1]) {
			sav = p[n - 1];
		}
		
		return max(p, n-1, sav);
	}


}

void main() {
	int n, p[20] = { 0 },i,sav=0;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", p + i);
	}
	sav = p[n - 1];

	printf("%d", max(p, n, sav));
}