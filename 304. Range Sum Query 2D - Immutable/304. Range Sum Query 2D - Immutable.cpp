#include <vector>
#include <iostream>

using namespace std;

class NumMatrix {
private:
    int rows;
    int cols;
    vector<vector<int>> sumArr;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();
        this->sumArr = createSumMatrix(matrix);
    }

    vector<vector<int>> createSumMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> sumArr;
        for (int i = 0; i < rows; i++)
        {
            vector<int> newArr(cols);
            sumArr.push_back(newArr);
        }

        sumArr[0][0] = matrix[0][0];

        // calculate the first row
        for (int i = 1; i < this->cols; i++)
        {
            sumArr[0][i] = sumArr[0][i - 1] + matrix[0][i];
        }

        // calculate the first column
        for (int i = 1; i < this->rows; i++)
        {
            sumArr[i][0] = sumArr[i - 1][0] + matrix[i][0];
        }

        // calculate the sumArr matrix
        for (int i = 1; i < this->rows; i++)
        {
            for (int j = 1; j < this->cols; j++)
            {
                sumArr[i][j] = sumArr[i - 1][j] + sumArr[i][j - 1] - sumArr[i - 1][j - 1] + matrix[i][j];
            }
        }

        // //print sumArr
        //for (int i = 0; i < this->rows; i++)
        //{
        //    for (int j = 0; j < this->cols; j++)
        //    {
        //        cout << sumArr[i][j] << ' ';
        //    }
        //    cout << '\n';
        //}

        return sumArr;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        // this is the general case
        int result = 0;
        if (row1 == 0 && col1 == 0)
        {
            result = sumArr[row2][col2];
        }
        else if (row1 == 0) {
            result = sumArr[row2][col2] - sumArr[row2][col1 - 1];
        }
        else if (col1 == 0) {
            result = sumArr[row2][col2] - sumArr[row1 - 1][col2];
        }
        else {
            result = sumArr[row2][col2] - sumArr[row1 - 1][col2] - sumArr[row2][col1 - 1] + sumArr[row1 - 1][col1 - 1];
        }
        //cout << "Result: " << endl;
        return result;
    }
};

int main()
{
    //vector<vector<int>> newMatrix =
    //{
    //    {3, 0, 1, 4, 2},
    //    {5, 6, 3, 2, 1},
    //    {1, 2, 0, 1, 5},
    //    {4, 1, 0, 1, 7},
    //    {1, 0, 3, 0, 5},
    //};

    vector<vector<int>> newMatrix =
    {
        {-1}
    };
    NumMatrix sol(newMatrix);



    //cout << sol.sumRegion(2, 1, 4, 3) << endl; // return 8 (i.e sum of the red rectangle)
    //cout << sol.sumRegion(1, 1, 2, 2) << endl; // return 11 (i.e sum of the green rectangle)
    //cout << sol.sumRegion(1, 2, 2, 4) << endl; // return 12 (i.e sum of the blue rectangle)
    cout << sol.sumRegion(0, 0, 0, 0) << endl;


}