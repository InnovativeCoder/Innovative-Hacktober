#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    string a,b;
    cin>>a>>b;
    int l1 = a.size();
    int l2 = b.size();

    if(l2<l1)
        cout<<"-1";
    else{
        bool oneMatch = true;
        for(int i=0;i<=l1-l2;i++){
            int j;
            int temp = i;
            for(j=0;j<l2;j++){
                if(a[temp]!=b[j])
                    break;
                temp++;
            }
            if(j==l2){
                oneMatch = 0;
                cout<<i<<' ';
            }
        }
    }
    if(oneMatch)
        cout<<-1;
    return 0;
}
