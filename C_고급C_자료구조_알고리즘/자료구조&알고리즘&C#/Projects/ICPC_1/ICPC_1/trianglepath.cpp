#include <stdio.h>

int n;
int arr[101][101] = { 0 };
int sarr[101][101] = { 0 };
int sMax  = 0;

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int calMax(int gindex, int sindex, int cnt, int sav) {
	sarr[sindex][gindex] = sav;

	if (arr[sindex][gindex] == 0) return 0; //리턴값 뭘로 할지 정해야됨
	if (sarr[sindex][gindex] != 0) {

	}
	if (cnt == (n - 1)) {
		sav += arr[sindex][gindex];
		sarr[sindex][gindex] = sav;
		sMax = max(sMax, sav);
		return 0;
	}

	calMax(gindex, sindex + 1, cnt + 1, sav + arr[sindex][gindex]);
	calMax(gindex + 1, sindex + 1, cnt + 1, sav + arr[sindex][gindex]);

	return 0;
}

int main() {
	int c;

	scanf("%d", &c);

	for (int i = 0; i < c; i++) {
		sMax = 0;

		scanf("%d", &n);

		for (int j = 0; j < n; j++) {
			for (int k = 0; k <= j; k++) {
				scanf("%d", &(arr[j][k]));
			}
		}
		for (int j = 0; j < n; j++) {
			sMax += arr[j][0];
		}
		calMax(0, 0, 0, 0);

		printf("%d\n", sMax);
	}



}