#include <stdio.h>

int n;
int arr[101][101] = { 0 };
int finish=0;

int movement(int gindex,int sindex) {
	if ( gindex >= n || sindex >= n) {
		return 0;
	}
	if (gindex == (n - 1) && sindex == (n - 1)) {
		finish = 1;
		return 0;
	}
	movement(gindex + arr[sindex][gindex], sindex);
	movement(gindex, sindex + arr[sindex][gindex]);
}

int main() {
	int c;
	int i,j, k;

	scanf("%d", &c);

	for (i = 0; i < c; i++) {
		finish = 0;
		scanf("%d", &n);

		for (j = 0; j < n; j++) {
			for (k = 0; k < n; k++) {
				scanf("%d", &(arr[j][k]));
			}
		}
		movement(0, 0);
		if (finish == 1) printf("YES\n");
		else if (finish == 0) printf("NO\n");
	}
}