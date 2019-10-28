def combin(n,r):
  t = 0
	for i in range(1,r+1):
    t *= (n-i+1)/i
  return t
  
if __name__ == '__main':
  n = int(input("Enter the value of n..."))
  r = int(input("Enter the value of r..."))
  print("The nCr value is ",combin(n,r))
  
  
