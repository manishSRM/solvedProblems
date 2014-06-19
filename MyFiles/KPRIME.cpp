#include <cstdio>
#include <vector>
#define MAX 100000

using namespace std;

vector<int> V[6];

int binary_Search (const vector <int> &v, int num) {
	int beg = 0, end = v.size () - 1;
	while (beg <= end) {
		int mid = (beg + end) / 2;
		if (v[mid] <= num && num <= v[mid + 1])
			return mid;
		if (v[mid] > num)
			end = mid - 1;
		else
			beg = mid + 1;
	}	
}

int count_K_Primes (int A, int B, int K) {
	int index_A = binary_Search (V[K], A);
	int index_B = binary_Search (V[K], B);
	return (index_B - index_A + 1);
}

int countDistinctPrime (int num) {
	int count = 0;
	for (int i = 2; i <= num / i; i++) {
		if (num % i == 0) {
			count++;
			do {
			    num /= i;
			} while (num % i == 0);
		}
	}
	if (num > 1) {
	    count++;
	}
	return count;
}

int main () 
{
	int T;
	scanf ("%d", &T);
	for (int i = 2; i <= MAX; i++) {
		int count = countDistinctPrime (i);
		if (count >= 1 && count <= 5) 
			V[count].push_back (i);
	}
	for (int i = 0; i < T; i++) {
		int A, B, K;
		scanf ("%d %d %d", &A, &B, &K);
		printf ("%d\n", count_K_Primes (A, B, K));
	}
	return 0;
}