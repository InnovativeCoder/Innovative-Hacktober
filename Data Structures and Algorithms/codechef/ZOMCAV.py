# cook your dish here
# Python3 code to demonstrate Difference Array 
  
# Creates a diff array D[] for A[] and returns 
# it after filling initial values.
def zerolistmaker(n):
    listofzeros = [0] * n
    return listofzeros
def initializeDiffArray( A): 
    n = len(A) 
  
    # We use one extra space because 
    # update(l, r, x) updates D[r+1] 
    D = [0 for i in range(0 , n + 1)] 
  
    D[0] = A[0]; D[n] = 0
      
    for i in range(1, n ): 
        D[i] = A[i] - A[i - 1] 
    return D 
  
  
# Does range update 
def update(D, l, r, x): 
  
    D[l] += x 
    D[r + 1] -= x 
  
  
# Prints updated Array 
def printArray(A, D): 
  
    for i in range(0 , len(A)): 
        if (i == 0): 
            A[i] = D[i] 
  
        # Note that A[0] or D[0] decides 
        # values of rest of the elements. 
        else: 
            A[i] = D[i] + A[i - 1]
    return(A)
def areEqual(arr1, arr2, n, m): 
  
    # If lengths of array are not  
    # equal means array are not equal 
    if (n != m): 
        return False; 
  
    # Sort both arrays 
    arr1.sort(); 
    arr2.sort(); 
  
    # Linearly compare elements 
    for i in range(0, n - 1): 
        if (arr1[i] != arr2[i]): 
            return False; 
  
    # If all elements were same. 
    return True;
t=int(input())
for i in range(t):
    F=[]
    R=[]
    n=int(input())
    c=[]
    rl=[]
    c=[int(x) for x in input().split()]
    rl=[int(x) for x in input().split()]
    R=zerolistmaker(n)
    
    D = initializeDiffArray(R)
    for j in range(n):
        l=j-c[j]+1
        if(l<1):
            l=1
        l=l-1
        r=j+c[j]+1
        if(r>n):
            r=n
        r=r-1
        update(D,l,r,1)
    F=printArray(c,D)
    if(areEqual(F,rl,n,n)):
       print("YES")
    else:
        print("NO")
    
    
        
   
