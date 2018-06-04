//https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/fight-for-laddus/

#include <iostream>

using namespace std;

int main(){
	int T; 
	cin>>T;
	while(T--){
		int N;
		cin>>N;
		long long int A[N], B[100000] = {0};
		for(int i = 0; i < N; i++){
			cin >> A[i];	
			B[A[i]]++;
		}
		for(int i = 0; i < N ; i++){
			long long int elem = -1;	
			int j;
			for(int j = i+1; j < N; j++){
				if(B[A[j]] > B[A[i]]){
					elem = 	A[j];
					break;
				}
			}
			cout<<elem<<" ";
		}
		cout<<endl;
	}
	return 0;
}
