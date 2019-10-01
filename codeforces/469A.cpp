#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int p;
    cin >> p;
    int a[p];

    int f[101] = {0};

    for (int i = 0; i < p; i++)
    {
        cin >> a[i];
        f[a[i]]++;
    }

    int q;
    cin >> q;
    int b[q];

    for (int i = 0; i < q; i++)
    {
        cin >> b[i];
        f[b[i]]++;
    }

    int flag = 0;

    for (int i = 1; i <= n; i++)
    {
        if (f[i] == 0)
        {
            flag = 1;
            break;
        }
    }

    if (flag)
        cout << "Oh, my keyboard!" << endl;
    else
        cout << "I become the guy." << endl;
}