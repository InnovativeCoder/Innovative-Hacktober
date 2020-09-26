#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n,r,sum;
    scanf("%d", &n);
    //Complete the code to calculate the sum of the five digits on n.
    
    while(n>0)
    {
        r = n%10;
        n = n/10;
        sum += r;
    }
    printf("%d",sum);
    
    return 0;
}