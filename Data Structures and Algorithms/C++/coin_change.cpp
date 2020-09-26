#include <bits/stdc++.h>
#include <string.h>
using namespace std;
int count(int ar[],int m,int n){
	if(n==0){
		return 1;
	}

	if(n<0){
		return 0;
	}

	if(m<=0&&n>=1){
		return 0;
	}

	return count(ar,m-1,n)+count(ar,m,n-ar[m-1]);
}
int main(){
	// number of ways we can make coin change for given currency
	int arr[]={1,2,3};
	int size_of_arr=3;
	int currency=4;
	cout<<count(arr,size_of_arr,currency)<<endl;
}