#include<stdio.h>
void main()
{
	int j,l=1,c=1;
	while(l<5)
	{
	for(j=c;j<=l+c-1;j++)
	 {

	  printf("%d ",j);
       
	 }
    printf("\n");
 	 c=j;
	 l=l+1;		 
    }
getch();
}
