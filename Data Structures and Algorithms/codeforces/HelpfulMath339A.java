import java.io.CharArrayReader;

public class HelpfulMath339A{
    public static void main(String args[]){
        java.util.Scanner scan = new java.util.Scanner(System.in);
        String input = scan.next();
        input = input.replace("+", "");
        char [] arr = new char[input.length()];
        for(int i = 0 ; i<input.length();i++){
            arr[i] = input.charAt(i);
        }
        java.util.Arrays.sort(arr);
        for(int i = 0 ; i<arr.length;i++){
            System.out.print(arr[i]);
            if(i!=arr.length-1){
            System.out.print("+");
            }
        }

       
        

    }
}
