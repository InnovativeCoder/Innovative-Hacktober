#include <bits/stdc++.h>
using namespace std;
int main()
{
int t,test,mul,co=0,cot=0,maxi=0,mini=0;
    cin>>test;
    while(test--)
    {
        co=0,cot=0,maxi=0,mini=0,t=0;
    cin>>t;
    int ar[t];
    for(int i=0;i<t;i++)
    {
        cin>>ar[t];
        if (ar[t]>0)
            co++;
        else if(ar[t]<0)
            cot++;
    }
    if(co>cot)
    {
        maxi=co;
        mini=cot;
    }
    else if(cot>co)
    {
        maxi=cot;
        mini=co;
    }
    if(co==t)
        cout<<maxi<<" "<<maxi<<endl;
    else
      cout<<maxi<<" "<<mini<<endl;
    }
}
