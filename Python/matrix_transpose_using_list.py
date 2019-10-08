r,c=map(int,input("enter number of rows and cols: ").split())
m=[[int(input(f"enter m[{i}][{j}]")) for j in range(c)] for i in range(r)]
print('\n'.join(map(str,m)))

print()
print("transpose")
t=[[row[i] for row in m] for i in range(3)]
print('\n'.join(map(str,t)))
