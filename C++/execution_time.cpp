#include <algorithm> 
#include <chrono> 
#include <iostream> 
#include <ctime>
#include <bits/stdc++.h> 
using namespace std; 
using namespace std::chrono; 
  
// For demonstration purpose, we will fill up 
// a vector with random integers and then sort 
// them using sort function. We fill record 
// and print the time required by sort function 

void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
  
// A function to implement bubble sort  
void bubbleSort(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)     
      
    // Last i elements are already in place  
    for (j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
            swap(&arr[j], &arr[j+1]);  
}  
  
/* Function to print an array */
void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
} 

int main() 
{ 
	 // Call the function, here sort() 
    int arr[100];
    srand((unsigned)time(NULL));
    for (int i = 1; i < 100; i++) {
        arr[i] = 1 + rand() % 10;
    }
    int n = sizeof(arr)/sizeof(arr[0]);    
    // Get starting timepoint 
    auto start = high_resolution_clock::now(); 
    bubbleSort(arr, n);  
    // Get ending timepoint 
    auto stop = high_resolution_clock::now(); 
  
    // Get duration. Substart timepoints to  
    // get durarion. To cast it to proper unit 
    // use duration cast method 
    auto duration = duration_cast<microseconds>(stop - start); 
    cout<<"Sorted array: \n";  
    printArray(arr, n);  
  
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl; 
  
    return 0; 
} 