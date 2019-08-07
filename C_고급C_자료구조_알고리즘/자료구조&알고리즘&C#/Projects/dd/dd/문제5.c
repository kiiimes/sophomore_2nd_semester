#include <stdio.h>

void main() {
	int n, x[110], infnum, info[500],tmp,i,j,k,sav[500];

	scanf("%d", &n);//수열 개수
	for (i = 0; i < n; i++) {
		scanf("%d", x + i);//수열 입력
	}
	scanf("%d", &infnum);//위치 변환 개수 입력
	for (i = 0; i < infnum; i++) {
		scanf("%d", info+i);//위치 변환 순서 입력
	}

	for(i = 0; i < infnum; i++) {		
		sav[i] = x[info[i]];
	}

	for (i = 0; i < infnum; i++) {
		if (i == infnum - 1) {
			break;
		}
		
		x[info[i + 1]] = sav[i];
	}

	for (i = 0; i < n; i++) {
		printf(" %d", x[i]);
	}

}