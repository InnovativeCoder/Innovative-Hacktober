// Binary Search

#include <bits/stdc++.h>

using namespace std;

int bs(int low, int high, int key)
{

    while (low <= high)
    {
        int mid = (low + ((high - low) / 2)); // Overflow doesn't happen

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
