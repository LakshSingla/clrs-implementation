#include <iostream>

int power (int, int );

int main () {
	std::cout<<power(2, 10);
	std::cout<<std::endl;
	std::cout<<power(3, 5);
	return 0;
}


int power (int base , int exponent) {
	if ( exponent == 0) return 1;
	int halfPowered = power ( base, exponent / 2);
	if ( exponent % 2 ==0 ) return halfPowered * halfPowered;
	else return base * halfPowered * halfPowered;
}
