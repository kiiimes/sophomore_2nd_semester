void insert(HeapType &h, element item) {
	int i;
	i = ++(h->heap_size);
	while (i != 1 && key > heap[i / 2].key) {
		heap[i]=heap[i/2]
		i/=2
	}
	h->heap[i] = item;
}

void delete(HeapTpe *h){
	int parent, child;
	item = h[1];
	temp = h[max_size--];
	parent = 1;
	child = 2;
	while (child <= maxsize) {
		if (child < maxsize&&h->[child].key < h->[child + 1].key) {
			child += 1;
		}
		if (temp.key >= h->parent ÀÚ¸®) {
			break;

		}
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;

}