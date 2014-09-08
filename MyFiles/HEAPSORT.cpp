#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>

#define FOR(A,B,C) for(int A = B; A < C; A++)
#define EFOR(A,B,C) for(int A = B; A <= C; A++)
#define RFOR(A,B,C) for(int A = B; A >= C; A--)
#define PB(A,B) A.push_back(B);
#define VI vector<int>
#define VL vector<long>

using namespace std;

void Max_Heapify (VI &A, int pos, int heap_size) {
    int larger = pos, l_value = A[pos];
    while (1) {
        int left = (pos + 1) << 1 - 1;
        int right = (pos + 1) << 1;
        if (left <= (heap_size - 1) && A[left] > l_value)
            larger = left;
        if (right <= (heap_size - 1) && A[right] > A[larger])
            larger = right;
        if (larger != pos) {
            A[pos] = A[larger];
            pos = larger;
        }   
        else
            break;
    }
    A[pos] = l_value;
    return;
}

void Build_Max_Heap (VI &A) {
    RFOR (pos, A.size () / 2 - 1, 0) 
        Max_Heapify (A, pos, A.size ());
    return;
}

void heap_sort (VI &A) {
    int size_A = A.size ();
    Build_Max_Heap (A);
    RFOR (pos, A.size () - 1, 1) {
        swap (A[0], A[pos]);
        --size_A;
        Max_Heapify (A, 0, size_A);
    }
    return;
}

int main ()
{
    int N;
    scanf ("%d", &N);
    VI A(N);
    FOR(i, 0, N)
        scanf ("%d", &A[i]);
    cout << "SORTED ORDER WILL BE : ";
    heap_sort (A);
    FOR(j, 0, N)
        printf("%d ", A[j]);
    printf("\n");    
    return 0;
}