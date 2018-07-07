#include <iostream>

int main () {
	int T;
	std::cin >> T;
	while (T--) {
		int consecutive_days = 0;	
		int days_in_april = 30;
		bool worked; 
		bool overworked = false;
		while (days_in_april--){
			std::cin >> worked;
			consecutive_days = worked ? ++consecutive_days : 0;
			if(consecutive_days > 5) overworked = true;
		}
		if(overworked) std::cout << "#coderlifematters" ;
		else           std::cout << "#allcodersarefun" ;

		std::cout << std::endl;
	}
}
