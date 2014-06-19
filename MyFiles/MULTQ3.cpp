#include <cstdio>
#include <iostream>
#define MAX 100000

using namespace std;

#define _DEBUG 1

#if _DEBUG

#define trace1(x)                cout << #x << ": " << x << endl;
#define trace2(x, y)             cout << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cout << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cout << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cout << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cout << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif

struct remainder {
	int countZero;
	int countOne;
	int countTwo;
	int flag;
} segTree[4 * MAX];

void passFlag (int node, int min, int max) {
    if (segTree[node].flag) {
        segTree[node].flag = 0;
        segTree[node].countZero = (max - min + 1) - segTree[node].countZero;
        if (min != max) { 
            segTree[node * 2].flag = 1 - segTree[node * 2].flag;
            segTree[node * 2 + 1].flag = 1 - segTree[node * 2 + 1].flag;
        }
    }
}

void addStructure (remainder &sum, const remainder &v1, const remainder &v2) {
	sum.countZero = v1.countZero + v2.countZero;
	sum.countOne = v1.countOne + v2.countOne;
	sum.countTwo = v1.countTwo + v2.countTwo; 
}

void initalizeSegTree (int node, int min, int max) {
	segTree[node].flag = 0;
	if (min == max) {
		segTree[node].countOne = segTree[node].countTwo = 0;
		segTree[node].countZero = 1;
	}
	else {
		int mid = (min + max) / 2;
		initalizeSegTree (2 * node, min, mid);
		initalizeSegTree (2 * node + 1, mid + 1, max);
		addStructure (segTree[node], segTree[2 * node], segTree[2 * node + 1]);
	}	
}

int countMultiples (int node, int min, int max, int A, int B) {
	if (A > max || B < min)
		return 0;
	if (min >= A && max <= B) {
		return (segTree[node].flag ? ((max - min + 1) - segTree[node].countZero) : segTree[node].countZero);
	}
	passFlag (node, min, max);
	int mid = (min + max) / 2;
	int p1 = countMultiples (2 * node, min, mid, A, B);
	int p2 = countMultiples (2 * node + 1, mid + 1, max, A, B);

	return p1 + p2;
}

void updateSegTree (int node, int min, int max, int A, int B) {
	trace5(node, min, max, A, B)
	if (A <= min && B >= max) {
		 int temp = segTree[node].countZero;
		segTree[node].countZero = segTree[node].countTwo;
		segTree[node].countTwo = segTree[node].countOne;
		segTree[node].countOne = temp;
		segTree[node].flag = 1 - segTree[node].flag;
	    passFlag (node, min, max);	    
		return;
	}
    passFlag (node, min, max);
	if (A > max || B < min)
		return;
	int mid = (min + max) / 2;
	updateSegTree (2 * node, min, mid, A, B);
	updateSegTree (2 * node + 1, mid + 1, max, A, B);
	addStructure (segTree[node], segTree[2 * node], segTree[2 * node + 1]);
}

int main () {
	int N, Q, query, A, B;
	scanf ("%d %d", &N, &Q);
	initalizeSegTree (1, 0, N - 1);
	for (int i = 0; i < Q; i++) {
		scanf ("%d %d %d", &query, &A, &B);
		if (query == 1) 
			printf("%d\n", countMultiples (1, 0, N - 1, A, B));
		else
			updateSegTree (1, 0, N - 1, A, B);
	}
	return 0;
}

// if (min == max) {
// 	    int temp = segTree[node].countZero;
// 		segTree[node].countZero = segTree[node].countTwo;
// 		segTree[node].countTwo = segTree[node].countOne;
// 		segTree[node].countOne = temp;
// 		return;
// 	}
