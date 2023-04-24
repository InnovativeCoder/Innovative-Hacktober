import java.util.ArrayList;
import java.util.Random;

class SudokuMatrix {


    int[][] generateSudokuMatrix(int size) {
        int[][] matrix=new int[size][size];
        int i,j,x,k,tmp;
        for(i=0; i<size; i++) {
            for(j=0; j<size; j++) {
                matrix[i][j]=0;
            }
        }
        ArrayList<Integer> exclude=new ArrayList<>();
        for(i=0; i<size; i++) {
            int rnd=random(0,(size)-1, exclude);
            exclude.add(rnd);
            int n=1;
            for(j=rnd; j<=size; j++) {
                matrix[i][j-1]=n;
                n++;
            }
            tmp=n;
            x=rnd-2;
            for(k=0; k<=x; k++) {
                matrix[i][k]=tmp;
                tmp++;
            }
        }
        int[][] transpose=new int[size][size];
        for(i=0; i<size; i++) {
            for(j=0; j<size; j++) {
                transpose[i][j]=matrix[j][i];
            }
        }
        matrix=transpose;
        for(i=0; i<size; i++) {
            int rnd1=random(0,size-1);
            int rnd2=random(0,size-1);
            int[] swp=matrix[rnd1];
            matrix[rnd1]=matrix[rnd2];
            matrix[rnd2]=swp;
        }
        return matrix;
    }


    int[][] generateSudoku(int[][] matrix,int level) {
        if(level<=matrix[0].length) {
            ArrayList<Integer> exclude = new ArrayList<>();
            for (int i = 0; i < matrix.length; i++) {
                int lvl=random(2,level);
                for (int j = 0; j < lvl; j++) {
                    int rnd = random(0, (matrix[0].length)-1, exclude);
                    exclude.add(rnd);
                    matrix[i][rnd - 1] = 0;
                }
                exclude.clear();
            }
            return matrix;
        }else{
            System.out.println("Error in matrix level!!!");
            return matrix;
        }
    }

    int random(int start, int end,ArrayList<Integer> exclude) {
        Random rand = new Random();
        int range = end - start + 1;
        int random = rand.nextInt(range) + 1;
        while(exclude.contains(random)) {
            random=rand.nextInt(range) + 1;
        }
        return random;
    }

    int random(int start, int end) {
        Random rand = new Random();
        int random = rand.nextInt((end+1) - start) + start;
        return random;
    }

    void printMatrix(int[][] matrix) {
        for(int i=0; i<5*matrix.length; i++) {
            System.out.print("=");
        }
        System.out.println("");
        for(int i=0; i<matrix.length; i++) {
            for(int j=0; j<matrix[i].length; j++) {
                if(matrix[i][j]!=0) {
                    System.out.print("| " + matrix[i][j] + " |");
                }else{
                    System.out.print("| " + " " + " |");
                }
            }
            System.out.println("");
        }
        for(int i=0; i<5*matrix.length; i++) {
            System.out.print("=");
        }
        System.out.println("");
    }
}
