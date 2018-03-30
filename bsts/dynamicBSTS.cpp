#include <iostream>

using namespace std;

struct node {
	int data;
	node *right;
	node *left;
	node *parent;
}; 

node tree = { 0, nullptr, nullptr, nullptr};

void traverse (node*);
void insert (node*, int);

int main () {

}

void traverse ( node *tree ) {

	if ( tree == nullptr) return;

	traverse(tree->left);
	cout<<(tree->data)<<"\t";
	traverse(tree->right);
	cout<<endl;
	return;
}

void insert ( node *tree , int data ) {}
