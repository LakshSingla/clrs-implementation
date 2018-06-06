#include <iostream>

int maxTrace(int* , int);

int maxTrace(int *mat, int N){
	if(N)
	int maxTL = maxTrace(mat        , N-1);
	int maxTR = maxTrace(mat + 1    , N-1);
	int maxBL = maxTrace(mat + N    , N-1);
	int maxBR = maxTrace(mat + N + 1, N-1);
}
