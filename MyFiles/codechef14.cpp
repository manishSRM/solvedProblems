#include<stdio.h>
#include<math.h>

using namespace std;

typedef long long int lint;

int isPrime (int num) {
    int i, sqrtNum;                              
    if (num == 1)                                 
           return 0;                                                           
    sqrtNum = sqrt (num) + 1;
    for (i = 2; i <= sqrtNum; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int check_Palindrome(int num) {
	int temp, i, r, n = 0;
	temp = num;
	while(temp) {
		r = temp % 10;
		n = n * 10 + r;
		temp /= 10;
	}
	if(n == num) 
		return 1;
	else 
		return 0;
}

int next_Prime(int num) {
	int i, r, r2, flag = 1;
	i = num;
	while(i) {
		r = check_Palindrome(i); 
		if(r == 1) {
			r2 = isPrime(i);
			if(r2 == 1)
				return i;
		}
		i++;	
	}	
}

int main() {
	int num, n;
	scanf("%d", &num);
	n = next_Prime(num);
	printf("%d\n", n);
	return 0;
}	