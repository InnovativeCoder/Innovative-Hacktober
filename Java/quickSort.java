import java.util.Scanner;
class QuickSort {
    public static void main(String[] args) {
        System.out.println("Enter the total number of numbers you want to sort");
        Scanner obj = new Scanner(System.in);
        int n = obj.nextInt();
        int arr[] = new int[n];
        for(int i=0;i<n;i++)
            arr[i] = obj.nextInt();
        Sort sort = new Sort();
        sort.quickSort(arr,0,n-1);
        obj.close();
        for(int i=0;i<n;i++)
            System.out.print(arr[i] + " ");
            System.out.println();
    }
}
class Sort {
    public void quickSort(int arr[], int s, int e) {
        if(s<e) {
            int p = partition(arr,s,e);
            quickSort(arr,s,p-1);
            quickSort(arr,p+1,e);
        }
    }
    public int partition(int arr[],int s, int e) {
        int i=s,pivot=arr[e],temp;
        for(int j=s;j<=e;j++) {
            if(arr[j]<=pivot) {
                temp=arr[i];
                arr[i++]=arr[j];
                arr[j]=temp;
            }
        }
        return (i-1);
    }
}