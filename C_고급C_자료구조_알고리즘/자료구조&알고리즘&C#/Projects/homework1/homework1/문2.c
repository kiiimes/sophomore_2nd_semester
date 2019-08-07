#include <stdio.h>

int h[100];
int n;

void swap(int *x, int *y) {
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}


void downHeap(int i) {
	if (i * 2 > n && (i * 2 + 1) > n) {
		return;
	}
	int left = i * 2;
	int right = i * 2 + 1;
	int bigger = left;

	if (right <= n) {
		if (h[right] > h[bigger]) {
			bigger = right;
		}
	}
	if (h[i] >= h[bigger])return;

	swap(&h[i], &h[bigger]);

	downHeap(bigger);


}

void rBuildHeap(int i) {
	if (i > n) {
		return;
	}
	rBuildHeap(2 * i);
	rBuildHeap(2 * i + 1);
	downHeap(i);
	return;
}

void printHeap() {
	int i;
	for (i = 1; i <= n; i++) {
		printf(" %d", h[i]);
	}
	printf("\n");

}


void main() {
	int i;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		scanf("%d", h + i);
	}

	rBuildHeap(1);
	printHeap();

}