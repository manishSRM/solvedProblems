#include <cstdio>
#include <vector>
#include <algorithm>

#define gc() getchar_unlocked()
#define FOR(i, j, k) for (int i = j; i < k; i++)
#define EFOR(i, j, k) for (int i = j; j <= k; i++)
#define RFOR(i, j, k) for (int i = j; i >= k; i--)
#define PB (A, B) A.push_back(B);
#define VI vector<int>

using namespace std;

int isSpaceChar(char c) {
    return c == ' ' || c == '\n' || c == '\r' ;
}

inline int FAST_IO()
{
    char ch;
    int val=0;
    ch = gc();
    while(isSpaceChar(ch))
            ch=gc();
    val=0;
    while(!isSpaceChar(ch))
    {
        val=(val*10)+(ch-'0');
        ch=gc();
    }
    return val;
}

int convertInBinary (int A[], long long int num) {
	int count = 0;
	while (num) {
		A[count++] = (int)num % 2;
		num /= 2;
	}
	return count;
}

void reverseArray (int array[], int size) {
	int temp = size - 1;
	for (int c = 0; c < size / 2; c++) 
		swap (array[c], array[temp--]);
}

int countCommonTerms (int A[], int B[], int n1, int n2) {
	if (n1 > n2)
		swap (n1, n2);
	int count = 0;
	FOR(i, 0, n1) {
		if (A[i] == B[i])
			count++;
		else
		    break;
	}
	return count;
}

int shortestPath (int I[], int J[], int i, int j) {
	int n1 = convertInBinary (I, i);
	int n2 = convertInBinary (J, j);
	reverseArray (I, n1);
	reverseArray (J, n2);
	int K = countCommonTerms (I, J, n1, n2);
	return ((n1 + n2) - 2 * K);
}

int main () 
{
	int T;
	T = FAST_IO ();
	while (T--) {
		int i = FAST_IO ();
		int j = FAST_IO ();
		int I[40], J[40];
		printf("%d\n", shortestPath (I, J, i, j));
	}
	return 0;
}