#by Tarun M
fibtable = []

def fib(n):
    fibtable.append(0)
    fibtable.append(1)
    for i in range(2,n+1):
    	f = fibtable[i-1]+fibtable[i-2]
    	fibtable.append(f)
    return (fibtable)

if __name__ == '__main__':
  	n = int(input("Enter the number of elements in the series..."))
  	print(fib(n))

