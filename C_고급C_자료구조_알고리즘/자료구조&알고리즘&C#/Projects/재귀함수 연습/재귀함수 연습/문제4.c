#include <stdio.h>

int max(int n, int p[20], int mmax) {
	if (n == 0) {
		if (mmax < p[n]) {
			return p[n];
		}
		return mmax;
	}
	else if (mmax < p[n - 1]) {
		mmax = p[n - 1];
	}
	return max(n - 1, p, mmax);
	
}

void main() {
	int n,p[20],i,mmax;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", p + i);
	}
	mmax = p[n - 1];

	printf("%d",max(n-1, p,mmax));


}