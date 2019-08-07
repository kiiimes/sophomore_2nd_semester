#include <stdio.h>
#include <string.h>

int n;
double arr[9][9];
double sav[9];
int chk[9];
int cnt = 1;
int w = 0;

int check(int c) {
	for (int i = 0; i < n; i++) {
		if (c == chk[i]) return 0;
	}
	return 1;
}

int calc(int i,int j,int c) {
	

	if (c== (n-2)) {
		cnt++;
		return 0;
	}// 음음


	for (int k = j; k < n; k++) {
		for (int f = 0; f < n; f++) {
			if (arr[k][f] != 0&&check(f)) {
				chk[w++] = f;
				sav[cnt] += arr[k][f];
				calc(k, f,c+1);
			}
		}
	}

	return 0;

}//시작은 무족ㄴ 처음 부터 해도됨



int main() {

	int c;

	scanf("%d", &c);

	for (int i = 0; i < c; i++) {
		scanf("%d", &n);

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				scanf("%lf", &arr[j][k]);
			}
		}

		for (int j = 0; j < n; j++) {
			if (arr[0][j] != 0) {
				sav[j] = arr[0][j];
				memset(chk, -1, sizeof(chk));
				calc(0, j, 0);

			}
		}

		double min = sav[1];

		for (int j = 1; j < n; j++) {
			if (min > sav[j]) min = sav[j];
		}

		printf("%.10lf\n", min);
	}

}