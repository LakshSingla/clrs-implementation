#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ones(int x) {
	return x % 10;
}

int tens(int x) {
	x /= 10;
	return x % 10;
}

int hundreds(int x) {
	x /= 100;
	return x % 10;
}

int (*place_value[])(int) = {ones, tens, hundreds};

// a is the array, n is the size of the array, k is the range of the array
int counting_sort(int* a, int n, int k, int (*fn)(int)) {
	int *b = (int*)malloc(sizeof(int) * n);
	memset(b, 0, sizeof(int)*n);
	int *freq = (int*)malloc(sizeof(int)*k);
	memset(freq, 0, sizeof(int)*k);

	for(int i = 0; i < n; ++i) ++freq[fn(a[i])];
	for(int i = 1; i < k; ++i) freq[i] += freq[i-1];
	
	for(int i = n-1; i >= 0; --i) {
		b[--freq[fn(a[i])]]	= a[i];
	}

	for(int i = 0; i < n; ++i) a[i] = b[i]; 

	free(b);
	free(freq);
}

int radix_sort(int *a, int n, int d) {
	for(int i = 0; i < d; ++i) {
		counting_sort(a, n, 10, place_value[i]);		
	}
}

int identity (int a) {
	return a;
}




int main(void) {
	//int a[] = {3, 2, 4, 1, 1, 4, 7, 4, 2, 3, 3, 1};
	/*int a[] = {121, 214, 542, 725, 215, 125, 777, 12, 312, 422};
	counting_sort(a, 10, 10, place_value[1]);
	for(int i = 0; i < 10; ++i) printf("%d\t", a[i]); 
	printf("\n");*/
	
	int b[] = {121, 214, 542, 725, 215, 125, 777, 12, 312, 422};
	radix_sort(b, 10, 3);
	for(int i = 0; i < 10; ++i) printf("%d\t", b[i]); 
	printf("\n");

	return 0;
}
