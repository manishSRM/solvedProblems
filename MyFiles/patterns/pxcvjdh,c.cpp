#include<stdio.h>
int main()
{
	int i,j,k,l;
	for(i=1;i<=5;i++)
	{
	 for(j=1;j<=5-i;j++)
	  {
 	  	printf(" ");
	  }	
	  for(k=1;k<=i;k++)
	  {
	  	if(k%2==0)
	  	{
	  		printf(" ");
	  	}
	  	else
	  	{
	  	printf("*");
	     }
	  }
	  for(l=1;l<i;l++)
	  {
	  	 if(i%2==0)
	  	 { 
	  	 if(l%2==0)
	  	 	printf(" ");
	  	 else
	  	 	printf("*");
         }
	  	 else if(l%2==0)
	  	 {
	  	    printf("*");
	     }
	     else
	     printf(" ");

      }
	  printf("\n");
	}
	
	
	
}
