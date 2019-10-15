import java.util.Scanner;
class MergeSort {
	public static void main(String[] args) {
		Scanner sobj = new Scanner(System.in);
		System.out.println("Enter the total number of numbers you want to sort");
		int n = sobj.nextInt();
		int arr[] = new int[n];
		for(int i=0;i<n;i++) {
			arr[i] = sobj.nextInt();
		}
		sobj.close();
	   	Sort sort = new Sort();
		sort.mergeSort(arr,0,n-1);
		for(int i=0;i<n;i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
	}
}
class Sort {
	public void mergeSort(int arr[], int x, int n) {
		if(x<n) {
			mergeSort(arr, x, (x+n)/2);
			mergeSort(arr, (x+n)/2+1, n);
			merge(arr, x, n);
		}
	}
	public void merge(int arr[], int init, int n) {
		int x1 = init;
		int x2 = (init+n)/2+1;
		int x = init;
		int arr2[] = arr.clone();
		while (x1 < (init+n)/2+1 && x2 <= n) {
			if(arr2[x1] < arr2[x2]) {
				arr[x++] = arr2[x1++];
			}
			if(arr2[x2] < arr2[x1]) {
				arr[x++] = arr[x2++];
			}
		}
		while(x1<(init+n)/2+1) {
			arr[x++]=arr2[x1++];
		}
		while(x2<=n) {
			arr[x++]=arr2[x2++];
		} 
	}
}

