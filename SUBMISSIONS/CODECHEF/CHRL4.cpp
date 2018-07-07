#include <iostream>
#include <vector>
#include <limits>

#define MOD 1000000007

using ull = unsigned long long; 

int main () {
	ull n, k; 
	std::cin >> n >> k; 
	std::vector<ull>a(n);
	std::vector<ull>cache(n);
	for(int i = 0; i < n; ++i) {
		ull inp;
		std::cin >> inp;
		a[i] = inp ;
	}

	//std::cout << n << " " << k << std::endl;
	
	//for(const auto& elem : a) std::cout << elem << "* ";

	//std::cout << std::endl;

	for(int i = 0; i < n; i++) {
		if (i == 0) cache[i] = 0;
		else if (i <= k) cache[i] = a[n-1];
		else {
			ull min = std::numeric_limits<ull>::max();
			for (int j = i-1; j>=(i-k); j--){
				ull dist = a[j] * cache[j];
				//min	> a[j] * cache[j] ?
				min = (min > dist ? dist : min);
			}

			cache[i] = min;
		}
	}

	std::cout << cache[n-1] % MOD << std::endl; 
	
}

