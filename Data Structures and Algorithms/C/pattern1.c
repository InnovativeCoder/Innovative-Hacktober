/* 
Question)  Print below pattern!
    *
   **
  ***
 ****
*****
for n=5
and
  *
 **
***
for n=3
*/

#include <stdio.h>

void main(int argc, char const *argv[])
{
	int i,j,k,n;
	printf("Enter the number: \n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=n-1;j>=i;j--)
		{
			printf(" ");
		}
		for (k=1;k<=i;k++)
		{
			printf("*");
		}
		printf("\n");
	}
}
