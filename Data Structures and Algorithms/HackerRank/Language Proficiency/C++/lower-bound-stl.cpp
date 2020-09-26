#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    vector<int> v;
    vector<int>::iterator low, up;
    int n, temp, a, q;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin >> temp; 
        v.push_back(temp);
    }
    cin >> q;
    while(q--){
        cin >> a;
        if(binary_search(v.begin(), v.end(), a)){
             low = lower_bound(v.begin(), v.end(), a);
            cout << "Yes " << (low-v.begin()+1) << endl;
        }else{
             up = upper_bound(v.begin(), v.end(), a);
            cout << "No " << (up-v.begin()+1) << endl;
        }
    }
    
    return 0;
}
