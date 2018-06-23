#include <iostream>
#include <vector>

std::vector<int>::const_iterator peak_finder(
		std::vector<int>::const_iterator begin, 
		std::vector<int>::const_iterator end
	){
	
	std::vector<int>::const_iterator mid = begin + (end-begin)/2;
	
	if(mid != begin && *mid < *begin) 
		return peak_finder(begin, mid); 

	else if (mid != end-1 && *mid < *(end-1))
		return peak_finder(mid+1, end);
	
	else return mid;
}

int main() {
	std::vector<int> v{1, 2, 3, 5, 7, 6, 3, 2, 1};
	std::vector<int>::const_iterator peak = peak_finder( v.cbegin(), v.cend() );
	std::cout << "One of the peak value is: " << *peak << std::endl;
	return 0;
}
