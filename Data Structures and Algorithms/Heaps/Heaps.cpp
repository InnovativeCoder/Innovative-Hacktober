#include <bits/stdc++.h>
#define pb push_back
using namespace std;

struct job{
    int id;
    int p;
    job(){};
    job(int a,int b):id(a),p(b){};
};
vector<job>ARR;


void siftup(int ind){
    while(ind>1){
        int par = ind/2;
        if(ARR[par].p<ARR[ind].p){
            swap(ARR[par],ARR[ind]);
            ind = par;
        }else
            break;
        
    }
}
job getMax(){
    if(ARR.size()>1)
        return ARR[1];
    return job(-1,-1);
}
void insert(int id,int p){
    job nJob = job(id,p);
    ARR.pb(nJob);
    siftup(ARR.size()-1);
}

job extractMax(){
    if(ARR.size()<=1)
        return job(-1,-1);
    
    job t = ARR[1];
    swap(ARR[ARR.size()-1],ARR[1]);
    ARR.pop_back();

    int ind = 1;
    while((2*ind<ARR.size() && 2*ind+1<ARR.size()) && (ARR[ind].p<ARR[2*ind].p || ARR[ind].p<ARR[2*ind+1].p)){
        if(ARR[2*ind].p>ARR[2*ind+1].p){
            swap(ARR[2*ind],ARR[ind]);
            ind = 2*ind;
        }else{
            swap(ARR[2*ind+1],ARR[ind]);
            ind = 2*ind;
        }
    }
    if(2*ind<ARR.size())
        if(ARR[2*ind].p>ARR[ind].p)
            swap(ARR[2*ind],ARR[ind]);
        
    return t;
}
void display(){
    
    for(int i=1;i<ARR.size();i++){
        cout<<ARR[i].id<<' '<<ARR[i].p<<'\n';
    }
}
int main(int argc, char const *argv[]){
    ARR.pb(job(-1,-1));
    int ch;
    job t;
    int id,p;
    while(1){
        cout<<"1. Extract Max\n";
        cout<<"2. Get Max\n";
        cout<<"3. Insert a job\n";
        cin>>ch;
        switch(ch){
            case 1:
                t = extractMax();
                cout<<"JOB EXTRACTED. HEAP MODIFIED\n";
                cout<<t.id<<' '<<t.p<<"\n\n";
                display();
                break;
            case 2:
                t = getMax();
                cout<<t.id<<' '<<t.p<<'\n';
                display();
                break;
            case 3:
                cin>>id>>p;
                insert(id,p);
                cout<<"JOB INSERTED\n";
                display();
                break;
            default:
                break;         
        }
    }
    return 0;
}
