#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;
void swap(int *i,int *j)
{
    int t=*i;
    *i=*j;
    *j=t;
}
int partion(int A[],int p,int r)
{
    int x=A[r];
    int i= p-1;
    for(int j=p;j<r;j++)
    {
        if(A[j]<A[r])
        {
            i=i+1;
            swap(&A[i],&A[j]);
        }
    }
    swap(&A[i+1],&A[r]);
    return(i+1);
}
void QuickSort(int A[],int p,int r)
{
    if(p<r)
    {
        int q=partion(A,p,r);
        QuickSort(A,p,q-1);
        QuickSort(A,q+1,r);
    }
}
int main()
{
    int A[]={4,3,1,2,5,10,3,7,9};
    int size=sizeof(A)/sizeof(A[0]);
    auto start=high_resolution_clock::now();
    QuickSort(A,0,size-1);
    auto stop=high_resolution_clock::now();
    for(int i=0;i<size;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<"\n";
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<"Time taken by Quicksort: "
        <<duration.count()<< "microseconds";

}