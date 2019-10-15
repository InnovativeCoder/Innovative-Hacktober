#include<stdio.h>
int main()
{
	long long int T,K,P1,P2,j;
	scanf("%lld",&T);
	 if(T>=1)
	 {
       for(j=1;j<=T;j++)
       {
         scanf("%lld%lld%lld",&P1,&P2,&K);
          P1=P1+P2;
          K=P1/K;
          K=K%2;
          if(K == 0)
          {
             printf("CHEF\n");
          }
          else
          {
             printf("COOK\n");
          }
       }
	 }
	 return(0);

}