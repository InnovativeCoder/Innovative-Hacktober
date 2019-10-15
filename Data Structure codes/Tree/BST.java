/*
Program to perform operations such as 
minimum and maximum,Display tree levelwise ,find height of tree on Binary search tree.
*/
import java.util.*;

 class node {
	int data;
	node left;
	node right;
	
	node(int d){
		data=d;
		left=right=null;
	}
}
 
public class bst 
{
	int j=0;
	static node root;
	bst()
	{
		root=null;
	}
	void inorder(node localroot) {       //Display tree-Inorder
		if(localroot!=null)
		{
		inorder(localroot.left);
		System.out.println(localroot.data);
		inorder(localroot.right);
		}
	}
	
	void desc(node localroot) {              //Display tree in descending order
		Stack<node> o=new Stack<node>();
		node ptr=root;
		while(true)
		{
			while(ptr!=null)
				{
					
					o.push(ptr);				
					ptr=ptr.right;
				}
			if(o.isEmpty())
			{ 
				return;
			}
			else
			{
	
			ptr=o.pop();
			System.out.println(ptr.data);
			ptr=ptr.left;
			}
		}
	}	
	

void create() {                       //Creating BInary Search Tree
	int d;
	System.out.println("Enter the data");
	Scanner in=new Scanner(System.in);
	d=in.nextInt();
	node temp=new node(d);
	int flag=0;
	if(root==null)
	{
		root=temp;
		
	}
else {
	node ptr=root;
	while(flag==0)
	{
		
		
		flag=0;
		if(ptr.data>temp.data)
		{			
			
			if(ptr.left!=null)
			{
				
			ptr=ptr.left;	
			}
			else {				

				
				ptr.left=temp;
				flag=1;
			}
		}
		else if(ptr.data<temp.data)
			{
				if(ptr.right!=null)
				{
				ptr=ptr.right;	
				}
				else {
					ptr.right=temp;
					flag=1;
				}
			}
	}
	
	}
   }
void min()         //Finding Minimum Element
{
	node p=root;
	while(p.left!=null)
	{
		p=p.left;
	}
	if(p.left==null)
	{
		System.out.println("\nMinimum element: "+p.data+"\n");
	}
}
void max()         //Finding Maximum Element
{
	node p=root;
	while(p.right!=null)
	{
		p=p.right;
	}
	if(p.right==null)
	{
		System.out.println("\nMaximum element: "+p.data+"\n");
	}
}

int height(node ptr)       //Calculate height of tree
{
    if (ptr == null) 
            return 0; 
        else 
        { 
            int lDepth = height(ptr.left); 
            int rDepth = height(ptr.right); 
            if (lDepth > rDepth) 
                return (lDepth + 1); 
             else 
                return (rDepth + 1); 
        }  
             
}

void height1()
{
    System.out.println("Height of tree is : " +height(root));
}


void level()    //Display tree levelwise
{
	Queue <node> q=new LinkedList<node>();
	System.out.println("\nLevelwise Display:\n");
	node p=root;
	while(p!=null)
	{
		System.out.println(p.data);
		if(p.left!=null)
		{
			q.add(p.left);
		}
		 if(p.right!=null)
		{
			q.add(p.right);
		}
		 if(q.isEmpty())
		 {
			 p=null;
		 }
		 else
		 {
			 p=q.remove();
		 }
	}
}

node copy(node lr)     //Creating copy of tree
{
	if(lr==null)
	{
		return null;
	}
	else
	{
	
	node temp=new node(lr.data);
	
		if(lr.left!=null)
		{
			temp.left=copy(lr.left);
		}
		if(lr.right!=null)
		{
			temp.right=copy(lr.right);
		}
		return temp;
	}
	
}
void copynode(node r)
{
	node pt=copy(r);
	System.out.println("\nTree Copied:\n");
	 Stack<node> o=new Stack<node>();
		
	while(true)
	{
		while(pt!=null)
			{
				
				o.push(pt);				
				pt=pt.left;
			}
		if(o.isEmpty())
		{ 
			return;
		}
		else
		{

		pt=o.pop();
		System.out.println(pt.data);
		pt=pt.right;
		}
	}
}



public static void main(String args[])
{
	bst obj=new bst();
	
	while(true){
		System.out.println("\n--Menu--\n");
		System.out.println("Enter choice \n1.Create tree \n2.Display \n3.Find Minimum \n4.Find Maximum \n5.Display tree levelwise \n6.Display in descending order \n7.Find height of tree\n8.Copy Tree\n");
		Scanner in=new Scanner(System.in);
		int c=in.nextInt();				
		switch(c)
		{
		case 1:
			obj.create();
			break;
		case 2:
			System.out.println("\nDisplay tree InOrder wise\n");
			obj.inorder(root);
			break;
		case 3:
			obj.min();
			break;
		case 4:
			obj.max();
			break;
		case 5:
			obj.level();
			break;
		case 6:
			System.out.println("\nDescending Order Display\n");
			obj.desc(root);
			break;
		case 7:
			obj.height1();
			break;
		case 8:
			obj.copynode(root);
			break;
		
		}
	}
}

}
/*Output

--Menu--

Enter choice 
1.Create tree 
2.Display 
3.Find Minimum 
4.Find Maximum 
5.Display tree levelwise 
6.Display in descending order 
7.Find height of tree
8.Copy Tree

1
Enter the data
10

--Menu--

Enter choice 
1.Create tree 
2.Display 
3.Find Minimum 
4.Find Maximum 
5.Display tree levelwise 
6.Display in descending order 
7.Find height of tree
8.Copy Tree

2

Display tree

10

--Menu--

Enter choice 
1.Create tree 
2.Display 
3.Find Minimum 
4.Find Maximum 
5.Display tree levelwise 
6.Display in descending order 
7.Find height of tree
8.Copy Tree

1
Enter the data
9

--Menu--

Enter choice 
1.Create tree 
2.Display 
3.Find Minimum 
4.Find Maximum 
5.Display tree levelwise 
6.Display in descending order 
7.Find height of tree
8.Copy Tree

1
Enter the data
6

--Menu--

Enter choice 
1.Create tree 
2.Display 
3.Find Minimum 
4.Find Maximum 
5.Display tree levelwise 
6.Display in descending order 
7.Find height of tree
8.Copy Tree

1
Enter the data
12

--Menu--

Enter choice 
1.Create tree 
2.Display 
3.Find Minimum 
4.Find Maximum 
5.Display tree levelwise 
6.Display in descending order 
7.Find height of tree
8.Copy Tree

2

Display tree

6
9
10
12

--Menu--

Enter choice 
1.Create tree 
2.Display 
3.Find Minimum 
4.Find Maximum 
5.Display tree levelwise 
6.Display in descending order 
7.Find height of tree
8.Copy Tree

3

Minimum element: 6


--Menu--

Enter choice 
1.Create tree 
2.Display 
3.Find Minimum 
4.Find Maximum 
5.Display tree levelwise 
6.Display in descending order 
7.Find height of tree
8.Copy Tree

4

Maximum element: 12


--Menu--

Enter choice 
1.Create tree 
2.Display 
3.Find Minimum 
4.Find Maximum 
5.Display tree levelwise 
6.Display in descending order 
7.Find height of tree
8.Copy Tree

5

Levelwise Display:

10
9
12
6

--Menu--

Enter choice 
1.Create tree 
2.Display 
3.Find Minimum 
4.Find Maximum 
5.Display tree levelwise 
6.Display in descending order 
7.Find height of tree
8.Copy Tree

6

Descending Order Display

12
10
9
6

--Menu--

Enter choice 
1.Create tree 
2.Display 
3.Find Minimum 
4.Find Maximum 
5.Display tree levelwise 
6.Display in descending order 
7.Find height of tree
8.Copy Tree

7
Height of tree is : 3

--Menu--

Enter choice 
1.Create tree 
2.Display 
3.Find Minimum 
4.Find Maximum 
5.Display tree levelwise 
6.Display in descending order 
7.Find height of tree
8.Copy Tree

8
No of nodes are: 4

--Menu--

Enter choice 
1.Create tree 
2.Display 
3.Find Minimum 
4.Find Maximum 
5.Display tree levelwise 
6.Display in descending order 
7.Find height of tree
8.Copy Tree

9

Tree Copied:

6
9
10
12

*/
