#include <iostream>
#include <cstdarg>

int _sumx2(int count, ...) {
	int sum = 0;
	va_list vargs;	
	va_list vargs2;	
	va_start(vargs, count);
	va_start(vargs2, count);
	while(count--){
		int x =	va_arg(vargs, int);
		int y =	va_arg(vargs2, int);
		sum += x+y;
	}
	va_end(vargs);
	va_end(vargs2);

	return sum;
}

int main(int argc, char** argv) {
		
	std::cout << "SUM: " << _sumx2(4, 1, 2, 3, 4) << std::endl;
}
