#include <iostream>

using namespace std;

struct DivisionSolution{
	int quotient;
	int remainder;
};

DivisionSolution recursiveDivide(int, int, int = 0, int = 0);

int main () {
	DivisionSolution a = recursiveDivide(13 , 5);
	DivisionSolution b = recursiveDivide(25 , 25);
	DivisionSolution c = recursiveDivide(425 , 3);

	cout<<a.quotient<<"\t"<<a.remainder<<endl;
	cout<<b.quotient<<"\t"<<b.remainder<<endl;
	cout<<c.quotient<<"\t"<<c.remainder<<endl;
}

DivisionSolution recursiveDivide (int dividend, int divisor, int quotient ,int remainder) {
	DivisionSolution ret  ;
	if (dividend < divisor)return {quotient, dividend}; 
	else return recursiveDivide( dividend - divisor, divisor, quotient + 1);
}
