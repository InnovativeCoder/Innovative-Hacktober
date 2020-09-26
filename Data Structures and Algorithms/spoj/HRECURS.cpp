#include <bits/stdc++.h>
using namespace std;

int sum(int a[], int n)
{
    if (n <= 0)
        return 0;

    return (sum(a, n - 1) + a[n - 1]);
}

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

        cout << sum(a, n) << endl;
    }

    return 0;
}