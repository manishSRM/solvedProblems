#include <cstdio>
#include <algorithm>
#define EFOR(A, B, C) for(int A = B; A <= C; A++)

using namespace std;

void swap(char *A, char *B) {
	char temp = *A;
	*A = *B;
	*B = temp;
}

void printAllPermutaion(char str[], int i, int N) {
	int j;
	if(i == N) {
		printf("%s\n", str);
	} else {
		EFOR(j, i, N) {
			swap((str + i), (str + j));                //O(N*N!)
			printAllPermutaion(str, i + 1, N);
			swap((str + i), (str + j));              //backtarcking
		}
	}
}

int main() {
	char str[] = "ABC";
	printAllPermutaion(str, 0, 2);
	return 0;
} 