/*
Question) Print below pattern!

    *
   * *
  * * *
 * * * *
* * * * *
for n=5


*/


#include<stdio.h>

void main()
{
	int i,j,k,n;
	printf("enter n value:\n");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		for(j=n-1;j>=i;j--)
		{
			printf(" ");
		}
		for(k=1;k<=i;k++)
		{
			printf("* ");
		}
		printf("\n");
	}
}
