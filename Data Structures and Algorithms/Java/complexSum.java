public class ComplexNumber{
   
   double real, img;
	

   ComplexNumber(double r, double i){
	this.real = r;
	this.img = i;
   }
	
   public static ComplexNumber sum(ComplexNumber com1, ComplexNumber com2)
   {
	
        ComplexNumber temp = new ComplexNumber(0, 0);

        temp.real = com1.real + com2.real;
        temp.img = com1.img + com2.img;
        
        
        return temp;
    }
    public static void main(String args[]) {
	ComplexNumber com1 = new ComplexNumber(5.5, 4);
	ComplexNumber com2 = new ComplexNumber(1.2, 3.5);
        ComplexNumber temp = sum(com1, com2);
        System.out.printf("Sum is: "+ temp.real+" + "+ temp.img +"i");
    }
}
