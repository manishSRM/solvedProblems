#include <cstdio>

using namespace std;

int binary_search (int A[], int l, int key) {
    if (l <= 0)
        return -1;
    if (A[0] > key)
        return 0;
    if (A[l-1] <= key)
        return -1;
    int beg = 1, last = l - 1;
    while (beg <= last) {
        int mid = (beg + last) / 2;
        if (A[mid - 1] <= key && A[mid] > key)
            return mid;
        else if (A[mid] <= key)
            beg = mid + 1;
        else
            last = mid - 1;
    }
    return -1;
}

int main ()
{
    int A[] = {1, 2, 3};
    int key = 1;
    printf("%d\n", binary_search (A, 3, key));
    return 0;
}