#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int D,Oc,Of,Od,Cs,Cb,Cm,Cd;
    cin>>D>>Oc>>Of>>Od>>Cs>>Cb>>Cm>>Cd;
    long int Cost1=Oc+(D-Of)*Od;
    long int Cost2=Cb+(D/Cs)*Cm+D*Cd;
    if(Cost2<Cost1)
    cout<<"Classic Taxi\n";
    else
    cout<<"Online Taxi\n";
}