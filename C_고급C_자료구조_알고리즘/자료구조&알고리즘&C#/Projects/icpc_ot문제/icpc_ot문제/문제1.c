#include <stdio.h>

void insertionSort(int *inp) {
	int i,sav,j;

	for (i = 1; i < 9; i++) {
		sav = inp[i];
		j = i - 1;
		while ((j >= 0)&(inp[j] > sav)) {
			inp[j + 1] = inp[j];
			j = j - 1;
		}
		inp[j + 1] = sav;
	}
}

void printSum(int *sav) {
	int i;

	for (i = 0; i < 9; i++) {
		if (sav[i] != 0) {
			printf("%d\n", sav[i]);
		}
	}
}

void isSum(int *sav) {
	int i, s = 0;

	for (i = 0; i < 9; i++) {
		s += sav[i];
	}
	if (s == 100) {
		printSum(sav);
	}
}

void combination(int *inp,int *sav, int n,int r) {
	if (r == 0) {
		isSum(sav);
		return;
	}
	else if (n < r) {
		return;
	}
	else {
		sav[r - 1] = inp[n - 1];
		combination(inp,sav,n - 1, r - 1);
		combination(inp, sav, n - 1, r);
	}
}

int main() {
	int inp[9],i;
	int sav[9] = { 0 };
	int sum=0;

	for (i = 0; i < 9; i++) {
		scanf("%d", inp + i);
	}

	insertionSort(inp);

	combination(inp, sav, 9, 7);

	return 0;
}