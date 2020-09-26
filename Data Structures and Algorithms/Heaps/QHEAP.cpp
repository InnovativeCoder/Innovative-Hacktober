#include <bits/stdc++.h>
using namespace std;


vector<int>HEAP;

bool check(int node){
    
    int lchild = 2*node;
    int rchild = 2*node+1;

    
    if(HEAP[node]<HEAP[lchild] || HEAP[node]<HEAP[rchild])
        return false;
    if(lchild<HEAP.size() && HEAP[node]<HEAP[lchild])
        return false;
    else if(lchild<HEAP.size() && HEAP[node]>HEAP[lchild])
        return true;
    else if(lchild >=HEAP.size() && rchild>=HEAP.size())
        return true;
    if(!check(lchild))
        return false;
    if(!check(rchild))
        return false;
    
    return true;
}
int main(){
    int N;
    cin>>N;
    HEAP.resize(N+1);
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=1;i<=N;i++){
        cin>>HEAP[i];
    }

    if(check(1))
        cout<<"TRUE\n";
    else
        cout<<"FALSE\n";
    return 0;
}