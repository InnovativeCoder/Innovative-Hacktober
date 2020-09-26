class Student
{
int no;
String m;
Student(int r, String nm)
{
no=r;
m=nm;
}
void putDetails()
{
System.out.println("Name: "+m);
System.out.println("Roll no: "+no);
}
}
class Marks extends Student
{
	float marks1, marks2;
	Marks(int r,String nm,float m1,float m2)
	{
		super(r,nm);
		marks1=m1;
		marks2=m2;
	}
	
	void putMarks()
	{
	System.out.println("Marks: "+marks1+" "+marks2);
	}
}

class finalTotal extends Marks
{
	float total;

	finalTotal(int r,String nm,float m1,float m2)
	{
		super(r,nm,m1,m2);
		total=marks1+marks2;
	}

	void displaytotal()
	{
	System.out.println("Total Marks: "+total);
	}

	public static void main(String args[])
	{
		finalTotal obj=new finalTotal(5,"Student",15,30);
		obj.putDetails();
		obj.putMarks();
		obj.displaytotal();
	}
}
