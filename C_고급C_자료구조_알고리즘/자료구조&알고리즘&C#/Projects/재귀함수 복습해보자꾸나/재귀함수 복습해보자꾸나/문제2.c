#include <stdio.h>
 
double fac(int n) {
	

	if (n <= 1)return 1;
	else return n*fac(n - 1);

}

void main() {
	int i,n,cnt=1;
	double sum = 0;

	scanf("%d", &n);
	
	for (i = 0; i < n; i++) {
		sum += 1/fac(cnt);
		cnt++;
	}

	printf("%lf", sum+1);

}