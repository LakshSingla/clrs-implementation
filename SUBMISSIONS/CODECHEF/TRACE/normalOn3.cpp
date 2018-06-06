#include <iostream>

int mat[100][100];

int main(){
	int maxSum; 
	int T; 
	std::cin >> T; 
	while(T--){
		int N; 	
		std::cin>>N;
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				std::cin >> mat[i][j];

		maxSum = mat[0][0];

		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				int sum = 0; 				
				if(i > j){
					//i is bigger	
					for(int k = i, l = 0; k < N; k++, l++) sum += mat[k][j+l];
				}
				else if(j > i){
					//j is bigger	
					for(int k = 0, l = j; l < N; k++, l++) sum += mat[i+k][l];
				}
				
				else sum = mat[i][j];

				if(maxSum < sum) maxSum = sum;
			}
		}

		std::cout<<maxSum<<std::endl;
	}
}
