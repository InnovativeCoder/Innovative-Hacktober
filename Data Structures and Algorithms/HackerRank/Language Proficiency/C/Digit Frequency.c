#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    char s[1000];
    int freq[10] = {0};

    scanf("%s",s);

    for(int i=0; i<strlen(s); i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            ++freq[s[i] - '0'];
        }
    }
    for(int j=0; j<10; j++)
    {
        printf("%d ",freq[j]);
    }
    return 0;
}
