//https://www.hackerrank.com/contests/projecteuler/challenges/euler002/problem

//Author - sumit_011


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ll long long int
#define int ll

const int N=1e5;
int fib[N];

void fibonacci(){
    fib[0]=1;
    fib[1]=2;
    rep(i,2,N){
        fib[i]=fib[i-1]+fib[i-2];
    }
}


signed main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    fibonacci(); 
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        int sum=0;
        int id=1;
        while(fib[id]<n){
            sum+=fib[id];
            id=id+3;
        }
        cout<<sum<<"\n";
    }
}
