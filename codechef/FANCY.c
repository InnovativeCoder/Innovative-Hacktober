#include<stdio.h>
int main()
{
    int i,t,c=0;
    char str[100];
    scanf("%d",&t);
    while(t--)
{       c=0;
        //fflush(stdin);
         scanf(" %[^\t\n]s",&str);
        /*for(i=0; str[i]!='\0';i++)
            printf("%c",str[i]);*/
        for(i=0;str[i]!='\0';i++)
        {
            if(str[0]=='n'&&str[1]=='o'&&str[2]=='t'&&(str[3]==' '||str[3]=='\0'))
                c++;
            else if(str[i]==' '&&str[i+1]=='n'&&str[i+2]=='o'&&str[i+3]=='t'&&(str[i+4]==' '||str[i+4]=='\0'))
                c++;
        }
        if(c>0)
            printf("Real Fancy\n");
        else
            printf("regularly fancy\n");
}
            return 0;
}

