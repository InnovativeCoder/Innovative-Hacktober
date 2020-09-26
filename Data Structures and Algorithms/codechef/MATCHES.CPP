//Codechef cookoff -COOK110B
//Problem link - https://www.codechef.com/problems/MATCHES
//By Satyam 

#include <iostream>
typedef long long ll;
using namespace std;

int main() {
    int cnt[10]={6,2,5,5,4,5,6,3,7,6};
    ll t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        a = a+b;
        ll count=0,temp;
        while(a){
            temp = a%10;
            count += cnt[temp];
            a /= 10;
        }
        cout<<count<<endl;
    }
	return 0;
}
