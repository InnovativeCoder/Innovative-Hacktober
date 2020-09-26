"""
Original by Nooras Fatima Ansari
Modified by Tarun M
BFS ALGORITHM
"""
# the global graph is hardcoded, but it can be taken as input
graph = {'A': ['B', 'C', 'D'],
         'B': ['E', 'F', 'G'],
         'C': ['H', 'I', 'J'],
         'D': ['K', 'L'],
         'E': ['M', 'N'],
         'F': ['O', 'P'],
         'G': ['Q'],
         'H': ['R'],
         'I': ['S'],
         'J': [' ']
        } 

def bfs(graph, start, goal):
    close = []
    open = [start] 
    #open = [A]
    while open:
    	#print(open)  
    	element = open.pop(0) 
      # element = 'A'
    	if element == goal:   
            # element ==  'I' 
            close.append(element)
            print("Particular goal found")
            break
    	if element not in close: 
            close.extend(element)  
            #close = ['A']
            neighbours = graph[element] 
            #neighbours = ['B','c','D']
            for neighbour in neighbours:
                if neighbour != ' ':  
                    #neighbour ('B') !=  ' '
                    open.extend(neighbour) 
                    #open = ['B'] so on ...
    return close
    
if __name__ == '__main__':
    print(bfs(graph,'A','I'))

'''
Output:-
Particular goal found
['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I']
'''
