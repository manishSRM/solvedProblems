#include <cstdio>

using namespace std;

int A[101];

void input_Array(int n) {
	for (int i = 1; i <= n; i++) 
		scanf("%d", &A[i]);		
}


int numnber_Of_Sweets(int N, int X) {
	int sum = 0, K, rem, flag = 0;
	for(int i = 1; i <= N; i++)
		sum += A[i];
	K = sum / X;
	rem = sum % X;
	if(rem == 0)
		return K;
	for(int j = 1; j <= N; j++) {	
		if(rem >= A[j])
			return -1;	
	}
	return K;
}

void test_Cases(int t) {
	int N, X, r;
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &N, &X);
		
		input_Array(N);
		r = numnber_Of_Sweets(N, X);
		printf ("%d\n", r);		
	}
}

int main() {
	int T;
	scanf ("%d", &T);
	test_Cases(T);
	return 0;
}
