abstract class area
{
  abstract int areacal(int side);
  abstract int areacal(int l,int b);
  abstract double areacal(double r);
}
class Calculation extends area
 {
   int areacal(int side)
    {
      return(side*side);
    }
    int areacal(int l,int b)
    {
     return(l*b);
     }
    double areacal(double r)
    {
     return(3.14*r*r);
     }
     public static void main(String args[])
     {
        Calculation c1=new Calculation();
        int as=c1.areacal(15);
        int ar=c1.areacal(2,3);
        double ac=c1.areacal(3);
      System.out.println("Area of square :"+as+"\nArea of rectangle :"+ar+"\nArea of circle:"+ac);
    }
}
