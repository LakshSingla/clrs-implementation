//To test the Fermat's theorem

#include <iostream>
#include <cstdlib>
#include <ctime>

int power (int a, unsigned int n, int p) {
	int res = 1; 
	a %= p; 
	while(n > 0) {
		if (n & 1)	res = (res * a) % p;

		n >>= 1; 
		a = (a * a) % p;
	}
	return res;
}

bool isPrime(unsigned int n, int k) {
	if (n == 1 || n == 4 ) return false; 
	if (n <= 3) return true;

	while( k > 0) {
		int a = 2 + std::rand() % (n-4);
		if(power(a, n-1, n) != 1) return false;
		
		k--;
	}
	return true;
}

int main () {
 	std::srand(std::time(NULL));
	int k = 3;

	std::cout << std::boolalpha; 
	isPrime(11, k) ? std::cout << true : std::cout << false; std::cout << std::endl;
	isPrime(15, k) ? std::cout << true : std::cout << false; std::cout << std::endl;


	return 0;


}

