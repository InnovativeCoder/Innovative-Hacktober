#include<iostream>
#include<algorithm>
using namespace std;
long findocc(long[],long,long);
int main()
{
    long t,i,n,c,j,s,q,r,total,prev,current,qe,re,occurence,m,l,first,second,fs,pi,ci,even,odd;
    cin>>t;
    while(t--)
    {

        q=0;
        r=0;
        c=0;
        cin>>n;
        long a[n];
        long e[n];
        long o[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]%2==0){
                e[q]=a[i];
                q++;}
            else{
                o[r]=a[i];
                r++;}
        }
        sort(e,e+q);
        sort(o,o+r);
        qe=(q*(q-1))/2;
        re=(r*(r-1))/2;
        total=qe+re;
        i=0;
        odd=0;
        even=0;
        while(i<r)
        {
            if(i==0){
            l=findocc(o,o[0],r);
            prev=o[i];
            pi=i;
            i=i+l;
            ci=i;
            current=o[i];
            }

            fs=findocc(o,o[i],r);

            odd=odd+0.5*l*(l-1);

            s=o[pi]^o[ci];
            if(s<=2){
                odd=odd+(l*fs);
            }
            l=fs;
             prev=o[i];
             pi=ci;
            i=i+fs;
            ci=i;
            current=o[i];

            if(i==r){
            odd=odd+0.5*(l*(l-1));
            break;
            }
            }
            j=0;
                    while(j<q)
        {
            if(j==0){
            l=findocc(e,e[0],q);
            prev=e[j];
            pi=j;
            j=j+l;
            ci=j;
            current=e[j];
            }

            fs=findocc(e,e[j],q);

            even=even+0.5*l*(l-1);

            s=e[pi]^e[ci];
            if(s<=2){
                even=even+(l*fs);
            }
            l=fs;
             prev=e[j];
             pi=ci;
            j=j+fs;
            ci=j;
            current=e[j];

            if(j==q){
            even=even+0.5*(l*(l-1));
            break;
            }
            }



            total=total-odd-even;
            cout<<total<<endl;
    }
}
long findocc(long arr[], long x, long n)
{
  /* get the index of first occurrence of x */
  long *low = lower_bound(arr, arr+n, x);

  // If element is not present, return 0
  if (low == (arr + n) || *low != x)
     return 0;

  /* Else get the index of last occurrence of x.
     Note that we  are only looking in the
     subarray after first occurrence */
  long *high = upper_bound(low, arr+n, x);

  /* return count */
  return high - low;
}




