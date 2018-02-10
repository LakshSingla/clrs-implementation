#include <iostream>
#include <limits>
using namespace std;

const int MAX_ARR_LENGTH = 100;
int N;
int arr[MAX_ARR_LENGTH];

//mergeSort() sorts array between its 2 parameters
void mergeSort(int, int);

//merge() combines 2 sorted array from a - b and b - c into a sorted 
//array
void merge(int, int, int);

void copy(int[], int[], int, int);

int main(){
	cin>> N;	
	for(int x = 0 ; x < N ; x++) cin>>arr[x];
	mergeSort(0, N - 1);
	cout<<endl;
	return 0;
}


//start and end are the indexes b/w where to merge
void mergeSort(int start, int end) {
	//Only works in non trivial cases when array size is not 1 or 0
	if(start < end){
		int mid = (start + end ) / 2;
	
		//DIVIDE STEP
		//Give me 2 sorted subarrays of that problem however you can
		mergeSort( start  , mid);
		mergeSort( mid + 1, end);

		//COMBINE STEP
		//With the 2 sorted subarrays you give me I will combine them to form the larger subarray 
		merge(start, mid, end);
	}
}

//2 sorted arrays are present from start - middle and middle - end
void merge(int start, int middle, int end){
	int  left[MAX_ARR_LENGTH/2 + 2];
	int right[MAX_ARR_LENGTH/2 + 2];

	copy(left , arr, start     , middle);
	copy(right, arr, middle + 1, end   );

	int leftCtr = 0, rightCtr = 0;

	while( left[leftCtr]   != std::numeric_limits<int>::max() && 
	       right[rightCtr] != std::numeric_limits<int>::max()
	       ){
		
		if(left[leftCtr] > right[rightCtr]){
			
			arr[start + leftCtr + rightCtr] = right[rightCtr];
			rightCtr++;

		}
		else{
			arr[start + leftCtr + rightCtr] = left[leftCtr];
			leftCtr++;		
		}
	}
}

void copy(int newArr[] , int originalArr[], int oStart, int oEnd){
	int j ;
	for(int i = oStart, j = 0; i <= oEnd; i++, j++ ){
		newArr[j] = originalArr[i];
	}	
	newArr[j] = std::numeric_limits<int>::max();	
}
