#include <iostream>
#include <algorithm>

class Person{
	public:
	int skill[3];
	friend bool operator ==(const Person& p1, const Person& p2){
		return     p1.skill[0] == p2.skill[0]
			&& p1.skill[1] == p2.skill[1]
			&& p1.skill[2] == p2.skill[2];
	}
};

int main() {
	int T ;
	std::cin >> T; 
	while(T--){
		bool isPossible = true; 
		Person p[3];
		Person *sorted[3]; 
		for(int i = 0; i < 3; i++){
			sorted[i] = &p[i];
			for(int j = 0; j < 3; j++)
				std::cin >> p[i].skill[j];
		}

		for(int i = 0; i < 3; i++)
			for(int j = i+1; j < 3; j++)
				if(sorted[j]->skill[0] < sorted[i]->skill[0])
					std::swap(sorted[i], sorted[j]);
		
		for(int i = 0; i < 3; i++)
			for(int j = i+1; j < 3; j++){
				if(sorted[i]->skill[0] == sorted[j]->skill[0] && sorted[j]->skill[1] < sorted[i]->skill[1])
					std::swap(sorted[i], sorted[j]);
			}
		for(int i = 0; i < 3; i++)
			for(int j = i+1; j < 3; j++)
				if(sorted[i]->skill[1] == sorted[j]->skill[1] && sorted[j]->skill[2] < sorted[i]->skill[2])
					std::swap(sorted[i], sorted[j]);


		/*for(const auto& elem : sorted){
			std::cout << elem->skill[0] << " " << elem->skill[1] << " " <<elem->skill[2] << " " << std::endl;
		}*/

		for(int i = 0; i < i; i++){
			if(sorted[i+1]->skill[0] < sorted[i]->skill[0] ||sorted[i+1]->skill[1] < sorted[i]->skill[1] ||sorted[i+1]->skill[2] < sorted[i]->skill[2] ){
				isPossible = false; 
				break;
			}
			if(!(*(sorted[i+1]) == *(sorted[i]))){
				isPossible = false; 
				break;
			}
		}

		if(isPossible) std::cout << "yes"; 
		else           std::cout << "no";
		std::cout << std::endl;	

	}
}
