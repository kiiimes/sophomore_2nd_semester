#include <stdio.h>

int cd(int n, int m) {

	if (m <= 0) return n;
	else {
		return cd(m, n%m);
	}

}

void main() {
	int n, m;

	scanf("%d %d", &n, &m);

	printf("%d", cd(n, m));
	
}