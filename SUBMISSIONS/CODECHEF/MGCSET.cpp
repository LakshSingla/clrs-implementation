#include <iostream>
#include <cmath>

int main(){
	int T;
	std::cin >> T;
	while(T--){
		int n, m;
		int div = 0;
		int inp;
		std::cin >> n >> m;
		while(n--){
			std::cin >> inp; 
			if(!(inp % m)) ++div;
		}
		std::cout << static_cast<long long int>(std::pow(2, div)) - 1 << std::endl;	
	}
}

