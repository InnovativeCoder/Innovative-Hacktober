#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

ll power(ll x, ll y)
{

    ll res = 1;
    x = x % mod;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % mod;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % mod;
    }
    return res % mod;
}

int main()
{

    int t;
    cin >> t;
    // while (t--)
    // {
    //     ll n, ans, end;
    //     cin >> n;
    //     end = n;

    //     ans = 1;
    //     for (int i = 1; i <= n; i++)
    //     {
    //         ans = (ans * power(i, n - i + 1)) % mod;
    //     }
    //     cout << ans << endl;
    // }

    int ans = (t << 2);
    cout << ans;
    return 0;
}