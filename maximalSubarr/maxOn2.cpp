#include <iostream>

using namespace std;

#define ARRLENGTH 16


int main () {
	int minIndex = 0, maxIndex = 0;
	int arr[ARRLENGTH] = { 0};
	for(int i = 0; i < ARRLENGTH; i++) cin>>arr[i];
	int maxSum = arr[0];

	for(int i = 0; i < ARRLENGTH - 1; i++ ) {
		int contSum = arr[i];
		if ( contSum > maxSum ) { 
			maxSum = contSum;
			minIndex = i ; maxIndex = i;
		}

		for(int j = i + 1; j < ARRLENGTH; j++) {

			contSum += arr[j];
			if ( contSum > maxSum ) { 
				maxSum = contSum;
				minIndex = i ; maxIndex = j;
			}
		}

	}
	cout<<minIndex<<"\t"<<maxIndex<<endl;
	return 0;
}
