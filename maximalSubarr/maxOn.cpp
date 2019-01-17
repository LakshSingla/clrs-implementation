#include <iostream>
#include <vector>
#include <iterator>
#include <utility>

// Structure containing :-
// 1. Iterator to the first element in the container
// 2. Iterator to one past the last element in the container
// 3. Sum from first to last

struct SumInfo { 
	std::vector<int>::const_iterator start;
	std::vector<int>::const_iterator end;
	int sum;
};

int main(void) {
	std::vector<int> arr{13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12,-5, -22, 15, -4, 7};	
	//std::vector<int>::const_iterator max_arr_begin, max_arr_end;
	//SumInfo of maximal subarray of whole array
	SumInfo whole{
		arr.cbegin(),	
		arr.cbegin(),	
		0
	}; //Begin with empty array and 0 sum
	//Sum info of whole array ending with j
	SumInfo ending_j{
		arr.cbegin(),	
		arr.cbegin(),
		0
	}; //
	for(auto it = arr.cbegin(); it != arr.cend(); ++it) {
		auto can_add_safely =  ending_j.sum + *it > 0; //If last element along with the sum of previous elements > 0
		//then we can include it in the maximal subarray ending with j (value in the current iteration)
		//Else the maximal subarray ending with j has to be minimum
		SumInfo ending_j1;
		if(can_add_safely)
			ending_j1 = {
				ending_j.start,
				it+1,
				ending_j.sum + (*it)
			};
		else 
			ending_j1 = {
				it+1,
				it+1,
				0
			};

		//Maximal subarray till it can have two posibilies : 
		//a) It can end in j ->  ( done above )
		//		To find maximal subarray ending in j it can have 2 possibilites
		//			We include it => maximal array upto it-1 + it
		//			We donot include it => empty ( as it has to be necessarily included)
		//b) OR it cannot end in j -> maximal subarray upto it-- (i.e maximal subarray of previous loop only)
		if(ending_j1.sum >= whole.sum) {
			whole = ending_j1;	
		}
		ending_j = std::move(ending_j1);
		/* std::cout << "Till " << std::distance(arr.cbegin(), it) << ": "\
			<< std::distance(arr.cbegin(), whole.start) << " "\
			<< std::distance(arr.cbegin(), whole.end) << " "\
			<< whole.sum << std::endl;
		std::cout << "Till " << std::distance(arr.cbegin(), it) << ": "\
			<< std::distance(arr.cbegin(), ending_j1.start) << " "\
			<< std::distance(arr.cbegin(), ending_j1.end) << " "\
			<< ending_j1.sum << std::endl;
		std::cout << std::endl; */
	}
	int x = std::distance(arr.cbegin(), whole.start);
	int y = std::distance(arr.cbegin(), whole.end);
	std::cout << std::endl;
	std::cout << x  << "-" << y << ": ";
	std::cout << whole.sum;
	return 0;
}
