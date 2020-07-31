# program to identify balance height balanced binary tree - 
#An empty tree is height-balanced. A non-empty binary tree T is balanced if:
#1) Left subtree of T is balanced
#2) Right subtree of T is balanced
#3) The difference between heights of left subtree and right subtree is not more than 1. 
# Author - Ankit Agarwal

class Node:
	def __init__(self,key):
		self.left = None
		self.right = None
		self.val = key


def calHeight(root):
    if root is None:
        return 0
    else:
        return 1+max(calHeight(root.left),calHeight(root.right))


def balance(root):
    if root is None:
        return True
    else:
        lh = calHeight(root.left)
        rh = calHeight(root.right)
        return (abs(lh-rh)<=1 and balance(root.left) and balance(root.right))

# driver code
if __name__ == '__main__':
	root = Node(1)
	root.left = Node(2)
	root.left.left = Node(3)
	root.right = Node(4)
	""" 
	Constructed binary tree is  
				1 
			   / \ 
			  2   4
			 /
			3
	"""
	print(balance(root))
    