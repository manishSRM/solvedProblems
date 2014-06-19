#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <limits.h>

using namespace std;

int A[] = {3, 4, 2, 1, 5, 7, 9, 7, 10, 5, 12, 3, 1, 1, 2, 1, 3, 2};
int segTree[72];
int i, j;

void initialize(int node, int b, int e)
{
    if (b == e) 
        segTree[node] = A[b];   
    else
    {
        //compute the values in the left and right subtrees
        int mid = (b + e) / 2; 
        initialize(2 * node, b, mid);        
        initialize(2 * node + 1, mid + 1, e);
        segTree[node] = min (segTree[node * 2], segTree[node * 2 + 1]);
        //printf("node index = %d, value =  %d\n", node, segTree[node]);

    }
} //call "initialize (1, 0, n-1);" to setup the tree

int query(int node, int b, int e)
{
    //if the current interval doesn't intersect 
    //the query interval return -1
    if (i > e || j < b)
    return INT_MAX;
    
    //if the current interval is included in 
    //the query interval return M[node]
    if (b >= i && e <= j) {
        //printf("%d %d\n", segTree[node], node);
        return segTree[node];
    }
    
    //compute the minimum position in the 
    //left and right part of the interval
    int p1 = query(2 * node, b, (b + e) / 2);
    int p2 = query(2 * node + 1, (b + e) / 2 + 1, e);
    //return the position where the overall 
    //minimum is
    return min (p1, p2);
}

int main() {
    initialize(1, 0, 17);
    i = 1, j = 17;
    int ans = query (1, 0, 17);
    printf("%d\n", ans);		 
	return 0;
}


// node index = 8, value =  8
// node index = 4, value =  8
// node index = 5, value =  19
// node index = 2, value =  19
// node index = 12, value =  11
// node index = 6, value =  11
// node index = 7, value =  15
// node index = 3, value =  15
// node index = 1, value =  19

// node index = 8, value =  7
// node index = 4, value =  5
// node index = 5, value =  1
// node index = 2, value =  1
// node index = 12, value =  2
// node index = 6, value =  2
// node index = 7, value =  3
// node index = 3, value =  2
// node index = 1, value =  1

// node index = 16, value =  7
// node index = 17, value =  8
// node index = 9, value =  5
// node index = 10, value =  1
// node index = 11, value =  19
// node index = 24, value =  11
// node index = 25, value =  2
// node index = 13, value =  6
// node index = 14, value =  3
// node index = 15, value =  15

