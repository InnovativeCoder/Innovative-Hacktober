#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
    int ans = 1;
    if (n == 0)
    {
        return 1;
    }

        ans = n * fact(n - 1);

    return ans;
}
int main()
{

    int a, b;

    cin >> a >> b;
    a = a > b ? b : a;

    cout << fact(a);
    return 0;
}