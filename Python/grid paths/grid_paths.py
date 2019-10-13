#This code finds all the path starting from lower left corner(0,0) to  upper right corner (i,j)
table=[]
print("enter the index of i and j of topmost right corner respectively")
a,b = input().split()
def path(m,n):
    table = [[0 for x in range(m+1)] for y in range(n+1)] 
    table[0][0] = 1
    for i in range(0,m+1):
        table[0][i] = 1
    for j in range(0,n+1):
        table[j][0] = 1
    for i in range(1,m+1):
        for j in range(1,n+1):
            table[j][i]=table[j][i-1]+table[j-1][i]
    return(table[n][m])
print("number of paths",path(int(a),int(b)))
