#include<iostream>
using namespace std;
int main()
{
    int a[100][100],m,n,i,j,size=0;
    cout<<"Enter the number of rows and columns of a sparse matrix:"<<endl;
    cin>>m>>n;
    cout<<"Enter the elements:"<<endl;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
           {
               cin>>a[i][j];
               if(a[i][j]!=0)
               size++;

           }
    }
    cout<<"Sparse matrix representation:"<<endl;
    int b[3][size],k=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]!=0)
            {
                b[0][k]=i;
                b[1][k]=j;
                b[2][k]=a[i][j];
                k++;
            }
        }
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<size;j++)
            cout<<b[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
