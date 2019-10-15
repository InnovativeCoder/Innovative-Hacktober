
/* C PROGRAM TO PRINT OF BLOCK F */
/*AUTHOR: ABHINAV DEEP RASTOGI*/
#include <stdio.h>
#include <conio.h>
void main (){
int note, bank, fift, amt, hun, twent, te, rem1, rem2, rem3;
clrscr();
printf("Enter the Amount"); //DISPLAY OUTPUT
scanf("%d", &amt);
hun=amt/100;
fift=rem1/50;
twent=rem2/20;
te=rem3/10;

printf("THe bank of hundred in given amount is %d\n", hun);
printf("The bank of fifty in given amount is %d\n", fift);
printf("The bank of twenty in given amount is %d\n", twent);
printf("The bank of ten in given amount is  %d\n", te);
getch();
}