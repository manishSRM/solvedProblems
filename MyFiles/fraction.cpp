#include <cstdio>

using namespace std;

typedef struct {
	int numerator;
	int denominator;
}FRACTION;

	FRACTION f1;
	FRACTION f2;
	FRACTION res;

void input_values(FRACTION f1) {
	scanf("%d %d", &f1.numerator, &f1.denominator);
}

FRACTION multiply_fraction (FRACTION f1, FRACTION f2) {
	FRACTION temp;
	temp.numerator = f1.numerator * f2.numerator;
	temp.denominator = f1.denominator *f2.denominator;
	return temp;
}

void print_fraction(FRACTION res) {
	printf("%d / %d", res.numerator, res.denominator);
	printf("\n");
}

int main() {
	//input_values(f1);
	//input_values(f2);
	//res = multiply_fraction(f1,f2);
	//print_fraction(f1, f2, res);
	print_fraction(f1);
	return 0;
}

