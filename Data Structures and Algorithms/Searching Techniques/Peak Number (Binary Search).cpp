#include <bits/stdc++.h>
using namespace std;
#define FORI(i,a,b) for(int i=a;i<b;i++)

int searchMe(vector<int>&arr,int l,int r){
    if(l==r)
        return l;
    int mid = (l+r)/2;
    if(mid==0 && mid<arr.size()-1 && arr[mid]>arr[mid+1])
        return 0;
    if(mid==arr.size()-1 && mid>0 && arr[mid]>arr[mid-1])
        return arr.size()-1;
    if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])
        return mid;
    if(arr[mid]>=arr[mid-1] && arr[mid]<=arr[mid+1])
        return searchMe(arr,mid+1,r);
    else if(arr[mid]<=arr[mid-1] && arr[mid]>=arr[mid+1])
        return searchMe(arr,l,mid-1);
    else if(arr[mid]<arr[mid+1])
        return searchMe(arr,mid+1,r);
    else
        return searchMe(arr,l,mid-1);
}
int main(int argc, char const *argv[]){
    
    int N;
    cin>>N;
    vector<int>ARR(N);
    FORI(i,0,N)
        cin>>ARR[i];
    
    cout<<ARR[searchMe(ARR,0,N-1)]<<'\n';
    return 0;
}
