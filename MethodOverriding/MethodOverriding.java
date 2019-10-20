import java.util.Scanner;
interface area
{
	void calc();
	void display();
}

class circle implements area
{
	double a;
	public void calc()
		{
			Scanner sc=new Scanner(System.in);
			System.out.println("Enter the radius of circle");
			int r=sc.nextInt();
			a=3.14*r*r;
		}
	public void display()
		{
			System.out.println("Area of circle:" +a);
		}
}

class triangle implements area
{
	double a;
	public void calc()
		{
			Scanner sc=new Scanner(System.in);
			System.out.println("Enter dimensions of triangle");
			int b=sc.nextInt();
			int h=sc.nextInt();
			a=0.5*h*b;
		}
	public void display()
		{
			System.out.println("Area of triangle"+a);
		}
}

class MethodOverriding
{
	public static void main(String args[])
		{
			Scanner sc=new Scanner(System.in);
			area t=null;
			System.out.println("----MENU----");
			System.out.println("1.Calculate area of circle\n2.Calculate area of triangle");
			int c=sc.nextInt();
			switch(c)
			{	
				case 1:t=new circle();
					break;
				case 2:t=new triangle();
					break;
				default:System.out.println("Enter valid choice");
					break;	
			}
			t.calc();
			t.display();
		}
}

