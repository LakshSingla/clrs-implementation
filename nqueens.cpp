#include <iostream>
#include <cmath>

bool mat[100][100]{0};

bool isAttacked(bool (*mat)[100], int N, int x, int y){
	//Check if anyone in the same row
	for(int i = 0; i < N; i++){
		if(i == y) continue; 
		else if (mat[x][i]) return true; 
	}
	//Check if anyone in the same column 
	for(int i = 0; i < N; i++){
		if(i == x) continue; 
		else if (mat[i][y]) return true; 
	}
	//Check in the  diagonals	

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(i == x  && j == x) continue; 
			if(( std::abs(x - i) == std::abs(y - j) || x + y == i + j) && mat[x][y]) return true;
		}
	}
	
	return false;
}

bool nQueens(bool (*mat)[100], int N, int unplaced){
	if(unplaced == 0) return true;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(!isAttacked(mat, N, i, j)) {
				mat[i][j] = true; 
				if(nQueens(mat, N, unplaced-1)) return true;
				mat[i][j] = false;
			}
		}
	}

	return false;
}

int main(){
	int N, queens ;
	std::cout<<"Enter the value of N: (1 - 100): ";
	std::cin>>N; 
	std::cout<<"Enter the number of unplaced queens: (1 - N): ";
	std::cin>>queens; 
	if(nQueens(mat, N, queens)){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++) std::cout<<mat[i][j]<<" ";
			std::cout<<std::endl;
		}
	}
	else std::cout<<"Could not find the solution"<<std::endl;
	return 0;
}
