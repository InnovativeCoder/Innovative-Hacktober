import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class GFG {
    public static void main (String[] args) throws IOException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int testcase=Integer.parseInt(br.readLine());
        while(--testcase>=0){
            String s = br.readLine();
            StringBuffer sb1 = new StringBuffer(s);
            int n = Integer.parseInt(s);
            if(n<10){
                System.out.println(n);
            }
            else {
                int l = 0;
                if (!s.contains("0")) {
                    l = Digits(s.toCharArray());
                    for (int i = 0; i < s.length(); i++) {
                        if (s.charAt(i) == (l + "").charAt(0)) {
                            sb1.deleteCharAt(i);
                            break;
                        }
                    }
                } else {
                    for (int i = 0; i < s.length(); i++) {
                        if (s.charAt(i) == '0') {
                            l = Digits((s.substring(0, i)).toCharArray());
                            break;
                        }
                    }
                    for (int i = 0; i < s.length(); i++) {
                        if (s.charAt(i) == (l + "").charAt(0)) {
                            sb1.deleteCharAt(i);
                            break;
                        }
                    }
                }
                System.out.println(Integer.valueOf(sb1.toString()));
            }
        }

    }

    static int Digits(char[] ch)
    {
        int largest = 0; int j=0;
        if(ch.length==1)    largest=Character.getNumericValue(ch[0]);
        else {
            for (int i = 1; i < ch.length; i++) {
                if (Character.getNumericValue(ch[i - 1]) > Character.getNumericValue(ch[i])) {
                    largest = Character.getNumericValue(ch[i - 1]);
                    break;
                } else {
                    j++;
                }
            }
            if (j == ch.length - 1) {
                largest = Character.getNumericValue(ch[j]);
            }
        }
        return largest;

    }

    static int Digitsl(int n)
    {
        int largest = 0;
        int smallest = 9;

        while(n != 0)
        {
            int r = n % 10;

            // Find the largest digit
            largest = Math.max(r, largest);

            // Find the smallest digit
            smallest = Math.min(r, smallest);

            n = n / 10;
        }
        return largest;
    }
}