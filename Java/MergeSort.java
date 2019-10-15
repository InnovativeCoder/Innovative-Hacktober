//Program to sort elements using Mergesort

public class MergeSort {
	
	void sort(int arr[], int left, int right) 
	{ 
		if (left < right) 
		{ 
			
			int mid = (left+right)/2; 

			sort(arr, left, mid);  //Sort both the halves
			sort(arr , mid+1, right); 

			merge(arr, left, mid, right); //Merge the sorted halves
		} 
	} 
	void merge(int arr[], int l, int m, int h) 
	{ 
		
		int n1 = m - l + 1; //Calculate size of both the arrays
		int n2 = h - m; 

	
		int L[] = new int [n1]; 
		int R[] = new int [n2]; 

		for (int i=0; i<n1; ++i) 
			L[i] = arr[l + i]; 
		for (int j=0; j<n2; ++j) 
			R[j] = arr[m + 1+ j]; 

		int i = 0, j = 0; 
		int k = l;
		
		while (i < n1 && j < n2) //Copy the smallest element into arr[]
		{ 
			if (L[i] <= R[j]) 
			{ 
				arr[k] = L[i]; 
				i++; 
			} 
			else
			{ 
				arr[k] = R[j]; 
				j++; 
			} 
			k++; 
		} 

		//Copy remaining elements of L[] if present
		while (i < n1) 
		{ 
			arr[k] = L[i]; 
			i++; 
			k++; 
		} 

		//Copy remaining elements of R[] if present
		while (j < n2) 
		{ 
			arr[k] = R[j]; 
			j++; 
			k++; 
		} 
	} 

	static void display(int arr[]) 
	{ 
		int n = arr.length; 
		for (int i=0; i<n; ++i) 
			System.out.print(arr[i] + " "); 
	} 
	
	public static void main(String[] args) {
		int arr[] = {15, 11, 10, 5, 2, 7}; 

		System.out.println("Input array:"); 
		display(arr); 

		MergeSort obj = new MergeSort(); 
		obj.sort(arr, 0, arr.length-1); 

		System.out.println("\nSorted array:"); 
		display(arr); 

	}
  
}

 /*Output
  Input array:
  15 11 10 5 2 7 
  Sorted array:
  2 5 7 10 11 15 
  */
