#include<stdio.h>
void main()
{
	int i,j,k;
	for(i=1;i<=5;i++)
{

	 	 for(j=5;j>6-i;j--)
	  {
	    printf("%d",j);
       }
    for(k=i;k<=5;k++)
	{
		 if(i==4&&k==4)
		 {
		 	printf("2");
		 }
		 else if(i==5&&k==5)
		 {
		 printf("1");  	
		 }
		 else
		 {
		 printf("%d",k);
	     }
	} 
	
    printf("\n");   
	 
	 
}
getch();
}
