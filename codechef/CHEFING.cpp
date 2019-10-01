//           _____   __  .__                               ________ _______   
//          /  _  \_/  |_|  |__ _____ __________  _______  \_____  \\   _  \  
//         /  /_\  \   __\  |  \\__  \\_  __ \  \/ /\__  \   _(__  </  /_\  \ 
//        /    |    \  | |   Y  \/ __ \|  | \/\   /  / __ \_/       \  \_/   \
//        \____|__  /__| |___|  (____  /__|    \_/  (____  /______  /\_____  /
//                \/          \/     \/                  \/       \/       \/ 
//				                        ♥I♥♥♥CODE♥      
//			                        	==========
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli N;
string LOVE[10000];
void atharva1(lli);
void atharva2();
int main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli T;
    cin>>T;
    while(T--)
    {   cin>>N;
        atharva1(N);
        atharva2();
    }
    return 0;
}
void atharva1(lli N)
{   
    for(lli i=0;i<N;i++)
        cin>>LOVE[i];
}
void atharva2()
{   lli count=0;
    bool freq1[27],freq2[27];
    memset(freq1, true ,27);
    for(lli i=0;i<N;i++)
    {   memset(freq2, false ,27);
        for(lli j=0;LOVE[i][j];j++)
        {   if(freq1[LOVE[i][j]-'a'])
                freq2[LOVE[i][j]-'a']= true;
        }
        memcpy(freq1,freq2,27);
    }
    for(lli i=0;i<27;i++)
    {   if(freq1[i])
            count++;
    }
    cout<<count<<"\n";
}
