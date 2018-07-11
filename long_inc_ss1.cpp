#include <iostream>
#include <vector>

int long_subseq(const std::vector& inp, int index, int cap){
	int included_length = 1 + long_subseq(inp, len-1, );
	int not_included_length =  long_subseq(inp, len-1, );
	return included_length > not_included_length ? 
		   included_length : 
		   not_included_length; 
}

int main(){
	int n;
	std::cin >> n;
	std::vecor<int> inp(n);
	for(int i = 0; i < n; ++i){
		std::cin >> inp[i];	
	}
	//std::cout << long_subseq(inp, n-1, inp[n-1]);
	return 0;
}
