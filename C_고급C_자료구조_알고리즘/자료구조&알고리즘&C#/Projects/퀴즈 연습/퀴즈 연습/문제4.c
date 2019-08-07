#include <stdio.h>

int max(int p[],int n,int i) {
	int a;

	if (n == 1) return a;
	else {
		if (p[i] < p[i+1]) {
			i++;
			return max(p[i], n - 1,i);
		}
		else {
			i++;
			return max(p[i-1], n - 1,i);
		}
	}
	return a;

}

void main() {
	int n, p[20] = { 0 },i;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", p + i);
	}
	i = 0;

	printf("%d", max(p, n,i));
	


}