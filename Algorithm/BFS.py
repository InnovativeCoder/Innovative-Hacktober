#Name : Nooras Fatima Ansari
#BFS ALGORITHM
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

def bfs(graph, start,goal):
    close = []
    open = [start] #open = [A]
 
    while open:
    	#print(open)  
    	x = open.pop(0) #x = 'A'
    	if x == goal:   #x ==  'I' 
            close.extend(x)
            print("Particular goal found")
            break
    	if x not in close: 
            close.extend(x)  #close = ['A']
            neighbours = graph[x] #neighbours = ['B','c','D']
            for neighbour in neighbours:
                if neighbour != ' ':  #neighbour ('B') !=  ' '
                    open.extend(neighbour) #open = ['B'] so on ...
    return close
 
print(bfs(graph,'A','I'))

'''
Output:
Particular goal found
['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I']
'''
