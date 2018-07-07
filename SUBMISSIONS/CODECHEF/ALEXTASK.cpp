#include <iostream>

int gcd (int a, int b) {
	return !b ? a : gcd(b, a % b);
}

unsigned long long lcm(const int arr[], int n) {
	unsigned long long ans = arr[0];	

	for(int i = 1; i < n; i++) 
		ans = ((arr[i] * ans) / (gcd(arr[i], ans)));

	return ans;
}

int main () {
	int T; 
	std::cin >> T; 
	while (T--) {
	}
}
