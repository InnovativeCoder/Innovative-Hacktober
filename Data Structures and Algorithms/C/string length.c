#include<stdio.h>
int main(void)
{
	int i;
	char a[100];
	printf("enter the string\n");
	gets(a);
	while(a[i]!='\0')
	{
		i++;
	}
	printf("The legth of the string is %d",i);
	return 0;
}
