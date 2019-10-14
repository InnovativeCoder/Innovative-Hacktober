import java.util.Scanner;
/*
PRACTICE PROBLEM: Missing number in array 

Given an array C of size N-1 and given that there are numbers from 1 to N with one element missing, the missing number is to be found.

Input:
The first line of input contains an integer T denoting the number of test cases. For each test case first line contains N(size of array). The subsequent line contains N-1 array elements.

Output:
Print the missing number in array.

Constraints:
1 ≤ T ≤ 200
1 ≤ N ≤ 107
1 ≤ C[i] ≤ 107

Example:
Input:
2
5
1 2 3 5
10
1 2 3 4 5 6 7 8 10

Output:
4
9*/

class ProgramFour {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int testCase = scan.nextInt();
		while(testCase>0){
			int arraySize = scan.nextInt();
			int[] inputArr = new int[arraySize-1];
			for(int val=0;val<inputArr.length;val++){
				inputArr[val] = scan.nextInt();
			}
			int missingNumber = findSolution(inputArr);
			System.out.println(missingNumber);
			testCase--;
		}
	}
	private static int findSolution(int[] arr){
		int sum=0;
		int arrayLength=arr.length;
		for(int i=0;i<arrayLength;i++){
			sum+=arr[i];
		}
		//using (n*n+1)/2
		int actualSum=((arrayLength+1)*(arrayLength+2))/2;
		return actualSum-sum;
	}
}