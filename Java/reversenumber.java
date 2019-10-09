package oldprogarms.pepcode;

public class reversenumber {

	public static void main(String[] args) {
	 int n= 92785463;
	 
	 while(n!=0)
	 {
		 
		 int a=n%10;
		 System.out.print(a);
		 n=n/10;
	 }
	}

}


