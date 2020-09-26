#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007

using namespace std;

ll power(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res % mod;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        ll ans = 1;
        for (ll i = 1; i <= n; i++)
        {
            if (i == 1)
                continue;

            ans = (ans * power(i, n - i + 1, mod)) % mod;
            // cout << ans << endl;
        }

        cout << ans << endl;
    }

    return 0;
}