#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t!=0)
    {
        int n,i,q,j,c=0;
        cin>>n;
        int d[n],p[n];
        for(i=1;i<=n;i++)
        {
            cin>>d[i]>>p[i];
        }
        cin>>q;
        int de[q],re[q];
        for(j=1;j<=q;j++)
        {
            cin>>de[j]>>re[j];
        }
        for(j=1;j<=q;j++)
        {
            for(i=1;i<=n;i++)
            {
                if(d[i]<=de[j])
                {
                    c=c+p[i];
                }
            }
            if(c>=re[j])
                cout<<"Go Camp"<<endl;
            else
                cout<<"Go Sleep"<<endl;
            c=0;
        }
        t--;
    }
    return 0;
}
