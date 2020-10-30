#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int a1,a2,k1,k2,n,d;
    vector< pair <int,int> >v;
    cin>>a1>>a2>>k1>>k2>>n;
    v.emplace_back(make_pair(k1,a1));
    v.emplace_back(make_pair(k2,a2));
    sort(v.begin(),v.end());

    d=n-(v[0].first*v[0].second+v[1].first*v[1].second);          
    if(d>0)
        cout<<0;

    else
    {
        d+=v[0].second+v[1].second;   

        if(d<0)
         cout<<0<<' ';

        else
            cout<<d<<' ';
    }

    int i,j;

    for(i=v[0].second;i>=0;i--)
    {
        if(n-i*v[0].first >=0)
        {
            n-=i*v[0].first;
            break;
        }
    }
    
    for(j=v[1].second;j>=0;j--)
    {
        if(n-j*v[1].first >=0)
            break;
    }
    cout<<i+j;
 
    return 0;
}