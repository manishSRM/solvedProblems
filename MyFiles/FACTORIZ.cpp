#include <cstdio>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <utility>
#include <iostream>
#include <string.h>
#define FOR (A, B, C) for (int A = B; A < C; A++) 
#define EFOR (A, B, C) for (int A = B; A <= C; A++)
#define RFOR (A, B, C) for (int A = B; A >= C; A--)
#define PB(A,B) A.push_back(B); 
#define lint long long int
#define MAX 1001

using namespace std;

typedef pair <long long int, int> PI;
typedef vector <PI> VPI;
typedef vector <int> VI;
typedef vector <VI> VII;
typedef vector <long long int> VL; 

VPI counter;
lint maxvalue = 1000000;

lint storePrime[1001];

void printAllFactor (int M) {
    printf("%d\n", M);
    for (int i = 0; i < counter.size (); i++) {
        lint primeNumber = counter[i].first;
        int count = counter[i].second;
        for (int j = 0; j < count; j++)
            printf("%lld\n", primeNumber);
    }
    return;
}

void storePrimeNumbers () {
	int c = 0;
	for (int i = 2; i <= 7919; i++) {
		int flag = 1;
		for (int j = 2; j <= i / j; j++) {
			if (i % j == 0) {
				flag = 0;
				break;
			}
		}
		if (flag)
			storePrime[c++] = i; 
	}
	return;
}

int bigDivideIfPossible (int num[], int &len, int divider) {
    int temp[len + 1], rem = 0, newLen = 0;
    for (int i = 0; i < len; i++) {
        rem = rem * 10 + num[i];
        if (rem >= divider || newLen != 0) {
            temp[newLen++] = rem / divider;
            rem %= divider;
        }
    }
    if (!rem) {
        len = newLen;
        for (int j = 0; j < len; j++)
            num[j] = temp[j];
    }
    return rem;
}

lint buildNumber (char *str) {
    lint N = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        N = (N * 10) + (str[i] - '0'); 
    }
    return N;   
}

void factorizeSmallNumbers (lint N) {
    int maxCount = 0;
    for (int i = 2; i <= min(N / i, maxvalue); i++) {
        if (N % i == 0) {
            int count = 0, factor = i;
            do {
                N /= i;
                count++;
            } while (N % i == 0);
            counter.push_back (make_pair (factor, count));
            maxCount += count;
        }
    }
    if (N > 0 && N != 1) {
        counter.push_back (make_pair (N, 1));
        ++maxCount;
    }
    printAllFactor (maxCount);
}

int main () 
{
	int T;
	lint N;
	char str[1010];
	scanf ("%d", &T);
	storePrimeNumbers ();
	while (T--) {
		scanf ("%s", str);
		int len = strlen (str), M = 0, rem;
		if (len < 18) {
			lint N = buildNumber (str);
			factorizeSmallNumbers (N);
			counter.clear();
			continue;
		}
		
		int num[len + 1];
		for (int i = 0; i < len; i++)
			num[i] = str[i] - '0';
		for (int k = 0; k < 1000; k++) {
			rem = bigDivideIfPossible (num, len, storePrime[k]);
			if (!rem) {
				M++;
				int count = 1;
				while (!(bigDivideIfPossible (num, len, storePrime[k]))) {
					M++;
					count++;
				}
				counter.push_back (make_pair (storePrime[k], count));
			}
			if (len == 1 && num[len - 1] != 1)
				break;
		}
		if (len != 1 || num[len - 1] != 1) {
			printAllFactor (M + 1);
			for (int c = 0; c < len; c++)
				printf("%d", num[c]);
			printf("\n");
		} else {
			printAllFactor (M);
		}
		counter.clear();
	}
	return 0;
}