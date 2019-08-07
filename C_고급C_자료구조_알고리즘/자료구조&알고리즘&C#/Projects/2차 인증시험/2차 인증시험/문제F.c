#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
	// 위아래좌우자기 합 을 그 자기 자리에 넣는거
	int h, y,**p,**sav;
	int i, j;

	scanf("%d %d", &h, &y);

	p = (int**)malloc(h * sizeof(int*));
	sav = (int**)malloc(h * sizeof(int*));
	

	for (i = 0; i < h; i++) {
		p[i] = (int*)malloc(y * sizeof(int));
		sav[i] = (int*)malloc(y * sizeof(int));

		for (j = 0; j < y; j++) {
			scanf("%d", &(p[i][j]));
		}
	}//입력

	if (h == 1) {
		for (i = 0; i < h; i++) {
			for (j = 0; j < y; j++) {
				if (j == 0) {
					sav[i][j] = p[i][j] + p[i][j + 1];
				}
				else if (j == (y - 1)) {
					sav[i][j] = p[i][j] + p[i][j -1];
				}
				else {
					sav[i][j] = p[i][j] + p[i][j + 1]+p[i][j-1];
				}
			}
		}
	}
	else if (y == 1) {
		for (i = 0; i < h; i++) {
			for (j = 0; j < y; j++) {
				if (i==0) {
					sav[i][j] = p[i][j] + p[i+1][j];
				}
				else if (i == (h - 1)) {
					sav[i][j] = p[i][j] + p[i-1][j];
				}
				else {
					sav[i][j] = p[i][j] + p[i+1][j] + p[i-1][j];
				}
			}
		}
	}
	else {
		for (i = 0; i < h; i++) {
			for (j = 0; j < y; j++) {
				if (i == 0 && j == 0) {//왼쪽 위 끝
					sav[i][j] = p[i][j] + p[i][j + 1] + p[i + 1][j];

				}
				else if (i == (h - 1) && j == (y - 1)) {//오른쪽 아래 끝
					sav[i][j] = p[i][j] + p[i - 1][j] + p[i][j - 1];
				}
				else if (i == (h - 1) && j == 0) {//왼쪽 아래 끝
					sav[i][j] = p[i][j] + p[i - 1][j] + p[i][j + 1];
				}
				else if (i == 0 && j == (y - 1)) {//오른쪽 위 끝
					sav[i][j] = p[i][j] + p[i][j - 1] + p[i + 1][j];
				}
				else if (i == 0) {
					sav[i][j] = p[i][j] + p[i][j - 1] + p[i][j + 1] + p[i + 1][j];
				}
				else if (j == 0) {
					sav[i][j] = p[i][j] + p[i - 1][j] + p[i + 1][j] + p[i][j + 1];
				}
				else if (i == (h - 1)) {
					sav[i][j] = p[i][j] + p[i][j -1] + p[i][j + 1] + p[i - 1][j];
				}
				else if (j == (y - 1)) {
					sav[i][j] = p[i][j] + p[i - 1][j] + p[i + 1][j] + p[i][j - 1];
				}
				else {
					sav[i][j] = p[i][j] + p[i - 1][j] + p[i + 1][j] + p[i][j - 1] + p[i][j + 1];
				}
				
			}
			
		}

	}


	for (i = 0; i < h; i++) {
		for (j = 0; j < y; j++) {
			printf(" %d", sav[i][j]);
		}
		printf("\n");
	}
}