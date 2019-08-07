#include <stdio.h>

int main() {
	int i = 0, j = 0, n, p[100][100], cnt = 0;

	scanf_s("%d", &n);
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf_s("%d", &(p[i][j]));
		}
	}

	i = 0;
	j = 0;

	while (p[i][j] == 1) {

		cnt++;
		j++;
	}//1인동안만 cnt++
	j = j - 1;
	while (1) {
		i++;
		while (p[i][j] == 0) {
			j--;
		}
		if (p[i][j] == 1) {
			j++;
			cnt = cnt + j;
		}
		
		if (n == i) {
			break;
		}
	}
	printf("%d", cnt);

}