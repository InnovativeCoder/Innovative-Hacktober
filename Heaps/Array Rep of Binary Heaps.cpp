#include <bits/stdc++.h>
using namespace std;


vector<int>HEAP;
void insert(int x,int ind){
    if(HEAP[0]==0){
        HEAP[ind]=x;
        HEAP[0]+=1;
    }else{
        HEAP[0]+=1;
        HEAP[ind]=x;
        // elem/2 is its parent
        bool done = false;
        while(!done && ind>1){
            if(HEAP[ind/2]>=HEAP[ind]){
                // We are done
                done = 1;
            }else{
                swap(HEAP[ind],HEAP[ind/2]);
                if(ind==1)
                    done=1;
                ind = ind/2;
            }
        }
    }
}

int maxim(){
    if(HEAP[0]==0)
        return -1;
    return HEAP[1];
}

void heapify(){
    bool done = false;
    int ind = 1;
    while(!done){
        if(HEAP[ind]>=HEAP[2*ind] && HEAP[ind]>=HEAP[2*ind+1]){
            done = 1;
        }else{
            if(HEAP[2*ind]>=HEAP[2*ind+1]){
                swap(HEAP[ind],HEAP[2*ind]);
                ind = 2*ind;
            }else{
                swap(HEAP[ind],HEAP[2*ind+1]);
                ind = 2*ind+1;
            }
        }
    }
}

void deleteMaxim(){
    if(HEAP[0]==0)
        return ;
    
    swap(HEAP[HEAP[0]],HEAP[1]);
    HEAP[HEAP[0]]=0;
    HEAP[0]-=1;
    heapify();
}

int main(int argc, char const *argv[]){

    int N,temp,x;
    cin>>N;
    HEAP.resize(N+1);

    x=N;
    int elem = 1;
    while(x--){
        cin>>temp;
        insert(temp,elem);
        elem+=1;
    }
    cout<<"YOUR HEAP IS READY: "<<'\n';
    for(auto e:HEAP)
        cout<<e<<' ';
    cout<<'\n';

    x=N;
    while(x--){
        cout<<maxim()<<'\n';
        deleteMaxim();
    }

    return 0;
}

/*
     5
  4    3
2   1 -1 -4 

0 1 2 3 4  5  6
5 4 3 2 1 -1 -4


5---2
4---1



ceil(5/2)-1

ceil(3/2)-1
*/
