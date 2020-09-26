/*

	Title	:	To implement binary search tree and perform operations on it.
	
*/

import java.util.*;

class node
{
	int data;
	node lc;
	node rc;
	
	node(int d)
	{
		data=d;
		lc=null;
		rc=null;
	}
}

class BST
{
	Scanner sc=new Scanner(System.in);
	node root;
	int count=0;
	node temp,ptr;
	 
 
	BST()
	{
		root=null;
	}
	 
	void create()
	{

	    int flag=0,data;
	    char ch;

	    do
		{
			flag=0;
			
		    System.out.println("Enter the value for node : ");
		    data=sc.nextInt();
		    temp=new node(data);
			
			if(root==null)
			{		 
		  		root=temp;
		  		flag=1;
			}
			else
			{
			   ptr=root;
	   
			    while(flag==0)
			    {

			        if(temp.data<ptr.data)
			        {
				        if(ptr.lc==null)
				        {
				            ptr.lc=temp;
				            flag=1;				          
				        }
				        else
				        {
				            ptr=ptr.lc;				           
				        }

			        }
			        else if(temp.data>ptr.data)
			        {
			            if(ptr.rc==null)
			            {			               
			                ptr.rc=temp;
			                flag=1;			               
			            }
			            else
			            {
			                ptr=ptr.rc;			               
			            }   
			       
			        }
			        else
			        {
			        	System.out.println("Node already exist!");
						break;
			        }
			    }
			}

			if(flag==1)
				System.out.println("Node inserted!");
			
			
			System.out.println("\n\nDo you want to continue creating? (Y/N)");
			ch=sc.next().charAt(0);
			
		}while(ch=='y'||ch=='Y');

	}
 
	void display()
	{
	   
	    if(Empty())
			return;
		
	    node ptr=root;
		Stack<node> s=new Stack<node>();
		
		while(true)
		{
			while(ptr!=null)
			{
				s.push(ptr);
				ptr=ptr.lc;
			}
			
			if(s.isEmpty())
				break;
			
			ptr=s.pop();
			System.out.println(ptr.data);
			ptr=ptr.rc;			
			
		}
	   
	}
	 
	void levelOrder()
	{
		if(Empty())
			return;
		
	    Queue<node> q=new LinkedList<node>();
	  
	    ptr=root;
		
	    while(true)
	    {
		    System.out.print(ptr.data+" ");
			
	        if(ptr.lc!=null)
	        {
	      		q.add(ptr.lc);
	        }
	        if(ptr.rc!=null)
	        {
	            q.add(ptr.rc);
	        }
	        if(q.isEmpty())
	        {
	            break;
	        }
	        else
	        {
	            ptr=q.remove();
	           
	        }
	    }
	     
	}

	void findMaxMin()
	{
		if(Empty())
			return;
		
		ptr=root;
		while(ptr.lc!=null)
		{
			ptr=ptr.lc; 
		}
		System.out.println("Minimum node is : "+ptr.data);
	   
	   
		ptr=root;
		while(ptr.rc!=null)
		{
			ptr=ptr.rc;
		}
		
		System.out.println("Maximum node is : "+ptr.data);


	}


	void descorder()
	{
		if(Empty())
			return;
		
	    Stack<node> s=new Stack<node>();
	    ptr=root;
	    while(true)
	    {
	        while(ptr!=null)
	        {
	            s.push(ptr);
	            ptr=ptr.rc;	           
	        }
			
	        if(s.isEmpty())
	            return;
	 
	        ptr=s.pop();
	        System.out.print(ptr.data+" ");
	        ptr=ptr.lc;	        
	    }
	}

	
	int count(node l_root)
	{
 
	    if(l_root.lc==null&&l_root.rc==null)
	    {
	    	count++;
	    }
	    else
	    {
		    if(l_root.lc!=null)
		    {
		    	count(l_root.lc);
		    }
		    if(l_root.rc!=null)
		    {
		   		count(l_root.rc);   
		    }
	    }
	    
	    return count;
	     
	}
   	
    /*
	
	NON recurssive count
   
	void countleaf()
	{
	    if(Empty())
			return;
		
	    Queue<node> q=new LinkedList<node>();
	    int count=0;
		
	    q.add(root);
		
	    while(!q.isEmpty())
	    {
			ptr=q.remove();
			
	        if(ptr.lc!=null)	     
	      		q.add(ptr.lc);

	        if(ptr.rc!=null)	      
	            q.add(ptr.rc);
	        
			if(ptr.lc==null && ptr.rc==null)
				count++;
	    }
	    
		System.out.println("Total no of leaf nodes are : "+count);
	   
	}  
	
	*/
	 
	void countleaf()
	{
	    if(Empty())
			return;
		
	    int c=count(root);
	    System.out.println("Total no of leaf nodes are : "+c);
	   
	}
	
