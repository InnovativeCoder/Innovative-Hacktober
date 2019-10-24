
import java.util.Arrays;
import java.util.Scanner;

public class SEO {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		SEO(n);

	}

	public static void SEO(int limit) {

		boolean[] arr = new boolean[limit + 1];
		Arrays.fill(arr, true);
		arr[0] = false;
		arr[1] = false;
		for (int table = 2; table * table <= limit; table++) {
			if (arr[table] == false) {
				continue;
			}

			for (int mult = 2; table * mult <= limit; mult++) {
				arr[table * mult] = false;
			}
		}
		

		for (int i = 0; i < arr.length; i++) {
			if (arr[i] == true) {
				System.out.println(i);
			}
		}
	}

}
