#include <bits/stdc++.h>
#include <string.h>
using namespace std;
typedef unsigned long long int ull;
ull catalan(ull n){
	if(n<=1){
		return 1;
	}
	ull res=0;
	for(ull i=0;i<n;i++){
		res+=(catalan(i)*catalan(n-i-1));
	}
	return res;
}
int main(){
	for(ull i=0;i<10;i++){
		cout<<catalan(i)<<" ";
	}
	cout<<endl;
	return 0;
}