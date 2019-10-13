#include<stdio.h>

void main(){
    int a[] ={10,9,8,7,6,5,4,3,2,1};
    int b[11];
    int i,j ,key;
    for( i= 1 ; i <10;i++){
        j=i-1;
        key= a[i];
        while(key< a[j] && j>=0){
            a[j + 1] = a[j];  
            j--;
        }
        a[j+1]= key;

    }
    for( i=0 ; i< 10 ; i++){
        printf("%d ",a[i]);
    } 
}
