#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;

        int a[n][m] = {0};

        cout << n * m << " ";

        for (int k = 1; k < (n * m) - 1; k++)
        {

            int temp = k;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {

                    if (temp == k)
                    {
                        a[i][j] = 1;
                        temp = 0;
                        continue;
                    }
                    ++temp;
                }
            }

            temp = k;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {

                    if (temp == k)
                    {
                        a[j][i] = 1;
                        temp = 0;
                        continue;
                    }
                    ++temp;
                }
            }

            int count = 0;

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {

                    if (a[i][j] == 1)
                    {
                        count++;
                    }
                }
            }

            cout << count << " ";
        }
    }
    return 0;
}