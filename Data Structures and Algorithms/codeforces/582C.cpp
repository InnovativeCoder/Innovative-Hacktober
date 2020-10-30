#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout<<fixed;
 
    int q;
    cin>>q;
    while(q--)
    {
        
        long long n,m,s=0,num,i=2,x,r;
        cin>>n>>m;
        vector<int>v;
        num=n/m;
        r=m%10;
        v.emplace_back(r);

        while(i!=11)
        {
            x=(r*i)%10;
            v.emplace_back(x);
            i++;
        }

        i=0;

        while(i<v.size())
        {
            s+=v[i];
            i++;
        }

        s=s*(num/10);
        i=0;
 
        while(num%10)
        {
            s+=v[i];
            if(i==v.size()-1)
                i=-1;
            i++;
            num--;
        }
        
        cout<<s<<'\n';
    }
    return 0;
}