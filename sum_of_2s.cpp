#include <iostream>

bool sum_of_2s(int x){
	if( x == 0) return true; 

	if( x <= 1) return false; 

	else {
		if(sum_of_2s(x-3)){
			std::cout << "Add 3 to " << x - 3 << std::endl;
			return true; 
		} 
		else if(sum_of_2s(x-2)){
			std::cout << "Add 2 to " << x - 2 << std::endl;
			return true; 
		}
	}
	return false; 
}

int main() {
	int x; 
	std::cin >> x; 
	if(!sum_of_2s(x)) std::cout << "No corresponding match found. " << std::endl;
}


