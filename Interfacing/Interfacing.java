import java.util.*;
interface Area
{
 void x(float a,float b);
}
interface Perimeter
{
 void p(float a,float b);
}
class Interfacing implements Area,Perimeter
{
 public void x(float a,float b)
  {
   double c=a*b;
   System.out.println("Area of the rectangle:"+c);
  }
 public void p(float a,float b)
  {
    double c=2*a+2*b;
    System.out.println("Perimeter of the rectangle:"+c); 
  }
 public static void main(String args[])
 {
 Interfacing e=new Interfacing();
 Scanner s=new Scanner(System.in);
 System.out.println("Enter the length & breadth:");
 float a=s.nextFloat();
 float b=s.nextFloat();
 e.x(a,b);
 e.p(a,b);
 }
}
