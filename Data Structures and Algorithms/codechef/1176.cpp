#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll a[70];

ll fib(ll n)
{
    if (a[n] != -1)
        return a[n];

    if (n < 1)
    {
        a[0] = 0;
        return a[0];
    }

    if (n == 1)
    {
        a[1] = 1;
        return a[1];
    }

    a[n] = fib(n - 1) + fib(n - 2);
    return a[n];
}

int main()
{
    ll t, n;
    for (ll i = 0; i <= 70; i++)
    {
        a[i] = -1;
    }
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << "Fib(" << n << ") = " << fib(n) << endl;
    }

    return 0;
}