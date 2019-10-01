//           _____   __  .__                               ________ _______   
//          /  _  \_/  |_|  |__ _____ __________  _______  \_____  \\   _  \  
//         /  /_\  \   __\  |  \\__  \\_  __ \  \/ /\__  \   _(__  </  /_\  \ 
//        /    |    \  | |   Y  \/ __ \|  | \/\   /  / __ \_/       \  \_/   \
//        \____|__  /__| |___|  (____  /__|    \_/  (____  /______  /\_____  /
//                \/          \/     \/                  \/       \/       \/ 
//				                    I♥♥♥CODE
//				                    =======
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define MD 1000000007
lli A,B,K;
lli LCD(lli,lli);
lli inverse(lli);
lli powe(lli,lli);
void atharva();
int main()
{   lli T;
    cin>>T;
    while(T--)
    {   cin>>A>>K>>B;
        atharva();
    }
    return 0;
}
lli LCD(lli A,lli B)
{   if(A==0)
        return B;
    return LCD(B%A,A);
}
lli inverse(lli A)
{   lli ans=LCD(A,MD);
    if(ans!=1)
        return 0;
    else
        return powe(A,MD-2);
}
lli powe(lli A,lli B)
{   if(B==0)
        return 1;
    lli power=powe(A,B/2)%MD;
    power=(power*power)%MD;
    return (B%2==0)?power:(A*power)%MD;
}
void atharva()
{   lli ans1=powe(A-1,(B+1)/2);
    ans1=(1-((ans1%MD)*inverse(powe(A,(B+1)/2)))%MD+MD)%MD;
    if(B%2==0)
    {   lli ans2=powe(A-1,B/2);
        ans2=(((ans2%MD)* inverse(powe(A,B/2)))%MD)*inverse(A+K);
        ans1=ans1+(ans2%MD);
    }
    cout<<ans1%MD<<"\n";
}
