package matrix_ops;
import java.util.Scanner;

public class matrix {
    
    public final Scanner input = new Scanner(System.in);

    public void fillMatrix(int[][] matrix) {
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                System.out.printf("Line %d Column %d: ", i + 1, j + 1);
                matrix[i][j] = input.nextInt();
            }
        }
    }

    public int[][] sumMatrix(int[][] matrix1, int[][] matrix2) {
        int[][] sumOfMatrix = new int[matrix1.length][matrix1.length];
        for (int i = 0; i < matrix1.length; i++) {
            for (int j = 0; j < matrix1.length; j++) {
                sumOfMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        return sumOfMatrix;
    }

    public int[][] subtractMatrix(int[][] matrix1, int[][] matrix2) {
        int[][] addedMatrix = new int[matrix1.length][matrix1.length];
        for (int i = 0; i < matrix1.length; i++) {
            for (int j = 0; j < matrix1.length; j++) {
                addedMatrix[i][j] = matrix1[i][j] - matrix2[i][j];
            }
        }
        return addedMatrix;
    }

    public void printMatrix(int[][] matrix) {
        int i, j;
        for (i = 0; i < matrix.length; i++) {
            System.out.println();
            for (j = 0; j < matrix[0].length; j++) {
                System.out.print(matrix[i][j] + " ");
            }
        }
        System.out.println("");
    }

    public int[][] transposeMatrix(int[][] matrix) {
        int[][] transposeMatrix = new int[matrix.length][matrix.length];
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                transposeMatrix[i][j] = matrix[j][i];
            }
        }
        return transposeMatrix;
    }

    public int[][] multiplyMatrix(int[][] matrix1, int[][] matrix2) {
        int[][] multiplyMatrix = new int[matrix1.length][matrix1.length];
        for (int i = 0; i < matrix1.length; i++) {
            for (int j = 0; j < matrix1[0].length; j++) {
                for (int k = 0; k < matrix1.length; k++) {
                    multiplyMatrix[k][j] = matrix1[i][0] * matrix2[0][j];
                }
            }
        }
        return multiplyMatrix;
    }

}
