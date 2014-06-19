#include <cstdio>
#define MAX 1000 

using namespace std;

int A[MAX];
char Ch[MAX];

int isBomb (int A[], int i, int l) {
    //if i is not in range (0 to l-1) it returns 0 without checking A[i]
    if (i >= 0 && i < l) {
        if (A[i] == 1)
            return 1;
    }
    return 0;   
}

int count_NumberOfBuilding(int l) {
	int count = 0, i;
	for(i = 0; i < l;) {
		if(A[i] == 1) 	
			i += 2;
		else if(!isBomb (A, i-1, l) && !isBomb (A, i+1, l)) {
			count++;
			i += 1;
		}
		else
			i += 1;
	}
	return count;
}

void input_Array(int l) {
	for(int i = 0; Ch[i] != '\0'; i++) 
		A[i] = Ch[i] - '0';	
}	

void test_Cases(int T) {
	int size, r;
	for(int i = 0; i < T; i++) {
		scanf("%d", &size);
		scanf("%s", Ch);
		input_Array(size);
		r = count_NumberOfBuilding(size);
		printf("%d\n", r);
	}
}

int main() {
	int T;
	scanf("%d", &T);
	test_Cases(T);
	return 0;
}