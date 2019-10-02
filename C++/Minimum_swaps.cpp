#include<bits/stdc++.h>
using namespace std;
//Using graph calculate number of cycle for e.g 
int miniSwaps(int arr[],int N)
{
    pair<int,int> p[N];
    for(int i=0;i<N;i++)
    {
        p[i].first=arr[i];
        p[i].second=i;
    }
    sort(p,p+N);
    vector<bool>visited(N,false);
    int ans=0;
    for(int i=0;i<N;i++)
    {
        if(visited[i]||p[i].second==i)
        {
            continue;
        }
        int j=i;
        int cycle_counts=0;
        while(!visited[j])
        {
            visited[j]=1;
            j=p[j].second;
            cycle_counts+=1;
        }
        ans+=cycle_counts-1;
    }
    return ans;
}
int main()
{
    int arr[]={5,4,3,2,1,0};
    int N=sizeof(arr)/sizeof(arr[0]);
    cout<<miniSwaps(arr,N);
}