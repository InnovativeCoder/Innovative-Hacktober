#include<stdio.h>
int main()
{
    int var;
    printf("3\n");
    fflush(stdout);
    scanf("%d",&var);
    if(var==1)
    {
        printf("2\n");
        fflush(stdout);
    }
    else
    {
        printf("1\n");
        fflush(stdout);
    }
    return 0;
}
