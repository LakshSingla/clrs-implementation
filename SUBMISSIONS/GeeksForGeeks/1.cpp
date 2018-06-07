//https://www.geeksforgeeks.org/count-numbers-that-dont-contain-3/
#include <iostream>
#include <cmath>

int count(int n){
	if( n < 3 ) return n ;
	else if ( n >= 3 && n <=9 ) return n - 1;

	int dig = 0;	
	int nDup = n;
	while(nDup){
		dig++;	
		nDup /= 10; 
	}
	const int placeValue = static_cast<int>(std::pow(10, dig - 1));
	return count(n / placeValue) * count(n % placeValue);
}

int main(){
	int n; 
	std::cin >> n;
	std::cout<<count(n)<<std::endl;

}
