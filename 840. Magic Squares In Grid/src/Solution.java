import java.util.HashSet;

public class Solution {
    private boolean checkDistinctNumbers(int[][] matrix, int startRows, int startCols)
    {
//        boolean[] checkingArr = new boolean[10]; // default value is false
        HashSet<Integer> checkNumDistinct = new HashSet<Integer>();
        for (int i = startRows; i < startRows + 3; i++) {
            for (int j = startCols; j < startCols + 3; j++) {
                if (matrix[i][j] < 1 || matrix[i][j] > 9 || !checkNumDistinct.add(matrix[i][j])) {
                    return false;
                }
            }
        }
        return true;
    }
    public boolean isMagicSquare(int[][] matrix, int startRows, int startCols) {
        if (!checkDistinctNumbers(matrix, startRows, startCols))
            return false;
        HashSet<Integer> sumResult = new HashSet<Integer>();
        int sum = 0;
        // calculate horizontally
        for (int i = startRows; i < startRows + 3; i++) {
            sum = 0;
            for (int j = startCols; j < startCols + 3; j++) {
                sum += matrix[i][j];
            }
            sumResult.add(sum);
            if (sumResult.size() > 1) {
                return false;
            }
        }

        // calculate vertically
        for (int i = startCols; i < startCols + 3; i++) {
            sum = 0;
            for (int j = startRows; j < startRows + 3; j++) {
                sum += matrix[j][i];
            }
            sumResult.add(sum);
            if (sumResult.size() > 1)
            {
                return false;
            }
        }

        // calculate diagonally
        sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += matrix[startRows + i][startCols + i];
        }
        sumResult.add(sum);
        sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += matrix[startRows + i][startCols + 2 - i];
        }
        sumResult.add(sum);
        if (sumResult.size() > 1)
            return false;
        return true;
    }
    public int bruteForceApproach(int[][] matrix)
    {
        int countMagicSquare = 0;
        int rows = matrix.length;
        int cols = matrix[0].length;

        for (int i = 0; i <= rows - 3; i++) {
            for (int j = 0; j <= cols - 3; j++) {
                if (isMagicSquare(matrix, i, j))
                {
                    countMagicSquare++;
                }
            }
        }

        return countMagicSquare;
    }
    public int numMagicSquaresInside(int[][] grid) {
        return bruteForceApproach(grid);
    }
}