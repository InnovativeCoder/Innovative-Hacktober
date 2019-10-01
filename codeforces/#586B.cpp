#include<bits/stdc++.h>
 
using namespace std;
 
int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
  
// Function to find gcd of array of 
// numbers 
int findGCD(int arr[], int n) 
{ 
    int result = arr[0]; 
    for (int i = 1; i < n; i++) 
        result = gcd(arr[i], result); 
  
    return result; 
} 
 
int main()
{
    long long int n,ap,bp,abo,ao,l;
    cin>>n;
    long long int arr[n][n];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    
    int answer[n];
    int aloo[n];
    
    for(int i=0;i<n;i++){
    	aloo[i]=arr[0][i];
	}
    ap=findGCD(aloo, n);
    bp=(ap*arr[1][n-1])/arr[0][n-1];
    
    abo=arr[0][1];
    l=sqrt((ap*bp)/abo);
    ao=ap/l;
    answer[0]=ao;
    for(int i=1;i<n;i++)
    {
        answer[i]=arr[0][i]/ao;
    }
    for(int i=0;i<n;i++)
    {
        cout<<answer[i]<<" ";
    }
 
    return 0;
}
