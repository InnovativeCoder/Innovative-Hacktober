#include <bits/stdc++.h>
using namespace std;
 
#define f_loop(n) for(int i=0;i<n;i++)
 
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int nr,n,l,r,s=0;
    cin>>n>>l>>r;
    nr=n;
    int num=1<<l;
    while(nr)                             
    {
    	if(num!=1)
    		num>>=1;
    	s+=num;
    	nr--;
    }
    cout<<s<<' ';
    
    int f=1;
    num=1;
    s=1;
    while(n-1)
    {
    	if(f<r)
    	   num<<=1;
    	s+=num;
    	f++;
    	n--;
    }
    cout<<s;
 
    return 0;
}