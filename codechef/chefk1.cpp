#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;

        // if (m < n)
        // {
        //     cout << "-1" << endl;
        // }
        // else
        // {

        //     if (n == 1 && m != 1)
        //         cout << "-1" << endl;
        //     if (n == 1 && m == 1)
        //         cout << "1" << endl;
        // }
        if (n == 1)
        {
            if (m == 0)
                cout << "0\n";
            if (m == 1)
                cout << "1\n";
            else
                cout << "-1\n";
        }

        if (m >= n - 1 && m <= (n * (n - 1)))
        {
        }
    }

    return 0;
}