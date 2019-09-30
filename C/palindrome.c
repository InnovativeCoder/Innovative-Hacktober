/* Name :Kashish Gupta
Roll no :19
PRN :1814110021

		"Program for Palindrome"
*/
#include <stdio.h>
#include <string.h>

int main()
{
  char a[100], b[100];
  clrscr();
  printf("Enter a string to check if it is a palindrome\n");
  gets(a);

  strcpy(b, a);
  strrev(b);

  if (strcmp(a, b) == 0)
    printf("The string is a palindrome.\n");
  else
    printf("The string isn't a palindrome.\n");
  getch();
  return 0;
}
