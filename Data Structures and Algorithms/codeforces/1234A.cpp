#include<iostream>
#include<string>

using namespace std;

int main()
{
        int t,n,sum=0,x;
        cin>>t;
        while(t--)
        {
                cin>>n;
                for(int i=0; i<n; i++)
                {
                        cin>>x;
                        sum+=x;
                }
                while(1)
                {
                        if(sum%n==0)
                                break;
                        else
                                sum++;
                }
                cout<<sum/n<<endl;
                sum=0;
        }
}

