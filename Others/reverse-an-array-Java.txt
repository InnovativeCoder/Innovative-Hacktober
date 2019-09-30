// Program to reverse an array in Java
import java.util.Scanner;
class ArrayReverse{
	public static void main(String args[])
	{
		//Take the input

		Scanner scan = new Scanner(System.in); 
		System.out.println("Enter the number of elements:");
		int n = scan.nextInt();
		int arr[] = new int[n];
		System.out.println("Enter the array elements:");
		for(int i=0;i<arr.length;i++)
			arr[i]=scan.nextInt();

		//Swap the elements from the first half of the array with that of the second half

		int temp = 0;
		for(int i=0;i<arr.length/2;i++)
		{
			temp = arr[i];
			arr[i] = arr[arr.length-i-1];
			arr[arr.length-i-1] = temp;
		}
		
		//Display the final array after the swapping operation has been performed		

		System.out.println("Reversed array: ");
		for(int i=0;i<arr.length;i++)
		{
			System.out.println(arr[i] + " ");
		}
	}
}

