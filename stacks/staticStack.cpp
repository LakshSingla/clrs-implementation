#include <iostream>

using namespace std;

const int STACK_SIZE = 20;

int stack[STACK_SIZE] = { 0 };

int head = 0;
int items = 0;

void printStack( int[] , const int,const  int);
void push ( int[], const int,  int&, const int);
void pop ( int[], const int, int&);

int main () {	
	int inp ;
	int val;
	do {
		cout<<"1. Print the stack"<<endl;
		cout<<"2. Push onto the stack"<<endl;
		cout<<"3. Pop off the stack"<<endl;
		cout<<"4. Exit "<<endl;
		cout<<"Enter the choice: ";
		cin>>inp;
		switch(inp){
			case 1:
				printStack(stack, head, items);
				break;
			case 2:
				cout<<"Enter the value: ";
				cin>>val;
				push(stack, head, items, val);
				break;
			case 3: 
				pop(stack, head, items);
				break;
			default:
				return -1;
		}

	}while(inp != 4);
}

void printStack (int stack[] , const int head, const int items) {
	for (int i = head ; i < items; i++) cout<<stack[ i % STACK_SIZE]<<"\t";
	cout<<endl;
	return;
}

void push (int stack[] , const int head , int &items, const int data )  {
	if (items == 20) return ;
	stack[(head + items++) % STACK_SIZE] = data;
	return;
}

void pop (int stack[], const int head, int &items) {
	if (items == 0 ) return;
	items--;
}
