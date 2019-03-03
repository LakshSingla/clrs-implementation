#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>


struct node {
	int data;
	node *left, *right, *parent;
};

node* make_node(int data) {
	node *x = (node*)malloc(sizeof(node));
	if(x == nullptr) {
		std::cout << "Insufficient memory"<< std::endl;
		return x;
	}
	x->data = data;
	x->left = nullptr;
	x->right = nullptr;	
	return x;
}

node* insert(int data, node *parent, bool left) {
	node *child = make_node(data);
	if(child == nullptr) {
		return child;
	}
	
	child->parent = parent;
	if(left)
		parent->left = child;
	else 
		parent->right = child;
	
	return child;
}

void dfs_print(node *cur) {
	if(cur == nullptr) return;
	std::cout << cur->data << std::endl;
	dfs_print(cur->left);
	dfs_print(cur->right);
}

std::unordered_map<int, std::vector<int>>& find_inline_distance(node *head, int line, std::unordered_map<int, std::vector<int>>& m) { 
	if(head == nullptr) return m;
	try {
		m.at(line).push_back(head->data);
	}catch(...) {
		std::vector<int> v = {head->data};
		m.insert(std::make_pair(line, std::move(v)));
	}
	find_inline_distance(head->left, line-1, m);
	find_inline_distance(head->right, line+1, m);
	return m;
}

int main() {
	node *x1 = make_node(1);
	node *x2 = insert(2, x1, true);
	node *x3 = insert(3, x1, false);
	node *x4 = insert(4, x2, true);
	node *x5 = insert(5, x2, false);
	node *x6 = insert(6, x3, true);
	node *x7 = insert(7, x3, false);
	node *x8 = insert(8, x6, false);
	node *x9 = insert(9, x7, false);
	//dfs_print(x1);
	std::unordered_map<int, std::vector<int>> x;
	find_inline_distance(x1, 0, x);	
	for(int i = -5; i < 6; ++i) {
		try {
			std::vector<int> &v = x.at(i);
			for(const auto& el: v) std::cout << el << " ";
			std::cout << std::endl;
		}catch(...) {

		}
	}
	return 0;
}
