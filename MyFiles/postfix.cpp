#include <stdio.h>

using namespace std;

void printInPostfix (char string[]) {
    int j = 0;
    char s[500];
    for(int i = 0; string[i] != '\0'; i++)
    {
    	if(string[i] > 96 && string[i] < 123)  
            printf("%c",string[i]);
        else
        if(string[i] != 40 && string[i] != 41) 
            s[j++]=string[i];
        else
        if(string[i]==')') {
            printf("%c",s[j-1]);
            j--;
        }
    }    
	printf("\n");
}

int main()
{	
	int T;
    scanf("%d",&T);
    for (int k = 0; k < T; k++) {
    	char str[500];
    	scanf ("%s", str);
    	printInPostfix (str);
    }
    return 0;
}