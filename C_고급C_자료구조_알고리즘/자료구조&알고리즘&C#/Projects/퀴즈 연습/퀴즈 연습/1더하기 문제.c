#include <stdio.h>
#include <stdlib.h>
//1의 개수 세기
int add(int **pa, int n) {
	int i=0, j=0,cnt=0;
	if (pa[0][0] == 1) {
		while (pa[i][j] == 1) {//1인동안만
			cnt++;
			j++;
		}//0일때 break
		i++;
		j--;
	}
	else if (pa[0][0] == 0) {
		return cnt;
	}

	while (i < n) {
		if (pa[i][j] == 0) {
			if (j == 0) {
				break;
			}
			j--;
		}
		if (pa[i][j] == 1) {
			if (j == 0) {
				cnt++;
				break;
			}
			cnt =cnt+j+1;
			i++;
		}
	}
	return cnt;
}

void main() {
	int **p, n,i,j;

	scanf("%d", &n);

	p = (int**)malloc(n * sizeof(int*));

	for (i = 0; i < n; i++) {
		p[i] = (int*)malloc(n * sizeof(int));
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &p[i][j]);
		}
	}

	printf("%d", add(p, n));

}