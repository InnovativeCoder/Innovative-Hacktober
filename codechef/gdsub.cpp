#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll n, k, ans = 0;

    cin >> n >> k;

    set<int> unique;

    ll a[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        unique.insert(a[i]);
    }
    cout << unique.size() << endl;

    if (k == 0)
    {
        cout << "1";
    }
    if (k == 1)
    {
        cout << n;
    }

    for (int i = 1; i <= k; i++)
    {
    }

    return 0;
}