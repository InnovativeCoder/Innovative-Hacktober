#Name : Nooras Fatima Ansari
#DFS ALGORITHM
graph = {'A': ['B','C','D'],
         'B': ['E','F'],
         'C': ['G','H'],
         'D': ['I','J'],
         'E': [' '],
         'F': [' '],
         'G': [' '],
         'H': [' '],
         'I': [' '],
         'J': [' ']
        } 

def dfs(graph, start,goal):
    close = []
    open = [start]
 
    while open:
    	#print(open)
    	x = open.pop(0)
    	if x == goal:
            close.extend(x)
            print("Particular goal found")
            break
    	if x not in close:
            close.extend(x)
            neighbours = graph[x]
            temp = []
            for neighbour in neighbours:
                if neighbour != ' ':
                    temp.extend(neighbour)
            temp.extend(open)
            open = temp
    return close
 
print(dfs(graph,'A','H'))

'''
Output:
Particular goal found
['A', 'B', 'E', 'F', 'C', 'G', 'H']
'''
