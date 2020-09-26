/*

	Title	:	To implement binary search tree and perform operations on it.
	
*/

import java.util.Scanner;

class node
{
	node left,right;
	String keyword;
	String meaning;
	
	node(String k,String m)
	{
		keyword=k;
		meaning=m;
		left=null;
		right=null;
	}
}



class Dict
{
	private node root;
	
	Dict()
	{
		root=null;
	}
	
	void create()
	{
		char ch;
		
		Scanner sc= new Scanner(System.in);
		
		do
		{
			
			System.out.print("Enter the word: ");
			String key=sc.next();

			System.out.print("Enter the meaning of word: ");
			String mean=sc.next();

		
			insert(key,mean);
			
			System.out.println("Do you want to continue creating? (Y/N) ");
			ch=sc.next().charAt(0);
			
		}while(ch=='y'||ch=='Y');
	}
	
	
	
	void insert(String key,String mean)
	{
		
		node temp=new node(key,mean);
			
		if(root==null)
		{
			root=temp;
		}
		else
		{
			node ptr=root;
			
			while(ptr!=null)
			{
				if(key.compareTo(ptr.keyword)<0)
				{
					if(ptr.left!=null)
					{
						ptr=ptr.left;
					}
					else
					{
						ptr.left=temp;
						break;
					}
				}
				else if(key.compareTo(ptr.keyword)>0)
				{
					if(ptr.right!=null)
					{
						ptr=ptr.right;
					}
					else
					{
						ptr.right=temp;
						break;
					}
				}
				else
				{
					System.out.println("Duplicate entry !");
					break;
				}
			}
		}
			
	}
	
	void inorder(node local_root)
	{
		if(local_root!=null)
		{
			inorder(local_root.left);
			System.out.println(local_root.keyword+":\t\t"+local_root.meaning);
			inorder(local_root.right);
		}
	}
	
	
	void display()
	{
		if(root==null)
		{
			System.out.println("Tree is empty!");
			return;
		}
		
		inorder(root);
	}
	
	
	void search()
	{
		
		if(root==null)
		{
			System.out.println("Tree is empty!");
			return;
		}
	
		Scanner sc=new Scanner(System.in);
		
		System.out.print("Enter the word to search: ");
		String key=sc.next();
		
		node ptr=root;
		
		
		while(ptr!=null)
		{
			
			if(key.compareTo(ptr.keyword)==0)
			{
				System.out.println("\nWord Found! ");
				System.out.println(ptr.keyword+":\t\t"+ptr.meaning);
				return;
			}
			else if(key.compareTo(ptr.keyword)<0)
			{ 
				ptr=ptr.left;
			}
			else if(key.compareTo(ptr.keyword)>0)
			{
				ptr=ptr.right;
			}
				
		}
		
		if(ptr==null)
			System.out.println("Word not found! ");
	}
	
	
	void update()
	{
		
		if(root==null)
		{
			System.out.println("Tree is empty!");
			return;
		}
		
		node ptr=root;
		Scanner sc=new Scanner(System.in);
		
		System.out.println("Enter the word to update: ");
		String key=sc.next();
		
		while(ptr!=null)
		{
			if(key.compareTo(ptr.keyword)==0)
			{
				System.out.println("Enter the updated word: ");
				String n_key=sc.next();
		
		
				System.out.println("Before updating: ");
				System.out.println(ptr.keyword+":\t\t"+ptr.meaning);
				
				insert(n_key,ptr.meaning);
				
				System.out.println("\nAfter updating: ");
				System.out.println(n_key+":\t\t"+ptr.meaning);
				
				del(key);
				
			
				System.out.println("\nWord Updated! ");
				return;
			}
			else if(key.compareTo(ptr.keyword)<0)
			{ 
				ptr=ptr.left;
			}
			else if(key.compareTo(ptr.keyword)>0)
			{
				ptr=ptr.right;
			}
				
		}
		
		if(ptr==null)
			System.out.println("Word not found! ");
	}
	
	
	void delete()
	{
		
		if(root==null)
		{
			System.out.println("Tree is empty!");
			return;
		}
		
		Scanner sc=new Scanner(System.in);
		
		System.out.print("Enter the word you want to delete: ");
		String key=sc.next();
		
		del(key);
	}
	

