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

    cout << "Enter two positive numbers\n";
    cin >> a >> b;
    
    if(a < 0 || b < 0){
    cout << "Negative value found,enter value again\n";
    cin >> a >> b;
    }
    
    a > b ? cout << fact(b) : cout << fact(a);
    
    return 0;
}
