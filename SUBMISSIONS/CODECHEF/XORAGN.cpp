#include <iostream>

unsigned int mat[100000]; 

int main(){
	int T ;
	std::cin >> T ; 
	while(T--){
		int N ;
		std::cin>>N;
		for(int i =0 ; i < N; i++) std::cin >> mat[i];
		
		unsigned int XOR = 2 * mat[0];
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(i == 0 && j == 0) continue; 
				const int b = mat[i] + mat[j];
				XOR ^= b; 
			}
		}
		std::cout<<XOR<<std::endl;
	}
}