	int height(node root)
	{
		int hleft=0;
	    int hright=0;
	    if(root.lc!=null)
	    {
	        hleft=height(root.lc);
	    }
	    if(root.rc!=null)
	    {
	        hright=height(root.rc);
	    }
	    if(hleft>hright)
	    {
	        return hleft+1;
	    }
	    else
	    {
	        return hright+1;
	    }      
		
	}

	
	/*
	Non recursive height
	
	void findHeight()
	{
		if(Empty())
			return;
		
	    int h=0;
		
		Queue<node> q=new LinkedList<node>();
		
		q.add(root);
		q.add(null);
		
		while(!q.isEmpty())
		{
			ptr=q.remove();
			
			if(ptr==null)
			{
				if(!q.isEmpty())
					q.add(null);
				h++;
			}
			else
			{
				if(ptr.lc!=null)
					q.add(ptr.lc);
				if(ptr.rc!=null)
					q.add(ptr.rc);
			}
		}
		
	    System.out.println("Height of a BST is : "+h);
	    
	}
	*/
	
	
	void findHeight()
	{
		
		if(Empty())
			return;
		
	    int h=height(root);
	    System.out.println("Height of a BST is : "+h);
	     
	}
	
	

	node copy1(node r)
	{
		node ptr1=null;

	    if(r==null)
	    {
	        return null;
	    }
	    else
	    {
	        node temp1=new node(r.data);
	        
	        if(r.lc!=null)
	        {	
	    	    temp1.lc=copy1(r.lc);
	        }
	        if(r.rc!=null)
	        {
	        	temp1.rc=copy1(r.rc);
	        }

	        return temp1;
	    }         
	       
	}

	void copy()
	{
		if(Empty())
			return;
		
	    node p=copy1(root);
	    Stack<node> s=new Stack<node>();
	    while(true)
	    {
	        while(p!=null)
	        {
	            s.push(p);
	            p=p.lc;
	           
	        }
	        if(s.isEmpty())
	        {
	            return;
	        }
	        else
	        {
	            p=s.pop();
	            System.out.print(p.data+"  ");
	            p=p.rc;
	        }
	    }   
	   
	}
	
	boolean Empty()
	{
		if(root==null)
		{
			System.out.println("Tree is empty!");
			return true;
		}
		return false;
		
	}
	
	void find_p()
	{
		if(Empty())
			return;
		
		if(root.lc==null&&root.rc==null)
		{
			System.out.println("Tree must be having atleast two levels!!!");
			return;
		}
		
		System.out.println("Enter the node to find its parent");
		int nd=sc.nextInt();
		
		int flag=0;
		node ptr=root;
		node parent=null;
		
		while(ptr!=null)
		{
		
			if(nd<ptr.data)
			{
				parent=ptr;
			    ptr=ptr.lc;				           
			}
			else if(nd>ptr.data)
			{
				parent=ptr;
			    ptr=ptr.rc;			               
			}
			else
			{
				break;
			}
	    }
		
		if(ptr==null)
			System.out.println("Node not found!");
		else
		{
			if(parent!=null)
				System.out.println("Parent is : "+parent.data);
			else
				System.out.println(nd+" is root hence has no parent ! ");
		}
		
	}
	
}


class BSTop
{
	public static void main(String args[])
	{
		
		Scanner sc=new Scanner(System.in);
		BST t=new BST();
		int ch;
		
		
		do
		{
			System.out.println("");
			System.out.println("==================MENU================");
			System.out.println("");
			System.out.println("1.Create Tree");
			System.out.println("2.Display Tree");
			System.out.println("3.Find Maximum and Minimum node in a tree");
			System.out.println("4.Display Tree Levelwise");
			System.out.println("5.Find height of the tree");
			System.out.println("6.Display tree in descending order");
			System.out.println("7.Count no of leaf nodes in recursive");
			System.out.println("8.Copy tree");
			System.out.println("9.Find parent");
			System.out.println("10.Exit");
			System.out.println("");
			System.out.println("Enter your choice : ");
			ch=sc.nextInt();
			System.out.println("");
			switch(ch)
			{

				  case 1:
				     t.create();
				     break;
				  case 2:
				      t.display();
				      break;
				  case 3:
				      t.findMaxMin();
				      break;
				  case 4:
				      t.levelOrder();
				      break;
				  case 5:
				      t.findHeight();
				      break;
				  case 6:
				      t.descorder();
				      break;
				  case 7:
				     t.countleaf();
				      break;
				  case 8:
				      t.copy();
				      break;   
				  case 9:
				      t.find_p();
				      break;   
					 

			  }
		
		}while(ch>0&&ch<10);

	}
}

