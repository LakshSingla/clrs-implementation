//https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/the-football-fest-6/

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
	//else cout<<"No Food"<<endl;
}

int main(){
	int T; 
	cin >> T;
	while(T--){
		Stack s; 
		unsigned long int cur, prev;
		unsigned long int N, pno; 
		char type;
		cin >> N; 
		cin >> pno;
		cur = pno;
		while(N--){
			cin >> type; 
			switch(type){
				case 'P': 
					cin>>pno;
					prev = cur; 
					cur = pno;
					break;
				case 'B': 
					unsigned long int temp = cur; 
					cur = prev; 
					prev = temp;
					break;
			}
		}
		cout<<"Player "<<cur<<endl;
	}
}
