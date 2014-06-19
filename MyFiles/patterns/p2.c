#include<stdio.h>
void main()
{
	int i,j,c=0;
	for(i=1;i<=5;i++)
	 {
	 	for(j=i;j<=i+c;j++)
	 	{
	 		printf("%d ",j);
	 	}
	 	c=c+1;
	   printf("\n");		
		 
	 }
}
