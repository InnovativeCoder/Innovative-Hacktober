#include<iostream>
#include<climits>
using namespace std;
int main(){
    int a[1000];
    int n;
    int maxsum=INT_MIN;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //kadane algorithm
    //time complexity is O(n).
    int cursum=0;
    for(int i=0;i<n;i++){
        cursum+=a[i];
        if(cursum>maxsum){
            maxsum=cursum;
        }
        if(cursum<0){
            cursum=0;
        }
    }
    cout<<maxsum<<endl;

}
