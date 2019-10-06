#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, t;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    for(int i=0; i<n/2; i++)
    {
        t = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = t;
    }

    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}
