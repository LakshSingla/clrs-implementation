#include <iostream>
#include <cmath>

int main() {
	int T;
	std::cin >> T;
	while(T--){
		int N;
		std::cin >> N;
		int arb = std::ceil(float(N)/2);
		std::cout << 1 << " " << 1;
		for(int i = 0; i < N - arb; i++) std::cout << 0;
		std::cout << std::endl;
	}
	return 0;
}
