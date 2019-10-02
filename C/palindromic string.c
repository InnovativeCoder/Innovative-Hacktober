
#include<stdio.h>
void main()
{
    
    char a[50];
    short int i, j, l , count=0;
    gets(a);
    l=strlen(a);
    for(i=0,j=l-1;i<l&&j>=0;i++,j--)
    {
        if(a[i]!=a[j])
            break;
        else
            count++;
    }
    if(count==l)
        printf("YES");
    else
        printf("NO");
    