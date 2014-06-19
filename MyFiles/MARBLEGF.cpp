#include <cstdio>
#include <limits.h>
#define MAX 1000000

using namespace std;

int A[MAX];
long long int segTree[4 * MAX];

struct query {
	char Ch[3];
	int i;
	int j;
} query1;

void intitalize (int node, int min, int max) {
	if(min == max) {
		segTree[node] = A[min];
	} else {
		int mid = (min + max) / 2;
		intitalize (2 * node, min, mid);
		intitalize (2 * node + 1, mid + 1, max);
		segTree[node] = segTree[2 * node] + segTree[2 * node + 1]; 
	}
}

long long int querySum (int node, int min, int max, int i, int j) {
	if(i > max || j < min)
		return 0;
	if(min >= i && max <= j)
		return segTree[node];   
    long long int t1 = querySum(2 * node, min, (min + max) / 2, i, j);
	long long int t2 = querySum(2 * node + 1, (min + max) / 2 + 1, max, i, j);

	return t1 + t2; 
} 

void updateSegtree (int node, int min, int max, int i, int j) {
	if (i < min || i > max) {
	    return;
	}
	if(min == max && min == i) {
		segTree[node] += j;
		return;
	}
	int mid = (min + max) / 2;
    updateSegtree (2 * node, min, mid, i, j);
    updateSegtree (2 * node + 1, mid + 1, max, i, j);
	segTree[node] = segTree[node * 2] + segTree[node * 2 + 1]; 
}

void solveQuery (int size) {
	if(query1.Ch[0] == 'S') 
		printf("%lld\n", querySum (1, 0, size - 1, query1.i, query1.j));
	else if(query1.Ch[0] == 'G') {
		A[query1.i] += query1.j;
		updateSegtree(1, 0, size - 1, query1.i, query1.j);
	}	
	else { 
		A[query1.i] -= query1.j;
		updateSegtree(1, 0, size - 1, query1.i, -query1.j);
	}		 
}

int main () {
	int size, query;
	scanf("%d %d", &size, &query);
	for(int i = 0; i < size; i++) 
		scanf("%d", &A[i]);
	intitalize(1, 0, size - 1);
	for(int a = 0; a < query; a++) {
		scanf("%s %d %d", query1.Ch, &query1.i, &query1.j);
		solveQuery(size);
	}
	return 0;
}