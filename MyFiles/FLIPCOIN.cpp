#include <cstdio>
#define MAX 100000

using namespace std;

struct flipCoins {
	int count;
	int flag;
}  segTree[4 * MAX];

void addStructure (flipCoins &sum, const flipCoins &v1, const flipCoins &v2) {
	sum.count = v1.count + v2.count;
}

void passFlag (int node, int min, int max) {
    if (segTree[node].flag) {
        segTree[node].flag = 0;
        segTree[node].count = (max - min + 1) - segTree[node].count;
        if (min != max) { //childs only exist when not a leaf node
            segTree[node * 2].flag = 1 - segTree[node * 2].flag;
            segTree[node * 2 + 1].flag = 1 - segTree[node * 2 + 1].flag;
        }
    }
}

void initalizeSegTree (int node, int min, int max) {
	segTree[node].flag = 0;
	if (min == max) {
		segTree[node].count = 0;
	} else {
		int mid = (min + max) / 2;
		initalizeSegTree (2 * node, min, mid);
		initalizeSegTree (2 * node + 1, mid + 1, max);
		addStructure (segTree[node], segTree[2 * node], segTree[2 * node + 1]);
	}
}

int countHeads (int node, int min, int max, int a, int b) {
	if (a > max || b < min)
		return 0;
	if (min >= a && max <= b) {
	    return (segTree[node].flag ? ((max - min + 1) - segTree[node].count) : segTree[node].count);
	}
	passFlag (node, min, max);
	int mid = (min + max) / 2;
	int s1 = countHeads (2 * node, min, mid, a, b);
	int s2 = countHeads (2 * node + 1, mid + 1, max, a, b);
	return s1 + s2;
}

void updateSegTree (int node, int min, int max, int a, int b) {
    if (a <= min && b >= max) {
		segTree[node].flag = 1 - segTree[node].flag;
	    passFlag (node, min, max);	    
		return;
	}
    passFlag (node, min, max);
	if (a > max || b < min)
		return;
	int mid = (min + max) / 2;
	updateSegTree (2 * node, min, mid, a, b);
	updateSegTree (2 * node + 1, mid + 1, max, a, b);
	addStructure (segTree[node], segTree[2 * node], segTree[2 * node + 1]);
}

int main () {
	int N, Q, query, A, B;
	scanf ("%d %d", &N, &Q);
	initalizeSegTree (1, 0, N - 1);
	for (int i = 0; i < Q; i++) {
		scanf ("%d %d %d", &query, &A, &B);
		if (query == 1) 
			printf("%d\n", countHeads (1, 0, N - 1, A, B));
		else
			updateSegTree (1, 0, N - 1, A, B);
	}
	return 0;
}