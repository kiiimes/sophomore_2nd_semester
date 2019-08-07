#include <stdio.h>
#include <string.h>

//미완


int h, w;
int cnt = 0;

int isEmpty(char arr[][22]) {
	int i, j, f = 0;
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			if (arr[i][j] == '.') {
				f = 1;
				break;
			}
		}
		if (f == 1) return 1;
	}
	return 0;
}


int calc(int type, int startw, int starth,char arr[][22]) {

	

	//type==1일때 
	switch (type) {
	case 1:if ((startw - 1) < 0 || (starth + 1) >= h||arr[starth][startw-1]=='#'|| arr[starth][startw] == '#'|| arr[starth + 1][startw] == '#') return 0; arr[starth][startw - 1] = '#'; arr[starth][startw] = '#'; arr[starth + 1][startw] = '#'; break;
	case 2: if ((startw + 1) >= w || (starth -1) < 0|| arr[starth][startw] == '#'||arr[starth - 1][startw] == '#'|| arr[starth][startw + 1] == '#') return 0; arr[starth][startw] = '#'; arr[starth - 1][startw] = '#'; arr[starth][startw + 1] = '#'; break;
	case 3:if ((startw + 1) >= w || (starth + 1) >= h||arr[starth][startw]=='#'||arr[starth][startw+1]=='#'||arr[starth+1][startw]=='#') return 0; arr[starth][startw] = '#'; arr[starth][startw + 1] = '#'; arr[starth + 1][startw] = '#'; break;
	case 4:if ((startw - 1) < 0 || (starth - 1) < 0||arr[starth][startw-1]=='#'||arr[starth-1][startw]=='#'||arr[starth][startw]=='#') return 0; arr[starth][startw] = '#'; arr[starth][startw - 1] = '#'; arr[starth - 1][startw] = '#'; break;
	}

	if (!isEmpty(arr)) {
		cnt++;
		return 1;
	}

	int i, j, f = 0;
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			if (arr[i][j] == '.') {
				if (calc(1, j, i, arr)) arr[j][i] = '.'; arr[j][i - 1] = '.'; arr[j + 1][i] = '.';
				if (calc(2, j, i, arr)) arr[j][i] = '.'; arr[j - 1][i] = '.';arr[j][i+1]='.';
				if (calc(3, j, i, arr)) arr[j][i] = '.'; arr[j + 1][i] = '.'; arr[j][i + 1] = '.';
				if (calc(4, j, i, arr)) arr[j][i] = '.'; arr[j - 1][i] = '.'; arr[i][j - 1] = '.';
			}
		}
	}
	
	return 0;
}
//중간 블럭을 기준점으로 잡


int main() {
	int c;
	char arr[22][22] = { '\0' };

	scanf("%d", &c);

	for (int i = 0; i < c; i++) {
		cnt = 0;
		scanf("%d %d", &h, &w);

		for (int j = 0; j < h; j++) {
			getchar();
			scanf("%s",arr+j); 
		}
		int j, k, f = 0;
		for (j = 0; j < h; j++) {
			for (k = 0; k < w; k++) {
				printf(" %c ", arr[j][k]);
				if (arr[j][k] == '.') {
					f = 1;
					break;
				}
			}
			if (f == 1) break;
		}

		calc(1, k, j, arr);
		calc(2, k, j, arr);
		calc(3, k, j, arr);
		calc(4, k, j, arr);

		printf("%d\n", cnt);
	}

}