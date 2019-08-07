#include <stdio.h>

int h[100];
int n;

void downHeap(int i) {
	int tmp;
	if (h[i] < h[i * 2 + 1] && h[i] < h[i * 2]) {
		if (h[i * 2] > h[i * 2 + 1]) {
			tmp = h[i];
			h[i] = h[i * 2];
			h[i * 2] = tmp;
			downHeap(i * 2);
		}
		else {
			tmp = h[i];
			h[i] = h[i * 2 + 1];
			h[i * 2 + 1] = tmp;

			downHeap(i * 2 + 1);
		}
	}
	else if (h[i]<h[i * 2 + 1]) {
		tmp = h[i];
		h[i] = h[i * 2 + 1];
		h[i * 2 + 1] = tmp;

		downHeap(i * 2 + 1);
	}
	else if (h[i] < h[i * 2]) {
		tmp = h[i];
		h[i] = h[i * 2];
		h[i * 2] = tmp;

		downHeap(i * 2);
	}
	else {
		return;
	}


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