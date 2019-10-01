#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, a, c, b;

    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c;

        ll count = 0;

        for (int i = 1; i <= b; i++)
        {
            for (int j = 2; j <= a; j++)
            {
                // if a term can handle on its own
                if (i * i < (j - 1))
                {
                    int aCount = a - j + 1;
                    int cCount = c - 1;

                    int temp = aCount * cCount;
                    count += temp;
                    j = a + 1;
                    continue;
                }

                //
                for (int k = 2; k <= c; k++)
                {
                    if (i * i < (j - 1) * (k - 1))
                    {
                        // count += c - k + 1;
                        // k = c;

                        // cout << "a" << j << "b" << i << "c" << k << endl;

                        // int aCount = 0;
                        int cCount = 0;

                        // aCount = a - j + 1;
                        cCount = c - k + 1;

                        // int temp = aCount * cCount;
                        count += cCount;

                        // j = a + 1;
                        k = c + 1;
                    }
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}