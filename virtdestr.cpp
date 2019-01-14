#include <iostream>
class A {
	public:
		virtual ~A(){
			std::cout << "A destroyed" << std::endl;
		}
};

class B : public A {
	public:
		~B(){
			std::cout << "B destroyed" << std::endl;
		}
		
};

int main(){
	A* a = new B();
	delete a;
}
