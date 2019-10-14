//https://www.spoj.com/problems/PT07Z/

// Author - sumit_007 

#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define int ll
#define ps push
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
#define mp make_pair
#define rep(i,a,b) for (int i = a; i < b; i++)
#define repd(i,a,b) for (int i = a; i >= b; i--)
#define remax(a,b) a = max(a,b)
#define remin(a,b) a = min(a,b)
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define F first
#define S second
#define mii map<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define vpii vector<pair<int,int>>
#define pqi priority_queue<int>
#define pqpii priority_queue<pair<int,int>>
#define itr :: iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;
 
vi v[100005];
bool vis[100005];
int len,node;
void dfs(int p,int l){
    if(l>len){
        len = l;
        node = p;
    }
    vis[p] = true;
    for(auto x:v[p]){
        if(!vis[x])
            dfs(x,l+1);
    }
}
 
 
void solve(){
    int n;
    cin>>n;
    rep(i,0,n-1){
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    memset(vis,false,sizeof(vis));
    dfs(1,0);
    memset(vis,false,sizeof(vis));
    len=-1;
    dfs(node,0);
    debug(len);    
}
 
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	cout.tie(0);
	int t=1;
	// cin>>t;    
	WL(t){        
	    solve();
	}
	
}