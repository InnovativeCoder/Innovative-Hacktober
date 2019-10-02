//           _____   __  .__                               ________ _______   
//          /  _  \_/  |_|  |__ _____ __________  _______  \_____  \\   _  \  
//         /  /_\  \   __\  |  \\__  \\_  __ \  \/ /\__  \   _(__  </  /_\  \ 
//        /    |    \  | |   Y  \/ __ \|  | \/\   /  / __ \_/       \  \_/   \
//        \____|__  /__| |___|  (____  /__|    \_/  (____  /______  /\_____  /
//                \/          \/     \/                  \/       \/       \/
//                                      ♥I♥♥♥CODE♥
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
string S;
bool PRIME(lli);
void atharva();
void atharva2();
int main()
{   lli T;
    cin>>T;
    while(T--)
	{   cin>>S;
		if(S.length()<=18)
		    atharva();
		else
		    atharva2();
	}
    return 0; 
}
void atharva()
{   lli freq1[26]={0},freq2[26]={0};
    for(lli j=0;j<S.size();j++)
    {   freq1[S[j]-'A']++;
		freq2[S[j]-'A']++;
	}
    lli len=S.size();
	lli mn=10000000,lng=10000000;
	while(len)
	{   lli count=len;
		if(S.size()%count!=0) 
		{   len--;
			continue;
		}
		for(lli j=0;j<26;j++)
		    freq1[j]=freq2[j];
        lli m=S.size()/count;
		lli A=0;
		for(lli j=0;j<26;j++)
		{   if(freq1[j]==0) 
		        freq1[j]=-1;
			else 
			    freq1[j]=abs(freq1[j]-m);
		}
		sort(freq1,freq1+26);
        lli K=0;
		for(lli j=0;j<26;j++)
		{   if(freq1[j]==-1) 
		        continue;
			if(count==0) 
			{   K+=abs(m-freq1[j]);
				continue;
			};
			count--;
			A+=freq1[j];
		}
		while(count--)
			K+=m;
		if(K+abs(A-K)/2<mn)
		{   lng=len;
		    mn=K+abs(A-K)/2;
		}
        len--;
	}
    cout<<mn<<"\n";
}
void atharva2()
{   lli ans2=0,p=-1,f=0,Z=0,all=0,N=0,ans=0,val=0;
    lli freq[26]={0};
	for(lli j=0;j<S.length();j++)
	    freq[S[j]-'A']++;
	sort(freq,freq+26);
    for(lli j=0;j<26;j++)
	{   if(freq[j]!=0)
		{   if(p==-1)
		        p=j;
		        Z++;
    	        all+=freq[j];
		}
    }
	for(lli j=p;j<25;j++)
	{   if(freq[j]!=freq[j+1])
		{   f=1;
		    break;
		}
	}
    if(f==0)
	    cout<<"0\n";
	else
	{   for(lli j=Z;j>=1;j--)
		{   if(all%j==0)
		    {   val=all/j;
		        N=j;
		        break;
    		}
		}
		for(lli j=25;j>=p;j--)
		{   if(N>0)
		    {   ans+=abs(freq[j]-val);
		        N--;
		    }
		    else
		        ans+=abs(freq[j]);
		}
		if(all<=26 and PRIME(val))
		{   for(lli j=25;j>=p;j--)
		    {   ans2+=abs(freq[j]-1);
		    }
		    if(ans2<(ans/2))
		        ans=2*ans2;
		}
		    cout<<ans/2<<"\n";  
    }
}
bool PRIME(lli N) 
{   if (N<=1) 
        return false; 
    if(N<=3) 
        return true; 
    if(N%2==0 or N%3==0) 
        return false; 
    for(lli i=5;i*i<=N;i+=6) 
        if (N%i==0 or N%(i+2)==0) 
            return false; 
    return true; 
}
