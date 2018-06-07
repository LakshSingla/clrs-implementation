//https://www.hackerearth.com/practice/basic-programming/recursion/recursion-and-backtracking/practice-problems/algorithm/a-tryst-with-chess/

//Valid for all test cases

#include <iostream>

bool board[10][10]{0};

bool isValidLocation(int x, int y) {
	return x>=0 && x<10 && y>=0 && y<10;
}

int noOfMoves(int x, int y, int movesLeft){
	int total = 0; 

	if(movesLeft == 0 && !board[x][y]){ 
		board[x][y] = true;
		return 1;
	}

	if(movesLeft == 0 && board[x][y]){
		return 0;	
	}

	if(isValidLocation(x-1, y-2)){
		total += noOfMoves(x-1, y-2, movesLeft - 1);
	}
	if(isValidLocation(x+1, y-2)){
		total += noOfMoves(x+1, y-2, movesLeft - 1);
	}
	if(isValidLocation(x-2, y-1)){
		total += noOfMoves(x-2, y-1, movesLeft - 1);
	}
	if(isValidLocation(x+2, y-1)){
		total += noOfMoves(x+2, y-1, movesLeft - 1);
	}
	if(isValidLocation(x-2, y+1)){
		total += noOfMoves(x-2, y+1, movesLeft - 1);
	}
	if(isValidLocation(x+2, y+1)){
		total += noOfMoves(x+2, y+1, movesLeft - 1);
	}
	if(isValidLocation(x-1, y+2)){
		total += noOfMoves(x-1, y+2, movesLeft - 1);
	}
	if(isValidLocation(x+1, y+2)){
		total += noOfMoves(x+1, y+2, movesLeft - 1);
	}
	return total;
}

int main(){
	int x, y, N; 
	std::cin >> x >> y >> N; 
	std::cout<<noOfMoves(x, y, N);
	return 0;
}
