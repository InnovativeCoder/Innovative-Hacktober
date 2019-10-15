public class CaptchaCodeGen{
    public static void main(String args[]){
         
    
        int num1,num2;
        char upperCaseLetter;
        char lowerCaseLetter;
        char specialCharacter1;
        char specialCharacter2;
        num1 = (int)(Math.random()*10);//0-9
        num2 = (int)(Math.random()*10);//0-9
        int temp1 = (int)(Math.random()*100)%26; //0-26
        lowerCaseLetter = (char)(temp1+65) ; //A-Z
        int temp2 = (int)(Math.random()*100)%26; //0-26
        upperCaseLetter = (char) (temp2+97);//a-z
        int temp3 = (int)(Math.random()*10);
        specialCharacter1 = (char)(temp3+33);
        specialCharacter2 = (char)(temp3+37);

        System.out.println(specialCharacter2+""+num1+""+lowerCaseLetter+""+specialCharacter1+""+num2+""+upperCaseLetter);


    }
}