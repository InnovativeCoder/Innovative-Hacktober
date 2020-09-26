//Prime no which are palindrome b/w 100-200
#include<stdio.h>
#include<conio.h>
void main()
{
int i,j,k,flag,temp,rev;
clrscr();
for(i=100;i<200;i++)
{
flag=1;
for(j=2;j<i;j++)
{
 if(i%j==0)
 {
  flag=0;
  break;
 }
}
if(flag==1)
{
 temp=i;
 rev=0;
 for(k=0;k<3;k++)
 {
  rev= rev*10 + temp%10;
  temp/=10;
 }
 if(i==rev)
  printf("%d is Prime and Palindrome\n",i);
}
}
getch();
}