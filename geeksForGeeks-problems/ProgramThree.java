import java.util.Scanner;

/*
PROBLEM STATEMENT

Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a single integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print the maximum sum of the contiguous sub-array in a separate line for each test case.

Constraints:
1 ≤ T ≤ 110
1 ≤ N ≤ 106
-107 ≤ A[i] <= 107

Example:
Input
2
5
1 2 3 -2 5
4
-1 -2 -3 -4
Output
9
-1*/

class ProgramThree {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int testCase = scan.nextInt();
		while(testCase>0){
			int arraySize = scan.nextInt();
			int[] inputArr = new int[arraySize];
			for(int val=0;val<inputArr.length;val++){
				inputArr[val] = scan.nextInt();
			}
			int maxSum = findSolution(inputArr);
			System.out.println(maxSum);
			testCase--;
		}
	}
	private static int findSolution(int[] arr){
		int localSum = arr[0];	
		int globalSum = localSum;
		for(int i = 1;i < arr.length; i++){
			localSum+=arr[i];
			if(localSum<arr[i]){
				localSum=arr[i];
			}
			if(globalSum<localSum){
				globalSum=localSum;
			}
		}
		return globalSum;
	}
}