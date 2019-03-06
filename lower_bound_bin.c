#include <stdio.h>


int find_lower_bound(int *arr, int low, int high, int elem) {
	if(high <= low) return arr[low] < elem ? low + 1 : low;
	else {
		int mid = (high+low)/2;
		if(arr[mid] == elem) return mid+1;
		else if(arr[mid] > elem) return find_lower_bound(arr, low, mid-1, elem);
		return find_lower_bound(arr, mid+1, high, elem);
	}
}

int main () {
	int arr[] = {1, 2, 4, 5, 8, 9};
	int n = 6;
	printf("%d\n", find_lower_bound(arr, 0, n-1, 10));
}
