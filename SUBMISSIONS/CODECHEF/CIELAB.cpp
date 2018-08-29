#include <iostream>

int main () {
	int a, b;
	std::cin >> a >> b; 
	int correct_ans = a - b;
	if(correct_ans % 10 == 9) --correct_ans;
	else ++correct_ans;
	std::cout << correct_ans;
}
