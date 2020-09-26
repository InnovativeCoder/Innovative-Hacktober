#include <bits/stdc++.h>
using namespace std;

vector<int>ARR;

void heapify(int ind){
    
    while((2*ind<ARR.size() && 2*ind+1<ARR.size()) && (ARR[2*ind]>ARR[ind] || ARR[2*ind+1]>ARR[ind])){
        if(ARR[2*ind]>ARR[2*ind+1]){
            swap(ARR[ind],ARR[2*ind]);
            ind = 2*ind;
        }else{
            swap(ARR[ind],ARR[2*ind+1]);
            ind = 2*ind+1;
        }
    }
    if(2*ind<ARR.size() && ARR[2*ind]>ARR[ind]){
        swap(ARR[ind],ARR[2*ind]);
    }
}

int getMax(){
    if(ARR.size()<=1)
        return -1;
    return ARR[1];
}

void extractMax(){
    if(ARR.size()<=1)
        return ;
    swap(ARR[ARR.size()-1],ARR[1]);
    ARR.pop_back();
    int ind = 1;

    while((2*ind<ARR.size() && 2*ind+1<ARR.size()) && (ARR[2*ind]>ARR[ind] || ARR[2*ind+1]>ARR[ind])){
        if(ARR[2*ind]>ARR[2*ind+1]){
            swap(ARR[ind],ARR[2*ind]);
            ind = 2*ind;
        }else{
            swap(ARR[ind],ARR[2*ind+1]);
            ind = 2*ind+1;
        }
    }
    if(2*ind<ARR.size() && ARR[2*ind]>ARR[ind]){
        swap(ARR[ind],ARR[2*ind]);
    }
}

void heapSort(){
    int xx = 1;
    while(1){
        xx = getMax();
        extractMax();
        if(xx==-1)
            break;
        cout<<xx<<' ';
    }
}

void heapifyUtil(){
    for(int i=(((int)ARR.size()-1)/2);i>=1;i--){
        heapify(i);
    }
}

int main(int argc, char const *argv[]){
    
    int N;
    cin>>N;
    ARR.resize(N+1);
    ARR[0]=-1;

    for(int i=1;i<ARR.size();i++)
        cin>>ARR[i];
    
    heapifyUtil();
    heapSort();


    for(int i=1;i<ARR.size();i++)
        cout<<ARR[i]<<' ';
    cout<<'\n';
    return 0;
}
