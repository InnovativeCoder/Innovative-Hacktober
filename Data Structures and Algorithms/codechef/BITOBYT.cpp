#include<iostream>
using namespace std;
#include<cmath>
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		long c=1,d=0,N=0,bi = 1,ni=0,by=0;
		cin>>N;
		N--;
		d=N%26;
		if((d>=0)&&(d<2))
		{
			c=N/26;
      		c=pow(2,c);
			ni=0;by=0;
			bi=c;
		}
		else if((d>=2)&&(d<10))
		{
			c=N/26;
			c=pow(2,c);
			bi=0;by=0;
			ni=c;
		}	
		else if((d>=10)&&(d<26))
		{
			c=N/26;
			c=pow(2,c);
			bi=0;ni=0;
			by=c;
		}
		cout<<bi<<" "<<ni<<" "<<by<<endl;
	}
	return 0;
}

