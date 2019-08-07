#include <stdio.h>

void main() {
	int n, x[101], num, info[201],i,tmp,j,k,z;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", x + i);
	}
	scanf("%d", &num);
	for (i = 0; i < num*2; i++) {
		scanf("%d", info + i);
	}// 정보 입력

	for (i = 0; i < num * 2; i++) {



		

			for (j = 0; j < (info[i + 1] - info[i]) / 2 + 1; j++) {
				tmp = x[info[i] + j];//x[0]
				x[info[i] + j] = x[info[i + 1] - j];//x[4]
				x[info[i + 1] - j] = tmp;
			}
			for (k = 0; k < n; k++) {
				printf("%d\n", x[k]);
			}
		

	
		i = i + 1;
	}

	for (i = 0; i < n; i++) {
		printf(" %d", x[i]);

	}

}