#include <cmath>
#include <iostream>

bool is_prime(int n) {
	for(int i = 2; i < std::ceil(std::sqrt(n)); ++i)
		if(!(n % i)) return false;
	
	return true;
}

int main() {
	int n;
	std::cin >> n;
	for(int i = 2; i <= n; ++i){
		//std::cout << i << std::endl;
		if(is_prime(i)){
			while(!(n % i)) {
				n /= i;
				std::cout << i << (n != 1 ? " x " : " ");
			}
		}
	}

	std::cout << std::endl;
	return 0;
}
