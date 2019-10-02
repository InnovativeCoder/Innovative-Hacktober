#include<iostream>
using namespace std;
int main()
{
    int a[100][100],n,m;
    cout<<"Enter the rows and columns of a matrix:"<<endl;
    cin>>m>>n;
    cout<<"Enter the elements of the matrix:"<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    }
    cout<<"The spiral traversal of matrix:"<<endl;
    int i,k=0,l=0;
    while(k<m && l<n)
    {
        for(i=l;i<n;i++)
            cout<<a[k][i]<<" ";
        k++;
        for(i=k;i<m;i++)
            cout<<a[i][n-1]<<" ";
        n--;
        if(k<m)
        {
            for(i=n-1;i>=l;i--)
                cout<<a[m-1][i]<<" ";
        }
        m--;
        if(l<n)
        {
            for(i=m-1;i>=k;i--)
                cout<<a[i][l]<<" ";
        }
        l++;
    }
    return 0;
}
