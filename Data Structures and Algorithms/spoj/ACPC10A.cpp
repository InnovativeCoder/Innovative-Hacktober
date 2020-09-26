#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,s;
    while(cin>>a>>b>>c){
        if((a==0)&&(b==0)&&(c==0)){
            break;
        }
        else{
            s = b - a;
            if(s==c-b){
                cout<<"AP "<<s+c<<"\n";
            }
            else{
                cout<<"GP "<<c*(b/a)<<"\n";
            }
        }
    }
    return 0;
}
