#include <iostream>
using namespace std;
int main(){
	const int ARR_MAX = 100;
	int arr[ARR_MAX];
	int N; 
	cin>>N;
	if(N > ARR_MAX) {
		cout<<"Please enter a smaller array size";
		return -1;
	}
	else{
		for(int i = 0; i < ARR_MAX; i++){
			cin>>arr[i];
		}
	}
	for(int j = 1; j < N; j++){
		int temp = arr[j];
		int i;
		for(i = j-1; i >= 0; i--){
			if(arr[i]>temp){
				arr[i+1] = arr[i];
			}		
			else break;
		}	
		arr[i + 1] = temp;
	}
	for(int i = 0 ; i < N; i++){
		cout<<arr[i]<<"  ";
	}
	cout<<endl;
	return 0;
}
