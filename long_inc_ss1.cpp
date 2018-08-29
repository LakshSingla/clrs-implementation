//Start searching from the last
//The element can be in the subsequence or will not be in the subsequence
//if element is in the subsequence , the length becomes 1 + ... and cap changes
//else the cap remains same and the length becomes ...
#include <iostream>
#include <vector>
#include <limits>

int long_subseq(const std::vector<int>& inp, int index, int cap){

	if(index == -1) return 0;
	
	int included_length, not_included_length;

	/*if(cap == -1){
		included_length = 1 + long_subseq(inp, index-1, inp[index]);
		not_included_length =  long_subseq(inp, index-1, -1);
	}*/

	if(inp[index] <= cap){
		included_length = 1 + long_subseq(inp, index-1, inp[index]);
		not_included_length =  long_subseq(inp, index-1, cap);
	}
	else {
		return long_subseq(inp, index-1, inp[index]);	
	}
	return included_length > not_included_length ? 
		   included_length : 
		   not_included_length; 
}

int main(){
	int n;
	std::cin >> n;
	std::vector<int> inp(n);
	for(int i = 0; i < n; ++i){
		std::cin >> inp[i];	
	}
	std::cout << long_subseq(inp, n-1, std::numeric_limits<int>::max());
	return 0;
}
