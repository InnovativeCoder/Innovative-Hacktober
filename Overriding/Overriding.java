import java.util.*;
interface A
{
 void cal();
 void display();
}
class B implements A
{
  Scanner s=new Scanner(System.in);
  float a;
  double b;
  public void cal()
  {
   System.out.println("Enter the radius of the circle:");
   a=s.nextFloat();
   b=3.14*a*a;
  } 
  public void display()
  {
    System.out.println("Area of the circle"+b);
  }
}
class C implements A
{
  Scanner s=new Scanner(System.in);
  float a,c;
  double b;
  public void cal()
  {
   System.out.println("Enter the length & breadth of the rectangle:");
   a=s.nextFloat();
   c=s.nextFloat();
   b=a*c;
  } 
  public void display()
  {
    System.out.println("Area of the rectangle:"+b);
  }
}
class Overriding

{
 public static void main(String args[])
{
 Scanner s=new Scanner(System.in);
 A a=null;
 System.out.println("Enter,\n1.Area of circle\n2.Area of rectangle");
 System.out.println("Enter your choice:");
 int x=s.nextInt();
 switch(x)
 {
  case 1:
  a=new B();
  break;
  case 2:
  a=new C(); 
 }
 a.cal();
 a.display();
}
}
