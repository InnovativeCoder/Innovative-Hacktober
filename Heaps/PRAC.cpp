#include <bits/stdc++.h>
using namespace std;


struct job{
    int id;
    int priority;
    job(){}
    job(int a,int b):id(a),priority(b){}
};


vector<job>HEAP;

//     5
//   3   4
// 2  8 10
// 6 : 5 3 4 2 8 10
void heapifyUtil(int ind){
    int left = 2*ind;
    int right = 2*ind+1;
    while((left<HEAP[0] && right<HEAP[0]) && (HEAP[left]<HEAP[ind] || HEAP[right]<HEAP[ind])){
        if(HEAP[left]<HEAP[right]){
            swap right and par;
            ind = right;
        }else{
            swap left and par
            ind = left;
        }
    }
    if(left<HEAP[0] && HEAP[left]<HEAP[ind]){
        swap left and par
    }
}
void heapifyArray(){
    for(int i = (HEAP[0]/2);i>=0;i--)
        heapifyUtil(i);
}
int main(){

    int N;
    cin>>N;
    HEAP.resize(N+1);
    HEAP[0]=0;
    for(int i=1;<HEAP.size();i++){
        cout<<"Insert job details\n";
        cin>>HEAP[i].id;
        cin>>HEAP[i].priority;
        HEAP[0]++;
    }
    heapifyArray();
    return 0;
}