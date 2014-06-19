#include <cstdio>
#define MAX 100000
using namespace std;

int A[MAX];

int getMax (int size) {
	int max, temp;
	max = A[0];
	for(int i = 1; i < size; i++) {
		temp = A[i] + i;
		if(max < temp) 
			max = temp;
	}
	return max;
}

int main() 
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i)
	{	int size;
		scanf("%d", &size);
		for(int j = 0; j < size; j++)
			scanf("%d", &A[j]);
		printf("%d\n", getMax(size));
	}
}