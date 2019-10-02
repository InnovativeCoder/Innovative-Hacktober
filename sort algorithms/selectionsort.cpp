#include<iostream>
using namespace std;
void selectionsort(int arr[],int n){
    for (int i=0;i<n-1;i++){
        int min=arr[i],minindex=i,temp;
        for(int j=i;j<n;j++){
            if(min>arr[j]){
                min=arr[j];
                minindex=j;
            }
        }
        //swap
        temp=arr[i];
        arr[i]=arr[minindex];
        arr[minindex]=temp;
    }
}
int main(){
    int arr[]={7,6,5,4,3,2,1};
    selectionsort(arr,7);
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
}
