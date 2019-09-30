#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

// ll nCr(ll n, ll k)
// {
//     ll ans = 1;
//     k = k > n - k ? n - k : k;
//     ll j = 1;
//     for (; j <= k; j++, n--)
//     {
//         if (n % j == 0)
//         {
//             ans = (ans * (n / j)) % mod;
//         }
//         else if (ans % j == 0)
//         {
//             ans = (ans / j * n) % mod;
//         }
//         else
//         {
//             ans = ((ans * n) % mod) / j;
//         }
//     }
//     return ans % mod;
// }

/* Iterative Function to calculate (x^y)%p 
in O(log y) */
ll power(ll x, ll y, ll p)
{
    ll res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
               // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

// Returns n^(-1) mod p
ll modInverse(ll n, ll p)
{
    return power(n, p - 2, p);
}

// Returns nCr % p using Fermat's little
// theorem.
ll nCr(ll n, ll r, ll p)
{
    // Base case
    if (r == 0)
        return 1;

    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    ll fac[n + 1];
    fac[0] = 1;
    for (ll i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % p;

    return (fac[n] * modInverse(fac[r], p) % p *
            modInverse(fac[n - r], p) % p) %
           p;
}

int main()
{
    ll k, n;

    cin >> n >> k;

    ll a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll ans = 0;

    for (int i = 0; i <= k; i++)
    {
        ll temp = nCr(n, i, mod);

        ans = (ans + temp) % mod;
    }

    cout << ans << endl;
}