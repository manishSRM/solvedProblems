#include<stdio.h>

using namespace std;

int main() {
	FILE *fptr;
	char filename[] = "file.dat";
	char ch[100] = "computer science";
	int a = 11, b = 12;
	fptr = fopen(filename, "w");
	if(fptr == NULL) {
		printf("ERROR IN FILE\n");
		return -1;
	}
	fprintf(fptr, "Welcome in C!\n");
	fprintf(fptr, "%s", ch);
	fprintf(stdout, "hello world!\n");
	fscanf(stdin, "%d", &a);
	fprintf(stdout, "value of a = %d\n", a);
	return 0;
}
