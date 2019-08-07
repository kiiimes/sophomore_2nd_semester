#include <stdio.h>
#include <stdlib.h>

int N;
int M;
int q;

typedef struct Node {
	int key;
	int tag;
}Node;

void init(Node *arr) {
	int i;

	for (i = 0; i < M; i++) {
		arr[i].key = 0;
		arr[i].tag = 0;
	}
}
int getNextBucket(int v, int i,int num) {
	return (v + i*(q-(num%q))) % M;
}

void insertItem(Node *arr, int num) {
	int sav = num%M;
	int i = 0;

	while (i<M) {
		sav = getNextBucket(num%M, i,num);
		if (arr[sav].tag == 0) {
			arr[sav].key = num;
			arr[sav].tag = 1;
			printf("%d\n", sav);
			return;
		}
		else {
			printf("C");
			i++;
		}
	}
}


int findElement(Node *arr, int num) {
	int sav = num%M;
	int i = 0;

	while (i < M) {
		sav = getNextBucket(num%M, i,num);
		if (arr[sav].tag == 0) return -1;
		else if (num == arr[sav].key) {
			printf("%d ", sav);
			return arr[sav].key;
		}
		else i++;
	}
	return -1;


}

void printArr(Node *arr) {
	int i;

	for (i = 0; i < M; i++) {
		printf(" %d", arr[i].key);
	}
	printf("\n");
}

void main() {
	int num;
	char type;
	Node *arr;

	scanf("%d %d %d", &M, &N, &q);

	arr = (Node*)malloc(sizeof(Node)*M);

	init(arr);

	while (1) {
		getchar();
		scanf("%c", &type);
		switch (type) {
		case 'i':scanf("%d", &num); insertItem(arr, num); break;
		case 's':scanf("%d", &num); printf("%d\n",findElement(arr, num)); break;
		case 'p':printArr(arr); break;
		default:break;
		}
		if (type == 'e') { 
			printArr(arr);
			break; 
		}
	}

	free(arr);
}