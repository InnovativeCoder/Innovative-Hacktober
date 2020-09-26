#include<stdio.h>
#include<conio.h>
void main(){
int a, b, c;
clrscr();
printf("Assign the value to a & b=");
scanf("%d %d", &a, &b);
c=a;
a=b;
b=c;
printf("The Value of a=%d",a);
printf("\nThe Value of b=%d",b);
getch();
}
