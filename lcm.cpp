#include <iostream>
#include <initializer_list>

unsigned long long int gcd (int a, int b) {
	if( a == 0)	 return b; 

	return gcd(b % a , a); 
}

unsigned long long int lcm(std::initializer_list<int> T) {
	std::initializer_list<int>::iterator it_b = T.begin();
	std::initializer_list<int>::iterator it_e = T.end();

	unsigned long long int lcm = *it_b;	
	++it_b;

	while(it_b != it_e) {
		
		lcm = (lcm * (*it_b))/gcd(lcm, *it_b);
		
		++it_b;
	}

	return lcm;
}

int main () {
	unsigned int x = lcm({2, 3, 5, 10});
	std::cout << x << std::endl;
}
