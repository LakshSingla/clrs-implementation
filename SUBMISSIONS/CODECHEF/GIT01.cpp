#include <iostream>

char cake[100][100];

int main(){
	int T; 
	std::cin >> T;
	while(T--){
		int N , M; 
		std::cin >> N >> M; 
		for(int i = 0; i < N; i++) 
			for (int j = 0; j < M; j++)
				std::cin >> cake[i][j];

		int costR{0}, costG{0};

		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				if(((i+j) % 2) == 0){
					switch(cake[i][j]){
						case 'R' :
							costG += 5;
							break;
						case 'G':
							costR += 3;	
							break;
					}
				}
				else {
					switch(cake[i][j]){
						case 'R' :
							costR += 5;
							break;
						case 'G':
							costG += 3;	
							break;
					}
				
				}
			}
		}

		std::cout << (costR > costG ? costG : costR)<<std::endl;
	}
}
