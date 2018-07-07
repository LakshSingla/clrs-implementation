#include <iostream>

bool find_sum(int *arr, int *final_arr, const int arr_l, const int final_arr_l, const int sum){
	int cur_sum = 0;
	for(int i = 0; i < final_arr_l; i++) cur_sum += i; 

	if (sum == cur_sum)  return true;
	
	else if(arr_l == 0) return false; 

	for(int i = arr_l-1; i >= 0; i--){
		int to_push = arr[i];
		final_arr[final_arr_l] = to_push;
		if(find_sum(arr, final_arr, arr_l-1, final_arr_l+1, sum-to_push)) return true; 

	}

	return false ;
}

int main(){

	int arr[] = {1, 32, 39, 4, 5, 61, 17};
	int arr_l = sizeof(arr)/sizeof(arr[0]);
	int sum = 9; 
	int final_arr[10];
	
	find_sum(arr, final_arr, arr_l, 0, sum);

	for(int i = 0; i < 10; i++) std::cout << final_arr[i] << " "  ;

	std::cout << std::endl;

}
