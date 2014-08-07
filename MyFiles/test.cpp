#include <cstdio>
#include <algorithm>
#include <vector>  
#include <stack>
#include <set>
#include <iostream>
#include <utility>
#include <string.h>
#include <cstring>
    
using namespace std;

int &fun (int &x, int &y) {
	if (x > y)
		return x;
	else
		return y;
}

int main () {
	int a = 9, b = 8;
	fun (a, b) = 1;
	cout << a << endl;
	return 0;
}