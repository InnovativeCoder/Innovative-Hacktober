#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

int bs(int low, int high, int key)
{

    while (low <= high)
    {
        int mid = (low + high) / 2;
        cout << mid << endl;
        if (mid * mid == key)
        {
            return mid;
        }
        else if (mid * mid > key)
        {
            high = mid - 1;
        }
        else if (mid * mid < key)
        {
            low = mid + 1;
        }
    }

    return -1;
}

int main()
{
    int x;
    cin >> x;

    int a = bs(1, x, x);

    cout << a;

    return 0;
}