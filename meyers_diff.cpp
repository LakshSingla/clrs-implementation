#include <iostream>
#include <vector>
#include <utility>
#include <set>
//#include <unordered_set>

struct hash_intpair {
	public:
		inline std::size_t operator()(const std::pair<int, int>& el) {
			const std::hash<int> hash_int;
			return hash_int(el.first) + 31*hash_int(el.second);
		}

};

template <typename T1, typename T2>
void pprint_pair(const std::pair<T1, T2> p){ 
	std::cout << p.first << ", " << p.second;
	std::cout << std::endl;
}

int main (int argc, char *argv[]) {
	if(argc != 3) {
		std::cout << "Usage: diff string1 string2" << std::endl;
		return -1;	
	}
	//pprint_pair(std::make_pair(1, 2));
	//hash_intpair a;
	//std::cout << a(std::make_pair(1, 2)) << std::endl;
	
	std::string s1 = argv[1];
	std::string s2 = argv[2];

	std::vector<std::vector<bool>> grid;

	//Dimension is 1 more than sizeof(s2)+1 * sizeof(s2)+1 
	//in order to prevent out_of_range errors when accesing 
	//if it has hit either wall
	for(const auto& c : s2) {
		std::vector<bool> row(s1.length(), false);	
		for(int i = 0; i < s1.length(); ++i){
			if(s1[i] == c)
				row[i] = true;	
		}
		row.push_back(false);
		grid.push_back(row);
	}
	grid.push_back(std::vector<bool>(s1.length()+1, false));

	for(const auto& row : grid) {
		for(const auto& elem : row) {
			std::cout << elem << " " ;
		}
		std::cout << std::endl;
	}
	
	using coordinate = std::pair<int, int>;
	
	std::set<std::pair<int, int>> frontier;
	frontier.insert(std::make_pair(0, 0));

	int moves = 0;
	bool found = false;
	
 	while(true) {
		std::set<std::pair<int, int> > new_frontier;
		std::cout << moves << std::endl;
		bool moves_inc = false;
		for(const auto last_node : frontier) {
			pprint_pair(last_node);
			int x = last_node.first;
			int y = last_node.second;

			while(grid[x][y])  
				++x, ++y;

			if(x==s2.length() && y==s1.length()){
				found = true;
				break;
			}

			if(!moves_inc) ++moves, moves_inc = true;

			if( x < s2.length()) {
				int i = x;
				int j = y;
				++i, j;
				while(grid[i][j])  
					++i, ++j;
				coordinate next_coord{i, j};
				pprint_pair(next_coord);
				new_frontier.insert(next_coord);
			}
			if( y < s1.length()){
				int i = x;
				int j = y;
				i, ++j;
				while(grid[i][j])  
					++i, ++j;
				coordinate next_coord{i, j};
				pprint_pair(next_coord);
				new_frontier.insert(next_coord);
			}
		}
		frontier = std::move(new_frontier);
		if(found) break;
	}

	std::cout << moves << std::endl;
}
