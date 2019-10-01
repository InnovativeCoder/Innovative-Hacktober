
// CPP program To calculate The Value Of nCr
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

long long int fact(long long int n);

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

// Returns factorial of n
long long int fact(long long int n)
{
    long long int res = 1;
    for (long long int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

// Driver code
int main()
{
    long long int n = 50, r = 25;
    cout << nCr(n, r);
    return 0;
}