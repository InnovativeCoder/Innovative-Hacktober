abstract class area
{
	abstract int areacal(int a);
	abstract int areacal(int l,int b);
	abstract double areacal(double r);
}

class calculation extends area
{
	int areacal(int a)
		{
			return(a*a);
		}
	int areacal(int l,int b)
		{
			return(l*b);
		}
	double areacal(double r)
		{
			return(3.14*r*r);
		}
}

class AbstractClass
{
	public static void main(String[] args)
		{
			calculation c=new calculation();
			int areacube=c.areacal(10);
			int arearect=c.areacal(12,12);
			float areacir=c.areacal(10);
			System.out.println("Cube: "+areacube);
			System.out.println("Rectangle: "+arearect);
			System.out.println("Circle: "+areacir);
		}
}
