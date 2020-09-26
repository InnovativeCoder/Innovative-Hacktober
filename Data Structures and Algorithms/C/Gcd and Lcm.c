#include<stdio.h>
int main()
{
	int a,b,gcd,lcm,x,y;
	printf("\nEnter the first positive integer : ");
	scanf("%d",&a);
	printf("\nEnter the second positive integer : ");
	scanf("%d",&b);
	if((a==0)||(b==0))
	{
		printf("\nGCD and LCM is computed for positive integers");
	}
	else
	{
		x=a;
		y=b;
		while(x!=y)
		{
			if(x>y)
				x=x-y;
			else
				y=y-x;
		}
		gcd=x;
		printf("\nGCD of %d and %d is %d",a,b,gcd);
		lcm=(a*b)/gcd;
		printf("\nLCM of %d and %d is %d",a,b,lcm);
	}
	return 0;
}
