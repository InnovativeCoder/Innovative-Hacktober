#include <iostream> 
using namespace std; 

//function to sort the array
void selectionSort(int a[], int n)  
{  
    int min,t,i,j,index=j;
    for(int j=0;j<n;j++)
    {
        min=a[j];
        for(int i=j+1;i<n;i++)
        {
            if(a[i]<min)
            {
                min=a[i];
                index=i;
            }
            t=a[j];
            a[j]=a[index];
            a[index]=t;
        }
    }
} 

//Printing the array
void printArray(int a[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << a[i] << " ";  
    cout << endl;  
}  
  
//main function 
int main()  
{  
    int n,i;
    cout<<"---SELECTION SORT---"<<endl;
    cout<<"Enter the no of elements:"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the array elements:"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    selectionSort(a,n);  
    cout<<"Sorted array: \n";  
    printArray(a,n);  
    return 0;  
}  
