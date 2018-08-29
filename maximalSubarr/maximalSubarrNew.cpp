#include <iostream>
using namespace std;

const int MAX_ARR_SIZE = 100;

int arr[MAX_ARR_SIZE];
int arrSize = 16;

//start  = starting index of the subarray till which you can search
//end    = ending index of the subarray till which you can search
//middle = middle of the subarray which is always to be included 
//sum    = sum of the subarray from start to end

struct Subarray{
	int start;
	int middle;
	int end;
	int sum;
};

Subarray maximalCenterSubarray(int* , Subarray);

Subarray maximalSubarray(int* , Subarray);

int main(){
	int x[16] = {13, -3, -25, 20, -3, 16, 23, 18, 20, -7, 12,-5, -22, 15, -4, 7};	
	//cout<<maximalCenterSubarray(x, {0, 6, 15, -1}).start;
	//cout<<maximalCenterSubarray(x, {0, 6, 15, -1}).end;
	Subarray max = maximalSubarray(x, {
				0, -1, arrSize - 1, -1	
			});
	cout<<max.start<<"\t"<<max.middle<<"\t"<<max.end<<"\t"<<max.sum;
	cout<<endl;
	return 0;
}

Subarray maximalCenterSubarray(int *a, Subarray s){
	Subarray returnSubarr;
	int leftSum  = a[s.middle];
	int rightSum = 0; 
	for(int i = -1; i + s.middle >= s.start; i--){
		if(a[i + s.middle] < 0) {
			returnSubarr.start = s.middle + i + 1;
			break;
		}
		cout<<a[s.middle + i]<<endl;
		leftSum += a[i];
	}
	for(int i = 1; i + s.middle <= s.end ; i++){
		if(a[i + s.middle] < 0) {
			returnSubarr.end = s.middle + i - 1;
			break;
		}
		cout<<a[s.middle + i]<<endl;
		rightSum += a[i];
	}
	returnSubarr.sum = leftSum + rightSum;
	returnSubarr.middle = s.middle;
	return returnSubarr;
}
/*
Subarray maximalSubarray(int* a, Subarray s){
	Subarray returnSubarr;	
	int middle = (s.start + s.end);
	if(s.start == s.end){
		return {
			s.start, s.start, s.start, a[s.start]
		};
	}
	int leftArrSum = maximalSubarray(arr,{
				s.start, -1 , middle - 1, -1 
			});
	int rightArrSum = maximalSubarray(arr, {
				middle + 1, -1, s.end, -1
			});
	int middleArrSum = maximalCenterSubarray(arr, {
				
			}); 
}
*/

Subarray maximalSubarray(int *a, Subarray s){
	if (s.start == s.end) {
		return {
			s.start, -1, s.end, a[s.start]
		};
	}

	Subarray middleSumStruct = maximalCenterSubarray(a, {
				s.start, (s.end - s.start)/2, s.end, -1	
			});		

	Subarray leftSumStruct   = maximalSubarray(a, {
				s.start, -1, (s.end - s.start)/2, -1 
			});

	Subarray rightSumStruct  = maximalSubarray(a, {
				(s.end-s.start)/2 + 1, -1, s.end, -1
			});

	if(middleSumStruct.sum > leftSumStruct.sum && middleSumStruct.sum > rightSumStruct.sum) {
		return middleSumStruct;	
	}

	else if(leftSumStruct.sum > middleSumStruct.sum && leftSumStruct.sum > rightSumStruct.sum){
		return leftSumStruct;
	}

	return rightSumStruct;

}
