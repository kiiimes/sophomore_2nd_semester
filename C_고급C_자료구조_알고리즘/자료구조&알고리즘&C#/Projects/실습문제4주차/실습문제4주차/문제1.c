#include <stdio.h>

int H[100], n=0,cnt;

void swap(int *x, int *y) {
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}


void upHeap(int i) {
	int temp;
	if (i == 1) {
		return;
	}
	if (H[i] <= H[i / 2]) {
		return;
	}

	swap(&(H[i]), &(H[i / 2]));
	upHeap(i / 2);
}

void insertItem(int key) {
	n++;
	H[n] = key;
	upHeap(n);
}

void downHeap(int i) {
	int left = i * 2;
	int right = i * 2 + 1;
	int greater = left;

	if (left > cnt) {
		return;
	}

	if (right <= cnt) {
		if (H[right] > H[greater]) {
			greater = right;
		}
	}
	
	if (H[i] >= H[greater])return;

	swap(&H[i], &H[greater]);
	downHeap(greater);
}

void inPlaceHeapSort() {
	int i;
	for (i = n; i >= 2; i--) {
			swap(&H[1], &H[i]);
			cnt--;
			downHeap(1);
	}
}

void printArray() {
	int i;

	for (i = 1; i <= n; i++) {
		printf(" %d", H[i]);
	}
}

void main() {
	int i,num;

	scanf("%d", &cnt);

	for (i = 1; i <= cnt; i++) {
		scanf("%d", &num);
		insertItem(num);
	}
	inPlaceHeapSort();
	printArray();

}
