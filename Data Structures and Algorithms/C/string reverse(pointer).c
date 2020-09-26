#include<stdio.h>
void main()
{
	char s1[200],s2[200];
	void rev(char *p1,char *p2);
	printf("\n enter the string\n");
	gets(s1);
	rev(s1,s2);
	printf("\n The original string is %s",s1);
	printf("\n The Reversed string is %s",s2);
}
void rev(char *p1,char *p2)
{
	int len=0;
	while(*p1!='\0')
	{
		p1++;
		len++;
	}
	p1--;
	while(len>0)
	{
		*p2=*p1;
		p2++;
		p1--;
		len--;
	}
	*p2='\0';
}

