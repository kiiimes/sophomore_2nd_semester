#include <stdio.h>
#include <stdlib.h>

void main() {
	int i=0, j=0,n,**p,cnt=0;

	scanf("%d", &n);

	p = (int**)malloc(n * sizeof(int*));

	for (i = 0; i < n; i++) {
		p[i] = (int*)malloc(n * sizeof(int));
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &(p[i][j]));
		}
		
	}





	while (p[i][j] == 1) {

		cnt++;
		j++;
	}//1인동안만 cnt++
	while (1) {
	
		i++;
		while (p[i][j] == 0) {
			
			j--;
		}
		cnt = cnt + j;
		if (n == i) {
			break;
		}



	}
	printf("%d", cnt);


	




}