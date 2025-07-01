import java.util.*;

public class Solution {
    private boolean validIndex(int posRow, int posCol, int rows, int cols)
    {
        if (posRow >= 0 && posRow < rows && posCol >= 0 && posCol < cols)
            return true;
        return false;
    }
    private void drawSquare(Integer[][] square, int posX, int posY, char block)
    {
        square[posX - 1][posY] = 0;
        square[posX + 1][posY] = 0;
        square[posX][posY - 1] = 0;
        square[posX][posY + 1] = 0;

        // barrier cells are set to -1
        switch (block)
        {
            case '/':
                square[posX][posY] = -1;
                square[posX - 1][posY + 1] = -1;
                square[posX + 1][posY - 1] = -1;
                square[posX + 1][posY + 1] = 0;
                square[posX - 1][posY - 1] = 0;
                break;
            case '\\':
                square[posX][posY] = -1;
                square[posX + 1][posY + 1] = -1;
                square[posX - 1][posY - 1] = -1;
                square[posX - 1][posY + 1] = 0;
                square[posX + 1][posY - 1] = 0;
                break;
            case ' ':
                square[posX][posY] = 0;
                square[posX + 1][posY + 1] = 0;
                square[posX - 1][posY - 1] = 0;
                square[posX - 1][posY + 1] = 0;
                square[posX + 1][posY - 1] = 0;
                break;
        }
    }

    private void fillMatrix(Integer[][] matrix, int posRow, int posCol, Integer count)
    {
        if (matrix[posRow][posCol] == -1)
            return;
        if (matrix[posRow][posCol] == 0)
        {
            count++;
            matrix[posRow][posCol] = count;
        }
        int rows = matrix.length;
        int cols = matrix[0].length;
        // fill right
        if (validIndex(posRow, posCol + 1, rows, cols) && matrix[posRow][posCol + 1] == 0)
        {
            matrix[posRow][posCol + 1] = matrix[posRow][posCol];
        }
        // fill bottom
        if (validIndex(posRow + 1, posCol, rows, cols) && matrix[posRow + 1][posCol] == 0)
        {
            matrix[posRow + 1][posCol] = matrix[posRow][posCol];
        }
    }

    private final int[][] direction = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0},
    };

    private void floodFill(int initialPosRow, int initialPosCol, Integer[][] matrix)
    {
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int [] {initialPosRow, initialPosCol});
        int fillPosRow = 0;
        int fillPosCol = 0;
        int rows = matrix.length, cols = matrix[0].length;
        int[] getNextCell;
        // iterate through directions
        while (!queue.isEmpty())
        {
            getNextCell = queue.poll();
            for (int i = 0; i < 4; i++) {
                fillPosRow = getNextCell[0] + direction[i][0];
                fillPosCol = getNextCell[1] + direction[i][1];

                if (validIndex(fillPosRow, fillPosCol, rows, cols) && matrix[fillPosRow][fillPosCol] == 0)
                {
                    matrix[fillPosRow][fillPosCol] = 1;
                    queue.add(new int [] {fillPosRow, fillPosCol});
                }
            }
        }

    }

    public int bfsSolution(String[] grid)
    {
        Integer count = Integer.valueOf(0);
        Integer[][] matrix = convertStringToMatrix(grid);
        int rows = matrix.length;
        int cols = matrix[0].length;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0)
                {
                    floodFill(i, j, matrix);
                    count++;
                }
            }
        }

        return count;
    }

    public Integer[][] convertStringToMatrix(String[] grid)
    {
        int rows = grid.length * 3;
        int cols = grid[0].length() * 3;
        Integer[][] newMatrix = new Integer[rows][cols];
        for (int i = 1; i < rows; i += 3) {
            for (int j = 1; j < cols; j += 3) {
                drawSquare(newMatrix, i, j, grid[i / 3].charAt(j / 3));
            }
        }

        return newMatrix;
    }
    public int regionsBySlashes(String[] grid) {
        return bfsSolution(grid);
    }
}