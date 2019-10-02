#include<bits/stdc++.h>
using namespace std;
#define Mod 1000000007
long int factorial(int M)
{
  long int ans=1;
  for(int i=M;i>=1;i--)
  {
    ans=(ans*i)%Mod;
    
  }
  return ans;
}
int main()
{
  int N,M;
  cin>>N>>M;
  cout<<factorial(M);
 
}