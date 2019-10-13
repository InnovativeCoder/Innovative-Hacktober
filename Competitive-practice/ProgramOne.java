import java.util.Scanner;

/*
PROBLEM STATEMENT

Given an unsorted array A of size N of non-negative integers, find a continuous sub-array which adds to a given number S.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. The first line of each test case is N and S, where N is the size of array and S is the sum. The second line of each test case contains N space separated integers denoting the array elements.

Output:
For each testcase, in a new line, print the starting and ending positions(1 indexing) of first such occuring subarray from the left if sum equals to subarray, else print -1.

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= Ai <= 1010

Example:
Input:
2
5 12
1 2 3 7 5
10 15
1 2 3 4 5 6 7 8 9 10
Output:
2 4
1 5
*/

class ProgramOne {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int testCase = scan.nextInt();
		while(testCase>0){
			int arraySize = scan.nextInt();
			int sumReqd = scan.nextInt();
			int[] inputArr = new int[arraySize];
			for(int val=0;val<inputArr.length;val++){
				inputArr[val] = scan.nextInt();
			}
			findSolution(inputArr,sumReqd);
			testCase--;
		}
	}
	private static void findSolution(int[] arr,int sum){
		int front=1;
		int back=0;
		int localSum=arr[back]+arr[front];
		while(front<arr.length){
			if(localSum<sum){
				if(front<arr.length-1){
					front++;
				}else
				{
					System.out.println(-1);
					break;
				}
				localSum=localSum+arr[front];
			}else if(localSum>sum){
				localSum=localSum-arr[back];
				back++;
			}else{
				System.out.println((back+1) + " " + (front+1));
				break;
			}
		}
	}
}