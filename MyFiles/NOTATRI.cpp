#include <cstdio>
#include <algorithm>
#define MAX 2000

using namespace std;

#define gc() getchar_unlocked()

int isSpaceChar(char c) {
            return c == ' ' || c == '\n' || c == '\r' ;
}
inline int FAST_IO()
{
    char ch;
    int val=0;
    ch=gc();
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

long long int sticksLength[MAX];

int binary_Search (int j, int l, int key) {
	if (l <= 0)
        return -1;
    if (sticksLength[j] > key)
        return 0;
    if (sticksLength[l - 1] <= key)
        return -1;
    int beg = j + 1, last = l - 1;
    while (beg <= last) {
        int mid = (beg + last) / 2;
        if (sticksLength[mid - 1] <= key && sticksLength[mid] > key)
            return mid;
        else if (sticksLength[mid] <= key)
            beg = mid + 1;
        else
            last = mid - 1;
    }
    return -1;
}

int countWins (long long int sticks[], int size) {
	int count = 0;
	for (int i = 0; i < size; i++) {
	    for (int j = i + 1; j < size; j++) {
	        int index = binary_Search (j, size, sticksLength[i] + sticksLength[j]);
	        if (index != -1) 
	        	count += size - index;
	    } 
	}
	return count;
}

int main () 
{
	while (1) {
		int N; 
		scanf ("%d", &N);
		if (N == 0)
			return 0;
		for (int i = 0; i < N; i++) {
			sticksLength[i] = FAST_IO();
		}
		sort (sticksLength, sticksLength + N);
		printf("%d\n", countWins (sticksLength, N));
	}
	return 0;
}