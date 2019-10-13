#include <iostream>

#include <cstring>

using namespace std;


int main() 

{
    
    int i,l,sum=0;

    char str[100];

    cin>>str;

    l=strlen(str);

    for(i=0;i<l;i++)

    {

        sum=sum+(int(str[i])-96);

    }

    cout<<sum;


}