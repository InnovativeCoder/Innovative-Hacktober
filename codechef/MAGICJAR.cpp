//           _____   __  .__                               ________ _______   
//          /  _  \_/  |_|  |__ _____ __________  _______  \_____  \\   _  \  
//         /  /_\  \   __\  |  \\__  \\_  __ \  \/ /\__  \   _(__  </  /_\  \ 
//        /    |    \  | |   Y  \/ __ \|  | \/\   /  / __ \_/       \  \_/   \
//        \____|__  /__| |___|  (____  /__|    \_/  (____  /______  /\_____  /
//                \/          \/     \/                  \/       \/       \/ 
//					I♥♥♥CODE
//					========
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
void atharva();
lli Num;
int main()
{   lli T;
    cin>>T;
    while(T--)
    {   
        cin>>Num;
        atharva();    
    }
    return 0;
}
void atharva()
{   lli love;
    lli all=0;
    for(lli ath=0;ath<Num;ath++)
    {   cin>>love;
        all+=love;
    }
    all++;
    lli ans=abs(all-Num);
    cout<<ans<<"\n";
    
}
