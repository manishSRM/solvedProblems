#include <cstdio>
#include <vector>

using namespace std;

int checkPalindrome(const vector<int> &A, const vector<int> &B) {
	int size = A.size();
	for(int i = 0; i < size; i++) {
		if(A[i] != B[i])
			return -1;
	} 
	return 1;
}

int main() {
	int T;
	long long int N;
	scanf("%d", &T);
	vector<int> A;
	while(T--) {
		scanf("%lld", &N);
		while(N) {
			A.push_back(N % 2);
			N /= 2; 
			//printf("%lld\n", N);
		}
		vector<int> B;
		for(int i = A.size() - 1; i >= 0; i--)
			B.push_back(A[i]);
		printf("%d\n", checkPalindrome(A, B));
		A.clear();
		B.clear();	
	}
	return 0;
} 