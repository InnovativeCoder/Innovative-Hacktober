print("enter the number")
n = int(input())
fibtable = {}
def fib(n):
    fibtable[0] = 0
    fibtable[1] = 1
    for i in range(2,n+1):
        fibtable[i] = fibtable[i-1]+fibtable[i-2]
    return (fibtable[n])
print(fib(n))