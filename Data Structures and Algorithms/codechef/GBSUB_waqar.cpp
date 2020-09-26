#include <bits/stdc++.h>
#define REP(i, n) for (i = 1; i <= n; i++)
#define mod 1000000007
#define pb push back
#define ll long long int

using namespace std;

ll dp[1010][1010];
ll val[1010];

ll getMeAns(ll k, ll n)
{
    ll ans = 1;
    return ans;
}
int main()
{

    map<int, int> mp;

    ll k, n, x, i;

    cin >> n >> k;

    REP(i, n)
    cin >> x,
        mp[x]++;

    for (auto it = mp.begin(); it != mp.end(); it++, i++)
        dp[1][i] = (dp[1][i - 1] + it->second) % mod, val[i] = it->second;

    cout << getMeAns(min(k, (int)mp.size()), mp.size());
    return 0;
}