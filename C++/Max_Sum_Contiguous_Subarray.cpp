#include<bits/stdc++.h>
using namespace std;
int maxSubArray(const vector<int> &A) {
    
    int i,max1=A[0],maxcur=A[0];
    
    
    for(i=1;i<A.size();i++){
        maxcur=max(A[i],maxcur+A[i]);
        max1=max(maxcur,max1);
    }
    return max1;
}

int main(){
    vector<int> v={-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(v)<<endl;;
}