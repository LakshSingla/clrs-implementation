#include <iostream>
#include <utility>

#define MOD 1000000007

using ull = unsigned long long; 

using ulla = int[100000];

ull ways_to_go (int n, int k) {
	
	static ulla cachek = {};
	if(cachek[n]) return cachek[n];

	ull ways = 0;

	for(int i = 1; i <= k; i++) {
		if (i > n) break;
		else ways += 1 + ways_to_go(n-k, k);
	}

	cachek[n] = ways_to_go;

	return ways_to_go;
}

ull min_price (int n, int k, const std::vector& v) {
	if (n <= k) return v[n-1];
	
	ull prices = 
	for(int i = 1; i <= k; i++) {

	}
}

