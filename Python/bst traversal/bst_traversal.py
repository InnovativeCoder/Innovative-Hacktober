class Node(object):
  def __init__(self,value):
    self.value = value
    self.left = None
    self.right = None

class Binary_tree(object):
  def __init__ (self,root):
    self.root = Node(root)
   
  def print_pre_order(self,transversal_type):
    if transversal_type=="preorder":
      return (self.pre_order(tree.root,""))
    if transversal_type=="inorder":
      return (self.in_order(tree.root,""))
    if transversal_type=="postorder":
      return (self.post_order(tree.root,""))
    
  def pre_order(self,start,traversal):
    if start:
      traversal+=str(start.value)+"-"
      traversal=self.pre_order(start.left,traversal)
      traversal=self.pre_order(start.right,traversal)
    return traversal 
  
  def in_order(self,start,traversal):
    if start:
      traversal=self.in_order(start.left,traversal)
      traversal+=str(start.value)+"-"
      traversal=self.in_order(start.right,traversal)
    return traversal
  
  def post_order(self,start,traversal):
    if start:
      traversal=self.post_order(start.left,traversal)
      traversal=self.post_order(start.right,traversal)
      traversal+=str(start.value)+"-"
    return traversal
      
tree=Binary_tree(2)
tree.root.left=Node(1)
tree.root.right=Node(5)
tree.root.left.left=Node(7)
tree.root.left.right=Node(9)
tree.root.right.right=Node(8)
tree.root.right.left=Node(3)
print(tree.print_pre_order("preorder"))
print(tree.print_pre_order("inorder"))
print(tree.print_pre_order("postorder"))