	void del(String key)
	{
		
		node ptr=root;
		node parent=null;
		int flag=0;
		
		while(ptr!=null)
		{	
			
			if(key.compareTo(ptr.keyword)==0)
			{
				flag=1;
				break;
			}
			else if(key.compareTo(ptr.keyword)<0)
			{
				parent=ptr;
				ptr=ptr.left;
			}
			else if(key.compareTo(ptr.keyword)>0)
			{
				parent=ptr;
				ptr=ptr.right;
			}
		
		}
		
		
		if(flag==0)
		{
			System.out.println("Word not found!");
			return;
		}
		
		
		if(ptr.left==null &&ptr.right==null)
		{
			if(ptr==root)
			{
				root=null;
			}
			else
			{
				if(parent.left==ptr)
				{
					parent.left=null;
				}
				if(parent.right==ptr)
				{
					parent.right=null;
				}
			}
			
			ptr=null;
		}
		
		else if((ptr.left!=null)&&(ptr.right==null))
		{
			if(ptr==root)
			{				
				root=ptr.left;
			}
			else
			{
				
				if(parent.left==ptr)
				{
					parent.left=ptr.left;
				}
				if(parent.right==ptr)
				{
					parent.right=ptr.left;
				}
				
			}
			
			ptr=null;
		}
		
		else if((ptr.right!=null)&&(ptr.left==null))
		{
			
			if(ptr==root)
			{
				root=ptr.right;
			}
			else
			{				
				if(parent.left==ptr)
				{
					parent.left=ptr.right;
				}
				if(parent.right==ptr)
				{
					parent.right=ptr.right;
				}
			}
			
			ptr=null;
		}
		
		else if((ptr.left!=null)&&(ptr.right!=null))
		{
			
			node p=ptr.left;
			parent=ptr;
			while(p.right!=null)
			{
				parent=p;
				p=p.right;
			}
			
			ptr.keyword=p.keyword;
			ptr.meaning=p.meaning;
			
			if(parent!=ptr)
			{
				parent.right=p.left;
			}
			if(parent==ptr)
			{
				parent.left=p.left;
			}
			p=null;			
			
		}
		
		System.out.println("Word deleted!");
	}
	
}



public class BST {

	public static void main(String[] args) 
	{
		
		Dict d=new Dict();
		
		int ch;
		Scanner sc=new Scanner(System.in);
		d.create();
		
		do
		{
			System.out.println("");
			System.out.println("==================MENU================");
			System.out.println("");
			System.out.println("1.Insert");
			System.out.println("2.Display");
			System.out.println("3.Search");
			System.out.println("4.Update word ");
			System.out.println("5.Delete word");
			System.out.println("6.Exit\n");
			 
			System.out.println("Enter your choice : ");
			ch=sc.nextInt();
			System.out.println("");
			switch(ch)
			{

				  case 1:
				     d.create();
				     break;
				  case 2:
				      d.display();
				      break;
				  case 3:
				      d.search();
				      break;
				  case 4:
				      d.update();
				      break;
				  case 5:
				      d.delete();
				      break;				  
				  
			  }
		
		}while(ch>0&&ch<6);

		

	}

}


/*


OUTPUT:


Enter the word: print
Enter the meaning of word: dffs
Do you want to continue creating? (Y/N)
y
Enter the word: if
Enter the meaning of word: ddfds
Do you want to continue creating? (Y/N)
y
Enter the word: return
Enter the meaning of word: dffd
Do you want to continue creating? (Y/N)
y
Enter the word: and
Enter the meaning of word: ferfr
Do you want to continue creating? (Y/N)
y
Enter the word: block
Enter the meaning of word: wddsa
Do you want to continue creating? (Y/N)
n

==================MENU================

1.Insert
2.Display
3.Search
4.Update word
5.Delete word
6.Exit

Enter your choice :
2

and:            ferfr
block:          wddsa
if:             ddfds
print:          dffs
return:         dffd

==================MENU================

1.Insert
2.Display
3.Search
4.Update word
5.Delete word
6.Exit

Enter your choice :
3

Enter the word to search: bllock
Word not found!

==================MENU================

1.Insert
2.Display
3.Search
4.Update word
5.Delete word
6.Exit

Enter your choice :
3

Enter the word to search: block

Word Found!
block:          wddsa

==================MENU================

1.Insert
2.Display
3.Search
4.Update word
5.Delete word
6.Exit

Enter your choice :
4

Enter the word to update:
return
Enter the updated word:
raise
Before updating:
return:         dffd

After updating:
raise:          dffd

Word Updated!

==================MENU================

1.Insert
2.Display
3.Search
4.Update word
5.Delete word
6.Exit

Enter your choice :
2

and:            ferfr
block:          wddsa
if:             ddfds
print:          dffs
raise:          dffd

==================MENU================

1.Insert
2.Display
3.Search
4.Update word
5.Delete word
6.Exit

Enter your choice :
5

Enter the word you want to delete: if

==================MENU================

1.Insert
2.Display
3.Search
4.Update word
5.Delete word
6.Exit

Enter your choice :
2

and:            ferfr
block:          wddsa
print:          dffs
raise:          dffd

*/
