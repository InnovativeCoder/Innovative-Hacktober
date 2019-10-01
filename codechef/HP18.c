#include<stdio.h>
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int b,c,n,d=0,f=0;
        scanf("%d %d %d",&n,&b,&c);
        int a[n],i;
        for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
        if(a[i]%b==0)
        d++;
        else if(a[i]%c==0)
        f++;
        }
        if(d>f)
        printf("BOB\n");
        else
        printf("ALICE\n");
        }
        return 0;
}
