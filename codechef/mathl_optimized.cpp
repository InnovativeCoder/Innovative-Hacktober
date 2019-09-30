#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

ll a[1000001] = {1};

int main()
{

    ll t;
    cin >> t;

    ll p = 1;
    for (ll i = 1; i <= 1000000; i++)
    {
        p = (p * i) % mod;
        a[i] = (a[i - 1] * p) % mod;
    }

    while (t--)
    {
        ll n;
        cin >> n;
        cout << a[n] << endl;
    }

    return 0;
}