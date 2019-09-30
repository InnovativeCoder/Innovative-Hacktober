#include<iostream>
using namespace std;

int main()
{
        long long n,x,cnt=0,r=0;
        cin>>n;
        x=n;
        bool f = false;
        while(x!=0)
        {
                r = x%10;
                x = x/10;
                if(r==4 || r==7)
                        cnt++;

        }
        if((cnt%7==0 || cnt%4==0) && cnt!=0)
                cout<<"YES";
        else
                cout<<"NO";
}

