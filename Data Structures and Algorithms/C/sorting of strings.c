#include<stdio.h>
#include<string.h>
int main()
{
	char str[100][100],temp[100];
	int i=0,j=0,n;
	printf("Enter the count:");
	scanf("%d",&n);
	printf("\nEnter the strings\n");
	while(i<n)
	{
		scanf("%s",str[i++]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(strcmp(str[j],str[j+1])>0)
			{
				strcpy(temp,str[j]);
				strcpy(str[j],str[j+1]);
				strcpy(str[j+1],temp);
			}
		}
	}
	printf("\n Alphabetically sorted list\n");
	for(i=0;i<n;i++)
	{
		printf("%s\n",str[i]);
	}
	return 0;
}
