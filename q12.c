#include<stdio.h>
int strindex(char s[1000], char t[1000]);
void main(){
char s[1000], t[1000];
int i=0,j=0,c;
printf("enter the string");
gets(s);
printf("enter the string to be matched");
gets(t);
printf("%d",strindex(s,t));
}

int strindex(char s[],char t[])
{
    int i,j,k, r;

    r = -1;

    for(i=0;s[i]!='\0';i++)
    {
        for(j=i,k=0;t[k]!='\0' && s[j]==t[k];j++,k++)
            ;
        if(k>0 && t[k] == '\0')
            r = i;
    }
    return r;
}
