import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        int[][] matrixTest1 = {
                {4, 3, 8, 4},
                {9, 5, 1, 9},
                {2, 7, 6, 2},
        };

        int [][] matrixTest2 = {
                {5, 5, 5},
                {5, 5, 5},
                {5, 5, 5},
        };

        int [][] matrixTest3 = {
                {10, 3, 5},
                {1, 6, 11},
                {7, 9, 2},
        };

        int [][] matrixTest4 = {
                {3,10,2,3,4},
                {4,5,6,8,1},
                {8,8,1,6,8},
                {1,3,5,7,1},
                {9,4,9,2,9},
        };
        Solution sol = new Solution();
        // brute force solution
        int res = sol.numMagicSquaresInside(matrixTest4);
        System.out.println(res);
    }
}