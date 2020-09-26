#include<stdio.h>
int main()
{
    int n,t;
    //printf("Enter the number : ");
    scanf("%d",&n);
    
    for(int j=1; j<=(2*n-1); j++)
    {
        for(int i=1; i<=(2*n-1); )
        {
            if(j <= n)
            {
                while(i<=j)
                {
                    t = (n+1)-i;                
                    printf("%d ",t);
                    i++;    
                }
                
                if(j<=(n-1))
                {            
                    int counter = 1;
                    while(i>j && counter<=(2*n-1 - 2*j))
                    {
                        printf("%d ",t);
                        i++;
                        counter++;
                    }
                }
                                
                while(i<=(2*n-1))
                {    
                    if(j==n)
                        printf("%d ",++t);
                    else
                        printf("%d ",t++);
                    i++;
                }
            }
            if(j > n)
            {
                int m = n;
                while(i<=(2*n-j))
                {
                    printf("%d ",m--);
                    i++;
                }
                
                int count2 = 1;
                m++;
                while(count2 <= (2*j-2*n-1))
                {
                    printf("%d ",m);
                    i++;
                    count2++;
                }
                
                while(i<=(2*n-1))
                {
                    printf("%d ",m++);
                    i++;
                }
            }
        }
        printf("\n");
    }
}