# Python program for implementation of Selection Sort
 
import sys 
n = input("Enter elements:")
A=n.split()
# Traverse through all array elements 
for i in range(len(A)): 
	
	# Find the minimum element in remaining unsorted array 
	min_idx = i 
	for j in range(i+1, len(A)): 
		if A[min_idx] > A[j]: 
			min_idx = j 
			
	# Swap the found minimum element with the first element	
	if min_idx != i:
	    A[i], A[min_idx] = A[min_idx], A[i] 

# Driver code to test above 
print ("Sorted array:") 
for i in range(len(A)): 
	print(A[i]) 

