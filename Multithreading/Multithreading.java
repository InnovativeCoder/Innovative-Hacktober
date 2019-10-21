class thread1 extends Thread
{
	public void run()
	{
		try
		{
			for(int i=0;i<20;i++)
			{
				if(i%2==0)
				{
					System.out.println("Even number: "+i);
					sleep(1000);
				}
			}
		}
		catch(Exception e)
		{
			System.out.println("Exception occurs");
		}
	}
}

class thread2 extends Thread
{
	public void run()
	{
		try
		{
			for(int i=0;i<20;i++)
			{
				if(i%2!=0)
				{
					System.out.println("Odd number: "+i);
					sleep(1000);	
				}
			}
		}
		catch(Exception e)
		{
			System.out.println("Exception occurs");
		}
	}
}

class Multithreading
{
	public static void main(String[] args)
	{
		thread1 a=new thread1();
		a.start();
		thread2 b=new thread2();
		b.start();
	}
}

  public void run()
   {
     try
      {
       for(int i=0;i<20;i++)
        {
          if(i%2==0)
         { System.out.println(i);
          sleep(1000);
         }
        }
      }
     catch (Exception e)
      {
         System.out.println("Exception Occurs");
      }
    }
 }
class thread2 extends Thread
{
  public void run()
   {
     try
      {
       for(int i=0;i<20;i++)
        {
          if(i%2!=0)
         { System.out.println(i);
          sleep(1000);
         }
        }
      }
     catch (Exception e)
      {
         System.out.println("Exception Occurs");
      }
    }
 }
class Multithreading
  {
    public static void main(String args[])
     {
        thread1 a=new thread1();
        a.start();
        thread2 b=new thread2();
        b.start();
}
}

