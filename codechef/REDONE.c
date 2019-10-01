#include <stdio.h>
int main() {
        int test,num,loop=1000000;
        long long int var1,var3=1000000007;
        long int array[loop];
        array[0]=0,array[1]=1;
        for(var1=2;var1<loop;var1++)
        {
        long long int var2=array[var1-1]*var1+var1+array[var1-1];
        long long int var4=var2%var3;
            array[var1]=var4;
        }
            scanf("%d",&test);
            while(test--)
            {
                scanf("%d",&num);
                printf("%ld",array[num]);
                printf("\n");
            }
	return 0;
}

