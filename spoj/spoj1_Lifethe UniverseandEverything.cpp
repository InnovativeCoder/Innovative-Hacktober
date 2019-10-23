#include <bits/stdc++.h>
using namespace std;
int main() {
    int x = 0;
    while(x!=42){
        cin>>x;
        if(x==42)
            exit(0);
        if((x>=0)&&(x<100)){
        cout<<x<<endl;
        }
    }
    return 0;
}
