#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// // Returns factorial of n
// ll fact(ll n)
// {
//     ll res = 1;
//     for (ll i = 2; i <= n; i++)
//         res = res * i;
//     return res;
// }

// ll nCr(ll n, ll r)
// {
//     return fact(n) / (fact(r) * fact(n - r));
// }

ll nCr(ll n, ll k)
{
    ll ans = 1;
    k = k > n - k ? n - k : k;
    ll j = 1;
    for (; j <= k; j++, n--)
    {
        if (n % j == 0)
        {
            ans *= n / j;
        }
        else if (ans % j == 0)
        {
            ans = ans / j * n;
        }
        else
        {
            ans = (ans * n) / j;
        }
    }
    return ans;
}

int main()
{
    ll t, n, a[100], k;
    cin >> t;
    while (t--)
    {
        map<ll, ll> unique;

        cin >> n >> k;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            unique[a[i]]++;
        }

        if (n == k)
        {
            cout << "1" << endl;
            continue;
        }
        sort(a, a + n);

        map<ll, ll>::iterator it;

        ll remaingingLength = k;
        ll ans = 1;

        for (it = unique.begin(); it != unique.end(); it++)
        {
            ll count = it->second;

            // cout << it->first << " " << it->second << " " << endl;

            if (remaingingLength <= count)
            {
                // ans = ans * count C remainingLength;
                // cout << "reaminf <=count\n";

                ans = ans * nCr(count, remaingingLength);
                break;
            }

            else if (remaingingLength > count)
            {
                // ans = ans * count C count;
                // cout << "reaming > count";

                remaingingLength -= count;

                // ans = ans * nCr(count, count);
            }
        }

        cout << ans << endl;
    }
}