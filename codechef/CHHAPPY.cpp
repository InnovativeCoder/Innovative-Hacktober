#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,x,i,j,k=1,u=0,l;
        cin>>n;
        vector<int> v[n+1], m;
        for(i=1;i<=n;i++)
        {
            cin>>x;
            v[x].push_back(i);
        }
        for(i=1;i<=n;i++)
        {
            l=v[i].size();
            if(l>1)
            {
                for(j=0;j<l;j++)
                {
                    k = v[i][j];
                    if(v[k].size() > 0)
                        u++;
                }
                if(u>1)
                {
                    cout<<"Truly Happy\n";
                    break;
                }
                u=0;

            }
        }
        if(u==0)
          cout<<"Poor Chef\n";
    }
    return 0;
}
