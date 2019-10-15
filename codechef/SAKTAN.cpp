#include<bits/stdc++.h>

#define ll long long

using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m,q,x1,x2,cnt=0;
        cin>>n>>m>>q;
        ll row[n]={0},col[m]={0};
        for(ll i=0;i<q;i++)
        {
            cin>>x1>>x2;
            row[x1-1]++;
            col[x2-1]++;
        }
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                if((row[i]+col[j])%2!=0)
                    cnt++;
            }
        }
        cout<<cnt<<endl;
    }
}
