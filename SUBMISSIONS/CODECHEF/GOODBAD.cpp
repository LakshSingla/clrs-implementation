#include <iostream>
#include <string>
#include <cctype>

int main () {
	int T; 
	std::cin >> T ;
	while (T--) {
		int n, k; 
		std::string message; 
		std::cin >> n >> k ;
		std::cin >> message; 

		int ct_upper_case = 0, 
			ct_lower_case = 0;


		for (const auto& c: message) {
			if(std::isupper(c)) ++ct_upper_case;
			else ++ct_lower_case;
		}

		bool by_chef    = false, 
			 by_brother = false;

		if(ct_upper_case >= n-k) by_brother = true;
		if(ct_lower_case >= n-k) by_chef    = true;

		if(by_brother && by_chef) std::cout << "both"; 
		else if(by_brother && !by_chef) std::cout << "brother";
		else if(!by_brother && by_chef) std::cout << "chef";
		else std::cout << "none";

		std::cout << std::endl;
	}
}
