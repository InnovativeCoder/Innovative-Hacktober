#include<stdio.h>
void main()
{
	int no;
	int factorial(int);
	printf("\nEnter the value : ");
	scanf("%d",&no);
	if(no>=0)
		printf("\nThe factorial of %d is %d",no,factorial(no));
	else
		printf("\nInput value must be greater than or equal to zero");

}
int factorial(int n)
{
	int fact;
	if((n==1)||(n==0))
		return(1);
	else
		return(n*factorial(n-1));
}
