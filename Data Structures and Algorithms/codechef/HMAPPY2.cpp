//           _____   __  .__                               ________ _______   
//          /  _  \_/  |_|  |__ _____ __________  _______  \_____  \\   _  \  
//         /  /_\  \   __\  |  \\__  \\_  __ \  \/ /\__  \   _(__  </  /_\  \ 
//        /    |    \  | |   Y  \/ __ \|  | \/\   /  / __ \_/       \  \_/   \
//        \____|__  /__| |___|  (____  /__|    \_/  (____  /______  /\_____  /
//                \/          \/     \/                  \/       \/       \/ 
//				                    ♥I♥♥♥CODE♥      
//				                    ==========
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int LCD(lli,lli);
void atharva();
void lose();
void win();
lli N,X,Y,K,val,value,GD,mul,A,B;
int main()
{   lli T;
    cin>>T;
    while(T--)
    {   atharva();
    	if(value>=K)
    		win();
    	else
    		lose();
    }
    return 0;
}
void win()
{       cout<<"Win\n";
}
void lose()
{   cout<<"Lose\n";
}
void atharva()
{   cin>>N>>X>>Y>>K;
    A=N/X,B=N/Y;
    GD=LCD(X,Y);
    mul=X*Y,mul/=GD;
    val=N/mul,value=A+B-2*val;
}
int LCD(lli X,lli Y)
{   if(Y==0)
		return X;
	return LCD(Y,X%Y);
}
