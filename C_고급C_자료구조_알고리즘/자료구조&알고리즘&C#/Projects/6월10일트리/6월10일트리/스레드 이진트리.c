#include <stdio.h>
#define MAX_ELEMENT 200

typedef struct {
	int key;
}element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

void init(HeapType *h) {
	h->heap_size = 0;//�迭�� ��ó���� 0���� �ʱ�ȭ
}

void main() {
	element e1 = 10, e2 = 5, e3 = 30;
	element e4, e5, e6;
	HeapType heap;
	init(&heap);

	insert_max_heap(&heap, e1);


}