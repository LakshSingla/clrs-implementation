#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <string>

#define MOD 1000000007
//#define MOD 3

using ull = unsigned long long; 

int main () {
	ull n, k; 
	std::cin >> n >> k; 
	std::vector<ull>a(n);
	std::vector<long double>cache(n);
	std::vector<ull> path(n);
	for(int i = 0; i < n; ++i) {
		ull inp;
		std::cin >> inp;
		a[n-1-i] = inp ;
	}

	//std::cout << n << " " << k << std::endl;
	
	//for(const auto& elem : a) std::cout << elem << "* ";

	//std::cout << std::endl;

	for(int i = 0; i < n; i++) {
		if (i == 0) {
			cache[i] = 0;
			path[i] = 0;
		}
		else if (i <= k){ 
			cache[i] = std::log10(a[0]);
			path[i] = 0;
		}
		else {
			//long double min = std::numeric_limits<long double>::max();
			long double min = std::log10(a[i]) + std::log10(a[i-1]) + cache[i-1];
			ull next_jump = i-1;
			for (int j = i-1; j >= (i-k); j--){
				long double dist = std::log10(a[i]) + std::log10(a[j]) + cache[j];
				//min	> a[j] * cache[j] ?
				min       = (min > dist ? dist : min);
				next_jump = (min > dist ? j    : next_jump);

			}
			path[i] = next_jump;
			cache[i] = min;
		}
	}
	
	//for(const auto&elem : path) std::cout << elem << "\n";
	//std::cout << std::endl;
	//std::cout << "**********************";
	//for(const auto&elem : cache) std::cout << elem << "\n";
	std::cout << std::endl;
	//std::cout << "**********************";

	{
		ull ans = 1;
		int x = n-1;
		int i = 0;
		while(x) {
			ans *= (a[x] % MOD);
			if (i < 100) std::cout << ans << std::endl;
			x = path[x];
		}
		ans *= (a[0] % MOD);
		ans %= MOD; 
		std::cout << ans;
		std::cout << std::endl;
	}
	//std::cout << cache[n-1] << std::endl; 
	//std::cout << std::log10(4) << std::endl; 


	
}

