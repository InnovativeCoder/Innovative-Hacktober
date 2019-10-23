#include<iostream>
using namespace std;
int main()
{
    int n,r,i;
    cin>>n>>r;
        int R[n];
        for(i=1;i<=n;i++)
        {
            cin>>R[i];
        }
        for(i=1;i<=n;i++)
        {
            if(R[i]>=r)
                cout<<"Good boi\n";
            else
                cout<<"Bad boi\n";
        }
    return 0;
}
