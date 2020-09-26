#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n,k,f=0;
    cin>>n>>k;
    string s;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        if(f==k)
            break;

        if(n==1)
            s[0]='0';

        else
        {
            if(i==0 && s[i]!='1')
            {
                s[i]='1';
                f++;
            }

            else if(i==0 && s[i]=='1')
                continue;

            else if(s[i]=='0')
                continue;
            
            else
            {
                s[i]='0';
                f++;
            }
        }
    }

    cout<<s;
    return 0;
}