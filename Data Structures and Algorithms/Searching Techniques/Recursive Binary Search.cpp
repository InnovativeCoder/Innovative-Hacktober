#include <bits/stdc++.h>
using namespace std;

vector<int>arr{1,2,3,4,5,6};
int searchMe(int elem,int l,int r){
    if(r<l)
        return -1;
    int mid = (l+r)/2;
    if(arr[mid]==elem)
        return mid;
    else if(elem<arr[mid])
        return searchMe(elem,l,mid-1);
    return searchMe(elem,mid+1,r);
}
int main(int argc, char const *argv[]){
    
    int elem;
    cin>>elem;
    // cout<<searchMe(elem+=1,0,arr.size()-1);
    cout<<sizeof(elem+5.0);
    // cout<<elem;
    return 0;
}
