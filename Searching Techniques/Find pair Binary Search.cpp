#include <bits/stdc++.h>
using namespace std;
#define FORI(i,a,b) for(int i=a;i<b;i++)

int searchMe(vector<int>&arr,int elem,int l,int r){
    if(r<l)
        return -1;
    int mid = (l+r)/2;
    if(arr[mid]==elem)
        return mid;
    else if(elem<arr[mid])
        return searchMe(arr,elem,l,mid-1);
    return searchMe(arr,elem,mid+1,r);
}
int main(int argc, char const *argv[]){
    
    int N;
    cin>>N;
    vector<int>ARR(N);
    FORI(i,0,N)
        cin>>ARR[i];
    sort(ARR.begin(),ARR.end());
    int P;
    cin>>P;
    int count=0;
    FORI(i,0,N){
        if(searchMe(ARR,ARR[i]+P,i,N-1)!=-1){
            cout<<ARR[i]<<" "<<P+ARR[i]<<'\n';
            count+=1;
        }
    }
    cout<<"TOTAL: ";
    cout<<count<<'\n';
    return 0;
}
