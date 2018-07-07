#include <iostream> 
#include <cmath>

int main () {
	int T; 
	std::cin >> T ; 
	while(T--){
		long long int a, b, n ; 
		std:: cin >> a >> b >> n; 
		if(!(n % 2)) {
			a = std::abs(a);
			b = std::abs(b);
		}
		if(a > b) std::cout << 1; 
		else if( a < b ) std::cout << 2; 
		else std::cout << 0 ;
		std::cout << std::endl;
	}
}
