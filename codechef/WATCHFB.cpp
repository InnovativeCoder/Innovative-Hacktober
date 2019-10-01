#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, x, a, b;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int preva = -1;
        int prevb = -1;

        cin >> x >> a >> b;

        if (x == 1)
            preva = a, prevb = b, cout << (a > b ? "YES" : "NO") << endl;
        else
            cout << "NO" << endl;

        for (int i = 0; i < n - 1; i++)
        {
            cin >> x >> a >> b;

            if (x == 1)
                preva = a, prevb = b, cout << (a > b ? "YES" : "NO") << endl;

            else if (x == 2)
            {
                if (preva == -1 && prevb == -1)
                    cout << "NO" << endl;
            }
        }

        return 0;
    }