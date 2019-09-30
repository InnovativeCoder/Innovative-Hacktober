/* Name :Kashish Gupta
Roll no :19
PRN :1814110021
		"Factorial of number"		
*/
#include <stdio.h>

int main()
{
  int i,n;
  long fact=1;
  clrscr();

  printf("Enter a number to calculate its factorial\n");
  scanf("%d", &n);

  for (i = 1; i <= n; i++)
    fact = fact * i;

  printf("Factorial of %d = %ld\n", n, fact);

  getch();
  return 0;
}
