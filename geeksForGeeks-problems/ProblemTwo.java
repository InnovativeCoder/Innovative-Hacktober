import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;

/*
PROBLEM STATEMENT

Given an array of distinct integers. The task is to count all the triplets such that sum of two elements equals the third element.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. First line of each test case contains an Integer N denoting size of array and the second line contains N space separated elements.

Output:
For each test case, print the count of all triplets, in new line. If no such triplets can form, print "-1".

Constraints:
1 <= T <= 100
3 <= N <= 105
1 <= A[i] <= 106

Example:
Input:
2
4
1 5 3 2
3
3 2 7
Output:
2
-1*/

class ProgramTwo {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int testCase = scan.nextInt();
		while(testCase>0){
			int arraySize = scan.nextInt();
			int[] inputArr = new int[arraySize];
			for(int val=0;val<inputArr.length;val++){
				inputArr[val] = scan.nextInt();
			}
			int count = findSolution(inputArr);
			System.out.println(count);
			testCase--;
		}
	}
	private static int findSolution(int[] arr){
		int count = 0;
		Set<Integer> arraySet = new HashSet<Integer>(arr.length);
		for(int i = 0; i<arr.length ; i++)
		{
			arraySet.add(arr[i]);
		}
		int localSum = 0 ;
		for(int i = 0;i<arr.length;i++){
			for(int j=i+1;j<arr.length;j++){
				localSum = arr[i]+arr[j];
				if(arraySet.contains(localSum)){
					count++;
				}
			}
		}
		if(count == 0){
			count = -1;
		}			
		return count;	
	}	
}