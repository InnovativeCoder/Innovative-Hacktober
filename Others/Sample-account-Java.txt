//Program to simulate a simple bank account using Java

//Class with all the functionalities for a basic account such as credit, debit and transferring some money to another account
class Account
{
	String id,name;	
	int balance;
	static int count = 0;

	// Constructor for the class Account
	Account(String name)
	{
		balance=0;
		this.name = name;
		count+=1;
		id = String.valueOf(count);
	}

	String getID()
	{
		return id;
	}
	String getName()
	{
		return name;
	}
	int getBalance()
	{
		return balance;
	}

	void credit(int amount)
	{
		balance += amount;
	}
	int debit(int amount)
	{
		if(amount<=balance)
			balance-=amount;
		else
			System.out.println("Amount exceeded the balance!");
		return balance;
	}
	int transferTo(Account a,int amount)
	{
		if(amount<=balance)
		{
			a.balance+=amount;
			this.balance-=amount;
		}
		else
			System.out.println("Amount exceeded the balance!");
	}
	String toString()
	{
		return "Account[Id= "+id+" Name= "+name+ " Balance= "+balance+"]";
	}
} 
		
// Class with the main function
public class Acc
{
	public static void main(String args[])
	{
		Account a1 = new Account();
		Account a2 = new Account();
		System.out.println("Account a1 id:"+a1.getID());
		System.out.println("Account a1 name: "+a1.getName());
		System.out.println("Account a1 balance: "+a1.getBalance());
		System.out.println("Account a2 id: "+a2.getBalance());
		a1.credit(100);
		System.out.println("Account a1 after credit, balance: "+a1.getBalance());
		a1.transferTo(a2,30);
		System.out.println("Balance of a1:"+a1.getBalance()+" and a2: "+a2.getBalance());
		a1.debit(20);
		System.out.println("Balance of a1:"+a1.getBalance()+" and a2: "+a2.getBalance());
		System.out.println(a1.toString());
		System.out.println(a2.toString());
	}
} 
