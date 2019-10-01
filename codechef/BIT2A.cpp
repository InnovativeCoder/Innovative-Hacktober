#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{

    ll t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        int a[n];

        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (ll i = 0; i < n; i++)
        {
            int temp = a[i];
            ll j;
            for (j = i + 1; j < n; j++)
            {
                if (a[j] > temp)
                    break;
            }

            a[i] = n - j;

            if (j == n)
            {
                a[i] = 0;
            }

            cout << a[i] << " ";
        }

        cout << endl;
    }

    return 0;
}