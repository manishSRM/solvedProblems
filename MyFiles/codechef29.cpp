#include <cstdio>
#include <algorithm>
#include <limits.h>
#include <iostream>

#define MAX 100000

using namespace std;

int matchsticksBuringTime[MAX];
int segTree1[4 * MAX];
int segTree2[4 * MAX];
int N;

void input_BurningTime (int l) {
	for (int i = 0; i < l; i++) 
		scanf("%d", &matchsticksBuringTime[i]);
}

void initialize(int node, int b, int e)
{
    if (b == e) 
        segTree1[node] = matchsticksBuringTime[b];   
    else
    {
        int mid = (b + e) / 2; 
        initialize(2 * node, b, mid);        
        initialize(2 * node + 1, mid + 1, e);
        segTree1[node] = min (segTree1[node * 2], segTree1[node * 2 + 1]);
    }
} 

void initialize1(int node, int b, int e)
{
    if (b == e) 
        segTree2[node] = matchsticksBuringTime[b];   
    else
    {
        int mid = (b + e) / 2; 
        initialize1(2 * node, b, mid);        
        initialize1(2 * node + 1, mid + 1, e);
        segTree2[node] = max (segTree2[node * 2], segTree2[node * 2 + 1]);
    }
} 

int queryMin(int node, int b, int e, int i, int j)
{   
    if (i > e || j < b)
        return INT_MAX;
   
    if (b >= i && e <= j) 
        return segTree1[node];

    int p1 = queryMin(2 * node, b, (b + e) / 2, i, j);
    int p2 = queryMin(2 * node + 1, (b + e) / 2 + 1, e, i, j);
   
    //printf("%d %d\n", p1, p2);
    return min (p1, p2);
}

int queryMax(int node, int b, int e, int i, int j)
{   
    if (i > e || j < b)
        return INT_MIN;
   
    if (b >= i && e <= j)
        return segTree2[node];
   
    int p1 = queryMax(2 * node, b, (b + e) / 2, i, j);
    int p2 = queryMax(2 * node + 1, (b + e) / 2 + 1, e, i, j);
   
    return max (p1, p2);
}

void quries (int Q) {
	int L, R, max1, min1, max2, i, j, m, n;;
	double ans;
	for (int k = 0; k < Q; k++) {
		scanf("%d %d", &L, &R);
		min1 = queryMin(1, 0, N - 1, L, R);
		max1 = queryMax(1, 0, N - 1, L, R);
		max2 = max (queryMax(1, 0, N - 1, 0, L - 1), queryMax(1, 0, N-1, R + 1, N - 1));

		double ans1 = max2;
		double ans2 = (max1 - min1) / 2.0;
		ans = min1 + max (ans1, ans2);
		printf("%0.1f\n", ans);
	}
}

int main() {
	int Q;
	scanf("%d", &N);
    input_BurningTime(N);
    initialize(1, 0, N - 1);
    initialize1(1, 0, N - 1);    
	scanf("%d", &Q);
	quries(Q);
	return 0;
}