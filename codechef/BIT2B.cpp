#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int x;
        cin >> x;

        int count1 = 0;
        int count2 = 0;

        int sum = 0;

        for (int i = 0; i < n; i++)
            sum += a[i];

        int i = 0;
        int j = n - 1;
        int f = true;
        while (f)
        {
            if (i == j)
            {
                if (count1 < count2)
                    count2++;
                else
                    count1++;

                f = false;
            }

            if (a[j] >= 1)
            {
                a[j]--; // subtract 1 value from a[j]
            }
            if (a[j] == 0)
            {
                j--;
                a[j]--;
                count2++;
            }

            if (a[i] >= a[j] * x)
            {
            }
        }
    }
}