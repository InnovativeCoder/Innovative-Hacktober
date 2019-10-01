#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t, n, a[150], b[150];

    cin >> t;
    while (t--)
    {
        cin >> n;

        int pos;
        int neg;
        int ans;
        int temp;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        ans = 0;

        for (int i = 0; i < n; i++)
        {
            temp = (20 * a[i]) - (10 * b[i]);

            if (temp < 0)
                temp = 0;

            if (temp > ans)
                ans = temp;
        }

        cout << ans << endl;
    }

    return 0;
}
