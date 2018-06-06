#include <iostream>
#include <algorithm>
#include <utility>


int main(){
	int T; 
	std::cin >> T; 
	while(T--){
		int N; 
		std::string verdict = "Dynamic";
		std::string s; 
		std::cin >> s;
		int arr[26]{0};
		for(int i = 0; i < s.length(); i++){
			arr[s[i]-'a']++;
		}
		std::sort(arr, arr + 26);
		//for(const auto &elem : arr) std::cout<<elem<<"\t";
		//std::cout<<std::endl;
		int startPoint;
		for(startPoint = 0; startPoint < 26; startPoint++){
			if(arr[startPoint]) break;
		}

		if(startPoint == 24 || startPoint == 25){
			std::cout<<"Dynamic"<<std::endl;
			continue;
		}
		
		bool cond1 = true;
		for(int i = startPoint; i < 24; i++){
			if(arr[i] + arr[i+1] != arr[i + 2]){
				cond1 = false;
				break;
			}
		}
		if(!cond1){
			std::swap(arr[startPoint], arr[startPoint + 1]);	

			for(int i = startPoint; i < 24; i++){
				if(arr[i] + arr[i+1] != arr[i + 2]){
					verdict = "Not";
					break;
				}
			}
		}

		std::cout<<verdict<<std::endl;
		//if(T) std::cout<<std::endl;
	}
}
