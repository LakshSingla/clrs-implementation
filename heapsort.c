#include <stdio.h>
#include <stdbool.h>

typedef struct {
	int heap[30];
	int heap_len;
} heap_struct; 


int left_child(int x) {
	return (x << 1) + 1;
}

int right_child(int x) {
	return (x << 1) + 2;
}

int parent(int x) {
	return ((x - 1) >> 1);
}

void swap (int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y  = temp;
}

void max_heapify(heap_struct *h, int x) {
	int left = left_child(x);
	int right = right_child(x);
	bool left_exists = left < h->heap_len;
	bool right_exists = right < h->heap_len;
	int max = x;
	if(left_exists && (h->heap)[left] > (h->heap)[max]) max = left;
	if(right_exists && (h->heap)[right] > (h->heap)[max]) max = right;

	/*for(int i = 0; i < h->heap_len; ++i) printf("%d\t", h->heap[i]);
	printf("\n");
	printf("x: %d\t", x);
	printf("[x]: %d\t", h->heap[x]);
	printf("left: %d\t", left);
	printf("[left]: %d\t", h->heap[left]);
	printf("right: %d\t", right);
	printf("[right]: %d\t", h->heap[right]);
	printf("max: %d\t", max);
	printf("[max]: %d\n", h->heap[max]);
	printf("\n");*/

	if(max != x) {
		swap(h->heap+x, h->heap+max);
		max_heapify(h, max);
	}
}

void max_heapify_iter(heap_struct *h, int x) {
	while(true) {
		int left = left_child(x);
		int right = right_child(x);
		bool left_exists = left < h->heap_len;
		bool right_exists = right < h->heap_len;
		int max = x;
		if(left_exists && h->heap[max] < h->heap[left]) max = left;
		if(right_exists && h->heap[max] < h->heap[right]) max = right;
		if (max != x) {
			swap(h->heap + x, h->heap + max);
			x = max;
			continue;
		}
		break;
	}
}

void make_max_heap(heap_struct *h) {
	int a = h->heap_len / 2 - 1;
	while(a >= 0) {
		max_heapify_iter(h, a);	
		--a;
	}
}

void heapsort(heap_struct *h) {
	make_max_heap(h);	
	while(h->heap_len){
		swap(h->heap, h->heap + h->heap_len-1);	
		--(h->heap_len);
		max_heapify_iter(h, 0);
	}
}


int main() {
	heap_struct x = {
		//.heap = {4, 9, 8, 7, 6, 5, 3, 2, 1, 0},
		.heap = {4, 3, 1, 2, 5, 9, 8, 6, 0, 7},
		.heap_len = 10
	};
	//max_heapify(&x, 0);
	//make_max_heap(&x);
	heapsort(&x);
	for(int i = 0; i < 10; ++i) printf("%d\t", x.heap[i]);
	printf("\n");
}
