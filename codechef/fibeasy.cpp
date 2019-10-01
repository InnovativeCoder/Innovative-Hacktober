#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int a[61] = {0};

int fact()
{
    int first = 0;
    int second = 1;
    a[1] = 0;
    a[2] = 1;
    for (int i = 3; i <= 60; i++)
    {
        int ans = (first + second) % 10;
        first = second;
        second = ans;
        a[i] = ans;
    }
}

int bin(ll n)
{
    int length = 0;
    while (n > 1)
    {
        n = n >> 1;
        length++;
    }
    return length;
}

int main()
{

    fact();
    int t;
    ll n;
    ll ans = 0;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n == 1)
        {
            cout << "0" << endl;
            continue;
        }
        // ll temp = n % 60;
        int index = bin(n);
        ll ans = pow(2, index);
        ans = ans % 60;
        cout << a[ans] << endl;
    }
    return 0;
}
