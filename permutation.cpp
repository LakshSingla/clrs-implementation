#include <iostream>
#include <utility>

template <typename T>
void print_all_permutations(T *arr, int n, int r){
	if(r == n - 1){
		for(int i = 0; i < n; i++){
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
		return;
	}
	for(int i = r; i < n; i++){
		std::swap(arr[r], arr[i]);
		print_all_permutations(arr, n, r+1);
		std::swap(arr[r], arr[i]);
	}
}

int main(){
	int arr[] =  {1, 2, 3};
	print_all_permutations(arr, 3, 0);
}
