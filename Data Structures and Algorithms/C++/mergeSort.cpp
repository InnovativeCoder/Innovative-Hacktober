#include <iostream>
using namespace std;
void Merge(int a[], int l, int h, int mid)
{
	int i, j, k, c[h-l+1];
	i = l;
	k = 0;
	j = mid + 1;
 
	
	while (i <= mid && j <= h)
	{
		if (a[i] < a[j])
		{
			c[k] = a[i];
			k++;
			i++;
		}
		else
		{
			c[k] = a[j];
			k++;
			j++;
		}
	}
 
	while (i <= mid)
	{
		c[k] = a[i];
		k++;
		i++;
	}
 
	while (j <= h)
	{
		c[k] = a[j];
		k++;
		j++;
	}
 
 
	for (i = l; i <= h; i++)
	{
		a[i] = c[i-l];
	}
}
 
void MergeSort(int a[], int l, int h)
{
	int mid;
	if (l< h)
	{
		mid=(l+h)/2;
		MergeSort(a, l, mid);
		MergeSort(a, mid+1, h);
		Merge(a, l, h, mid);
	}
}
 
int main()
{
	int n, i;
	cout<<"\nEnter the number of data element to be sorted: "<<endl;
	cin>>n;
 
	int arr[n];
	cout<<"Enter element:"<<endl;
	for(i = 0; i < n; i++)
	{
		
		cin>>arr[i];
	}
 
	MergeSort(arr, 0, n-1);
 
	cout<<"\nSorted Data: "<<endl;
	for (i = 0; i < n; i++)
        cout<<arr[i]<<" ";
 
	return 0;
}