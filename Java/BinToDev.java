import java.util.scanner;

public class BinToDec{
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Please enter a Binary number:");
        int binNum = sc.nextInt();
        int result = 0, r = 0, pow = 0;
        while(binNum != 0){
            r = binNum % 10;
            result += r * (int)Math.pow(2, pow++);
            binNum /= 10;
        }
        System.out.println("Decimal: " + result);
        sc.close();;
    }
}
