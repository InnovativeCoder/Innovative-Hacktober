#include<stdio.h>
void bubble_sort(int [], int);
int main()
{
    int n,A[50],i;
    printf("Enter number of terms : ");
    scanf("%d",&n);
    printf("Enter Values in array\n");
    for(i=0;i<n;i++)
    {
    	scanf("%d",&A[i]);
    }
    bubble_sort(A,n);
    printf("Sorted Array:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
}

void bubble_sort(int A[],int n)
{
    int temp,i,j,flag;
    for(i=1;i<=n-1;i++)
    {
        flag=0;
        for(j=0;j<=n-1-i;j++)
        {
            if(A[j]>A[j+1])
            {
                flag=1;        //tells one or more checking has been done
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
        if(flag==0) /*if it doesn't enter the if condition even once(indicating that the array is now sorted)return to the main()*/
        return;
    }
}

