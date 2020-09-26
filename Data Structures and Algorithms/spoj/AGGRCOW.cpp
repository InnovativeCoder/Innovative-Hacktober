#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

ll bs(ll a[], ll low, ll high)
{
}

int main()
{
    ll a[100000];
    ll t, n, c;
    cin >> t;

    while (t--)
    {
        cin >> n >> c;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a + n);

        ll ans = bs(a, 0, n - 1);
    }

    return 0;
}