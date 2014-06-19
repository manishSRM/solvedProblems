#include<iostream>
#include <stdio.h>                         // segvhunt.c Find and eliminate all code that generates Segmentation Fault
	                                                                                            
using namespace std;

int main() {
	char **s ;			    // Double pointer
	char foo[] = "Hello World";
	*s = foo;
	printf("s is %p\n", s);
	s[0] = foo;
	printf("s[0] is %p\n", s[0]);
	return(0);
}

