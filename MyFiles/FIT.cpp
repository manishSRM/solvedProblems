#include <cstdio>
#include <limits.h>
#include <algorithm>
#include <vector>
#define MAX 100000
#define gc() getchar_unlocked()

using namespace std;

int goals[MAX];

void maxDifference (int length) {
    int maxDif = 0, currentMin = goals[0];
    for (int i = 1; i < length; i++) {
        if (currentMin > goals[i])
            currentMin = goals[i];
        else {
            int temp = goals[i] - currentMin;
            if (temp > maxDif)
                maxDif = temp;
        }
    }
    if (maxDif <= 0)
        printf("UNFIT\n");
    else
        printf("%d\n", maxDif);     
}

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

int main () 
{
    int T;
    scanf ("%d", &T);
    while (T--) {
        int size;
        scanf ("%d", &size);
        for (int j = 0; j < size; j++) 
            goals[j] = FAST_IO ();       
        maxDifference (size);
    }
    return 0;
}