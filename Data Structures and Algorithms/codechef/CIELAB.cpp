#include <iostream>
using namespace std;

int main() 
{
    int a,b,c;
    cin>>a;
    cin>>b;
    c=a-b;
    
    if (c%10==9)
    {
        c=c-1;
        
    }
    
    else
    {
        c=c+1;
    }
    
    if(a>=b)
    {
        cout<<c;
    }
    
    else
    {
        cout<<-c;
    }
	// your code goes here
	return 0;
}

