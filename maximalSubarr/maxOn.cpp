#include <iostream>
#include <vector>
#include <iterator>
#include <utility>

struct SumInfo { 
	std::vector<int>::const_iterator start;
	std::vector<int>::const_iterator end;
	int sum;
};

int main(void) {
	std::vector<int> arr{13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12,-5, -22, 15, -4, 7};	
	//std::vector<int>::const_iterator max_arr_begin, max_arr_end;
	SumInfo whole{
		arr.cbegin(),	
		arr.cbegin(),	
		0
	};
	SumInfo ending_j{
		arr.cbegin(),	
		arr.cbegin(),
		0
	};
	for(auto it = arr.cbegin(); it != arr.cend(); ++it) {
		auto lol =  ending_j.sum > 0;
		SumInfo ending_j1;
		if(lol)
			ending_j1 = {
				ending_j.start,
				it+1,
				ending_j.sum + (*it)
			};
		else if(*it > 0)
			ending_j1 = {
				it,
				it+1,
				*it
			};
		else 
			ending_j1 = {
				it+1,
				it+1,
				0
			};
		if(ending_j1.sum >= whole.sum) {
			whole = ending_j1;	
		}
		ending_j = std::move(ending_j1);
		std::cout << "Till " << std::distance(arr.cbegin(), it) << ": "\
			<< std::distance(arr.cbegin(), whole.start) << " "\
			<< std::distance(arr.cbegin(), whole.end) << " "\
			<< whole.sum << std::endl;
		std::cout << "Till " << std::distance(arr.cbegin(), it) << ": "\
			<< std::distance(arr.cbegin(), ending_j1.start) << " "\
			<< std::distance(arr.cbegin(), ending_j1.end) << " "\
			<< ending_j1.sum << std::endl;
		std::cout << std::endl;
	}
	int x = std::distance(arr.cbegin(), whole.start);
	int y = std::distance(arr.cbegin(), whole.end);
	std::cout << std::endl;
	std::cout << x  << "-" << y << ": ";
	std::cout << whole.sum;
	return 0;
}
