#include <iostream>
#include <iomanip>

using namespace std;

void hanoi(int n);
void hanoiRec(int[], int[], int[]);

int main(){
	return 0;
}

void hanoi(int n){ 
 	int a[n] = {} , b[n] = {} , c[n] = {} ;
	for(int i = 0; i < n; i++) a[i] = i + 1;
	
}

void hanoiRec(int src[], int aux[], int dest[]) {
	
}
