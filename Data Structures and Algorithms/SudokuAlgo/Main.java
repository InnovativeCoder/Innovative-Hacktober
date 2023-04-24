public class Main {
    public static void main(String[] args) {
        SudokuMatrix matObj=new SudokuMatrix();
        int[][] solved_matrix=matObj.generateSudokuMatrix(9);
        System.out.println("Sudoku Solution Matrix:- ");
        matObj.printMatrix(solved_matrix);
        System.out.println("");
        int[][] sudoku_matrix=matObj.generateSudoku(solved_matrix,5);
        System.out.println("Sudoku Matrix To Solve:- ");
        matObj.printMatrix(sudoku_matrix);
    }
}