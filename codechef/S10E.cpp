#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,i,p1=751,p2=751,p3=751,p4=751,p5,c=1;
        cin>>n;
        int arr[n];
        for(i=0;i<n;i++)
            cin>>arr[i];
        p5=arr[0];
        for(i=1;i<n;i++){
            if((arr[i]<p1)&&(arr[i]<p2)&&(arr[i]<p3)&&(arr[i]<p4)&&(arr[i]<p5)){
                c++;
            }
            p1=p2;
            p2=p3;
            p3=p4;
            p4=p5;
            p5=arr[i];
        }
        cout<<c<<"\n";
    }
    return 0;
}
