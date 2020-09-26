#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int n, a = 0, b = 7, near;
    while(t--){
        cin >> n;
        if(abs(n-a) == abs(n-b)){
            if(a < b){
                cout << "A" << endl;
                a = n;
            }else{
                cout << "B" << endl;
                b = n;
            }
        }else if(abs(n-a) > abs(n-b)){
            cout << "B" << endl;
            b = n;
        }else{
            cout << "A" << endl;
            a = n;
        }
    }
    return 0;
}