/*

OUTPUT:


==================MENU================

1.Create Tree
2.Display Tree
3.Find Maximum and Minimum node in a tree
4.Display Tree Levelwise
5.Find height of the tree
6.Display tree in descending order
7.Count no of leaf nodes in recursive
8.Copy tree
9.Find parent
10.Exit

Enter your choice :
1

Enter the value for node :
4
Node inserted!


Do you want to continue creating? (Y/N)
y
Enter the value for node :
2
Node inserted!


Do you want to continue creating? (Y/N)
y
Enter the value for node :
6
Node inserted!


Do you want to continue creating? (Y/N)
y
Enter the value for node :
1
Node inserted!


Do you want to continue creating? (Y/N)
y
Enter the value for node :
3
Node inserted!


Do you want to continue creating? (Y/N)
y
Enter the value for node :
5
Node inserted!


Do you want to continue creating? (Y/N)
n

==================MENU================

1.Create Tree
2.Display Tree
3.Find Maximum and Minimum node in a tree
4.Display Tree Levelwise
5.Find height of the tree
6.Display tree in descending order
7.Count no of leaf nodes in recursive
8.Copy tree
9.Find parent
10.Exit

Enter your choice :
2

1
2
3
4
5
6

==================MENU================

1.Create Tree
2.Display Tree
3.Find Maximum and Minimum node in a tree
4.Display Tree Levelwise
5.Find height of the tree
6.Display tree in descending order
7.Count no of leaf nodes in recursive
8.Copy tree
9.Find parent
10.Exit

Enter your choice :
3

Minimum node is : 1
Maximum node is : 6

==================MENU================

1.Create Tree
2.Display Tree
3.Find Maximum and Minimum node in a tree
4.Display Tree Levelwise
5.Find height of the tree
6.Display tree in descending order
7.Count no of leaf nodes in recursive
8.Copy tree
9.Find parent
10.Exit

Enter your choice :
4

4 2 6 1 3 5
==================MENU================

1.Create Tree
2.Display Tree
3.Find Maximum and Minimum node in a tree
4.Display Tree Levelwise
5.Find height of the tree
6.Display tree in descending order
7.Count no of leaf nodes in recursive
8.Copy tree
9.Find parent
10.Exit

Enter your choice :
5

Height of a BST is : 3

==================MENU================

1.Create Tree
2.Display Tree
3.Find Maximum and Minimum node in a tree
4.Display Tree Levelwise
5.Find height of the tree
6.Display tree in descending order
7.Count no of leaf nodes in recursive
8.Copy tree
9.Find parent
10.Exit

Enter your choice :
6

6 5 4 3 2 1
==================MENU================

1.Create Tree
2.Display Tree
3.Find Maximum and Minimum node in a tree
4.Display Tree Levelwise
5.Find height of the tree
6.Display tree in descending order
7.Count no of leaf nodes in recursive
8.Copy tree
9.Find parent
10.Exit

Enter your choice :
7

Total no of leaf nodes are : 3

==================MENU================

1.Create Tree
2.Display Tree
3.Find Maximum and Minimum node in a tree
4.Display Tree Levelwise
5.Find height of the tree
6.Display tree in descending order
7.Count no of leaf nodes in recursive
8.Copy tree
9.Find parent
10.Exit

Enter your choice :
8

1  2  3  4  5  6
==================MENU================

1.Create Tree
2.Display Tree
3.Find Maximum and Minimum node in a tree
4.Display Tree Levelwise
5.Find height of the tree
6.Display tree in descending order
7.Count no of leaf nodes in recursive
8.Copy tree
9.Find parent
10.Exit

Enter your choice :
9

Enter the node to find its parent
4
4 is root hence has no parent !

==================MENU================

1.Create Tree
2.Display Tree
3.Find Maximum and Minimum node in a tree
4.Display Tree Levelwise
5.Find height of the tree
6.Display tree in descending order
7.Count no of leaf nodes in recursive
8.Copy tree
9.Find parent
10.Exit

Enter your choice :
9

Enter the node to find its parent
5
Parent is : 6

==================MENU================

1.Create Tree
2.Display Tree
3.Find Maximum and Minimum node in a tree
4.Display Tree Levelwise
5.Find height of the tree
6.Display tree in descending order
7.Count no of leaf nodes in recursive
8.Copy tree
9.Find parent
10.Exit

Enter your choice :
9

Enter the node to find its parent
2
Parent is : 4

==================MENU================

1.Create Tree
2.Display Tree
3.Find Maximum and Minimum node in a tree
4.Display Tree Levelwise
5.Find height of the tree
6.Display tree in descending order
7.Count no of leaf nodes in recursive
8.Copy tree
9.Find parent
10.Exit

Enter your choice :
10


*/
