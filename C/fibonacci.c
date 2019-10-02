#include<stdio.h>
int main()
{
	int i,f1,f2,f3,n;
	printf("enter the number of terms to be generated\n");
	scanf("%d",&n);
	f1=0;
	f2=1;
	if(n<0)
	{
		printf("The count should be greater than zero");
	}
	else if(n==1)
	{
		printf("%d",f1);
	}
	else if(n==2)
	{
		printf("%d\t%d",f1,f2);
	}
	else
	{	
		printf("%d\t%d",f1,f2);
		for(i=2;i<n;i++)
		{
			f3=f1+f2;
			printf("\t%d\t",f3);
			f1=f2;
			f2=f3;
		}
	}	
return 0;
}
		
		
	
		

