#include <stdio.h>

int h[100];
int n;


void upHeap(int i) {
	int temp;
	if (i == 1) {
		return;
	}

	if (h[i] <= h[i / 2]) {
		return;
	}
	

	temp = h[i];
	h[i] = h[i / 2];
	h[i / 2] = temp;

	upHeap(i / 2);
}

void insertItem(int key) {
	h[n + 1] = key;
	n++;
	upHeap(n);
}

void printHeap() {
	int i;
	for (i = 1; i <= n; i++) {
		printf(" %d", h[i]);
	}
	printf("\n");

}

void downHeap(int i) {
	int tmp;
	if (h[i] < h[i / 2 + 1] && h[i] < h[i / 2]) {
		if (h[i / 2] < h[i / 2 + 1]) {
			tmp = h[i];
			h[i] = h[i / 2];
			h[i / 2] = tmp;
			downHeap(i / 2);
		}
		else {
				tmp = h[i];
				h[i] = h[i / 2+1];
				h[i / 2+1] = tmp;

				downHeap(i / 2+1);
		}
	}
	else if(h[i]<h[i/2+1]) {
		tmp = h[i];
		h[i] = h[i / 2 + 1];
		h[i / 2 + 1] = tmp;

		downHeap(i / 2+1);
	}
	else if (h[i] < h[i / 2]) {
		tmp = h[i];
		h[i] = h[i / 2];
		h[i / 2] = tmp;

		downHeap(i / 2);
	}
	else {
		return;
	}


}

int removeMax() {
	int sav = h[1];
	h[1] = h[n];
	h[n] = 0;
	downHeap(1);
	n--;
	return sav;

}

void main() {
	char type;
	int num;
	
	n = 0;

	while (1) {
		scanf("%c", &type);
		switch (type) {
		case 'i':scanf("%d", &num); insertItem(num); printf("0\n"); break;
		case 'd':printf("%d\n",removeMax()); break;
		case 'p':printHeap(); break;
		case 'q':return;
		}
		
		getchar();
	}
}