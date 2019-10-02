public class LargestSumSubarray{
	public static void main(String[] args) {
		
		int a[] = {-3, 4, 6, -5, 1, -2, 3, -7};
		int len = a.length;


		//Big-O(n^3) Solution
		int maxSum = Integer.MIN_VALUE; //assigns least possible value


		//Finding all subarrays via nested loops
		for (int i=0;i<len ;i++) 
		{
			for (int j =i;j<len ;j++) 
			{
				int curSum = 0;
				for (int k=i;k<j ;k++) 
				{
					curSum += a[k];

				}//loop3

				//reassigning sum if a subarray with larger sum is found
				if(curSum > maxSum)
				{
					maxSum = curSum;
				}

			}//loop2
			
		}//loop1

		System.out.println("The Big-O(n^3) Solution : " + maxSum);
		System.out.println();



		
		//Big-O(n^2) Solution

		/*Pre processed array to store the sum of sub array from
		  element 0 till i-th element
		  Example : 

		  int a[] = {-1, 4, -2, 4, -1, 3, 5, -6};
					
		  int processed[] = {-1, 3, 1, 5, 4, 7, 11, 5}
		   
		  Hence we can generalize that

		  Sum of sub array from i to j index is given by

		  sum = processed[j] - processed[i] + a[i]

		*/		
		int maxSum2 = Integer.MIN_VALUE; //assigns least possible value


		//Pre-processing code

		int processed[] = new int[len]; //taking empty pre processed array
		processed[0] = a[0];
		for (int i=1;i<len;i++) 
		{
			processed[i] = processed[i-1] + a[i];
		}


		//Finding maxSum

		for (int i=0; i<len; i++) 
		{
			for (int j=i; j<len; j++) 
			{
				int curSum = processed[j] - processed[i] + a[i];
				//reassigning sum if a subarray with larger sum is found
				if(curSum > maxSum2)
				{
					maxSum2 = curSum;
				}

			}//loop2
			
		}//loop1

		System.out.println("The Big-O(n^2) Solution : " + maxSum2);
		System.out.println();



		//Big-O(n) Solution  Using Kaden's Algorithm

		int currentSum = 0;
		int maxSum3 = Integer.MIN_VALUE; //assigns least possible value

		for (int i=0; i<len; i++) 
		{
			currentSum += a[i];

			if(currentSum > maxSum3)
			{
				maxSum3 = currentSum;
			}

			if(currentSum < 0)
			{
				currentSum = 0;
			}
		}

		System.out.println("The Big-O(n) Solution : " + maxSum3);
		System.out.println();



	}
}
