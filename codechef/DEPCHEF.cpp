//           _____   __  .__                               ________ _______   
//          /  _  \_/  |_|  |__ _____ __________  _______  \_____  \\   _  \  
//         /  /_\  \   __\  |  \\__  \\_  __ \  \/ /\__  \   _(__  </  /_\  \ 
//        /    |    \  | |   Y  \/ __ \|  | \/\   /  / __ \_/       \  \_/   \
//        \____|__  /__| |___|  (____  /__|    \_/  (____  /______  /\_____  /
//                \/          \/     \/                  \/       \/       \/ 
//				I♥♥♥CODE
//				--------
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{   lli T;
    cin>>T;
    while(T--)
    {   lli N;
        cin>>N;
        lli* A=(lli*)malloc(N*sizeof(lli));
        lli* B=(lli*)malloc(N*sizeof(lli));
        for(lli i=0;i<N;i++)
            cin>>A[i];
        for(lli i=0;i<N;i++)
            cin>>B[i];
        lli mx=-1,max1=-1,max2=-1;
        vector<pair<lli,lli>> p;
        for(lli i=0;i<N;i++)
            p.push_back(make_pair(A[i],B[i]));
        for(lli i=0;i<N;i++)
        {   if(i==0)
            {   if(p[i].second>(p[N-1].first+p[i+1].first) and mx<p[i].second)
                    mx=p[i].second;
            }
            else
            if(i==(N-1))
            {  if(p[i].second>(p[i-1].first+p[0].first) and mx<p[i].second)
                    mx=p[i].second;
            }
            else
            {   if(p[i].second>(p[i-1].first+p[i+1].first) and mx<p[i].second)
                    mx=p[i].second;
            }
        }
        cout<<mx<<"\n";
    }
    return 0;
}
