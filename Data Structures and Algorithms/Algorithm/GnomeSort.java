import java.lang.StringBuilder;

public class GnomeSort {

    public static void main(String[] args) {
        // random numbers
        int[] someNumbers = { 27, 21, 6, 1, 12, 10, 5, 1, 13, 8, 11, 22, 22, 28, 21, 23, 4, 14, 29, 26 };

        GnomeSort gnome = new GnomeSort();

        System.out.println("Befor sort:");
        gnome.print(someNumbers);

        gnome.sort(someNumbers);

        System.out.println("After sort:");
        gnome.print(someNumbers);

    }

    public void sort(int[] numArr) {
        int i = 1;
        int j = 2;
        while (i < numArr.length) {
            if (numArr[i - 1] < numArr[i]) {
                i = j++;
            } else {
                // swap elements
                int temp = numArr[i - 1];
                numArr[i - 1] = numArr[i];
                numArr[i] = temp;
                if (--i == 0) {
                    i = j++;
                }
            }
        }
    }

    public void print(int[] numbersArray) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < numbersArray.length; i++) {
            sb.append(numbersArray[i] + " ");
        }
        System.out.println(sb.toString());
    }
}
