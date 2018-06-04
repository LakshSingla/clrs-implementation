//https://www.hackerearth.com/practice/data-structures/arrays/multi-dimensional/practice-problems/algorithm/saul-goodmans-problem-statement/

//Input#1 - Time Limit exceeded
//Input#2 - Failed
//Input#3 - Passed

#include <iostream>
#include <cmath>

using namespace std;

unsigned long long int abs(unsigned long long int x){ 
	return (x > 0 ? x : -x);
}

struct cell { 
	unsigned long long int r; 
	unsigned long long int c;
}C[100000];

int T;
int N; 

int main(){
	cin>>T;
	while(T--){
		int P  = 0; 
		cin>>N;
		for(int i = 0; i < N; i++) cin>>C[i].r >> C[i].c ;
		for(int i = 0; i < N; i++)	
			for(int j = i + 1; j < N; j++)
				if(abs(C[i].r - C[j].r) == abs(C[i].c - C[j].c)){
					//cout<<C[i].r<<" "<<C[i].c<<"\t"<<C[j].r<<" "<<C[j].c;
					P++;
				}
		cout<<P<<endl;
	}
	return 0;
}
