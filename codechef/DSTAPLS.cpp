#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll t, n, k, first, second;

    ll a[100000], b[100000];

    cin >> t;
    while (t--)
    {

        cin >> n >> k;

        // n = no. of apples
        // k = no. of empty boxes

        // one at a time in all
        // k apple at a time in box

        if (k == 1)
        {
            cout << "NO" << endl;
            continue;
        }

        //if same then NO
        // else yes

        first = n / k;

        // for second

        if (first % k == 0)
            cout << "NO" << endl;

        else
            cout << "YES" << endl;
    }

    return 0;
}