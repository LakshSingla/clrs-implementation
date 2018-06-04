//https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/tutorial/

#include <iostream>

using namespace std;

class Stack{
	private:
		const int maxHeight;
		unsigned long long int C[100000];
		unsigned int top;
	public:
		Stack():top(0), maxHeight(100000){}
		bool overflow();
		bool underflow();
		void push(unsigned long long int);
		void pop();
};

bool Stack::overflow(){ return top == maxHeight;} 
bool Stack::underflow(){ return top == 0;} 
void Stack::push(unsigned long long int x){
	if(!overflow()) C[top++] = x;
}
void Stack::pop(){
	if(!underflow()) cout<< C[--top]<<endl;
	else cout<<"No Food"<<endl;
}

int main(){
	Stack s; 
	unsigned long int Q{0};
	cin>>Q; 
	int x, y;
	while(Q--){
		cin>>x;
		switch(x){
			case 1: 
				s.pop();
				break;
			case 2: 
				cin>>y;
				s.push(y);
				break;
		}
	}
	return 0;
}
