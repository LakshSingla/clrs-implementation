#include <iostream>
#include <algorithm>

struct Person {
	int s1; 
	int s2; 
	int s3; 
};

enum class SKILL{
	LT, EQ, GT
};

int main(){
	int T ;
		std::cin >> T; 
		while(T--) {
			Person *sorted[3];
			Person p[3];		
			SKILL s[2]{SKILL::EQ, SKILL::EQ};
			for(int i = 0; i < 3; i++){
				std::cin >> p[i].s1 >> p[i].s2 >> p[i].s3; 
				sorted[i] = p+i;
			}
			for(int i = 0; i < 2; i++){
				for(int j = i+1; j < 3; j++){
					if(sorted[j]->s1 < sorted[i]->s1)
						std::swap(sorted[i], sorted[j]);
				}

			}

			if(sorted[1]->s1 > sorted[0]->s1) s[0] = SKILL::GT;
			if(sorted[2]->s1 > sorted[1]->s1) s[1] = SKILL::GT;

			for(int i = 0; i < 2; i++){
				//if(s[i] == SKILL::LT ) break; 
				if(sorted[i+1]->s2 < sorted[i]->s2){
					s[i] = SKILL::LT; 
					break;
				}
				else if(sorted[i+1]->s2 == sorted[i]->s2 && s[i] == SKILL::GT)
					continue;
				
				else if(sorted[i+1]->s2 > sorted[i]->s2) 
					s[i] = SKILL::GT; 

			}

			for(int i = 0; i < 2; i++){
				if(s[i] == SKILL::LT) break; 
					
				else if(sorted[i+1]->s3 < sorted[i]->s3){
					s[i] = SKILL::LT; 
					break;
				}

				else if(sorted[i+1]->s3 == sorted[i]->s2 && s[i] == SKILL::GT) continue ;

				else if(sorted[i+1]->s3 > sorted[i]->s3) 
					s[i] = SKILL::GT; 

			}

			if(s[0] != SKILL::LT && s[1] != SKILL::LT && (s[0] == SKILL::GT || s[1] == SKILL::GT))
				std::cout << "yes" << std::endl;

			else 
				std::cout << "no"  << std::endl;

			/*for(int i = 0; i < 3; i++){ 
				std::cout << sorted[i]->s1 << " " <<  sorted[i]->s2 << " " << sorted[i]->s3 ;
				std::cout << std::endl;
			}*/

	}

}
