#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findMaxDistance(vector<int> distance)
    {
        int max = distance[0];
        for (auto& val : distance)
        {
            if (val > max)
            {
                max = val;
            }
        }
        return max;
    }

    bool isInsideMatrix(vector<int> pos, pair<int, int> matrixSize)
    {
        // first => row
        // second => column
        if (pos[0] >= 0 && pos[0] < matrixSize.first && pos[1] >= 0 && pos[1] < matrixSize.second)
        {
            return true;
        }
        return false;
    }

    // write a checking index function

    vector<vector<int>> iterateMatrix(pair<int, int> matrixSize, pair<int, int> initialPos, int maxDistance)
    {
        vector<vector<int>> res;

        int numOfElementAtEdge = 1;
        vector<int> iterateArr = { initialPos.first, initialPos.second };
        for (int i = 0; i <= maxDistance; i++)
        {
            //cout << "ITERATE TIMES: " << i << endl;
            if (i == 0)
            {
                res.push_back(iterateArr);
                //cout << iterateArr[0] << ' ' << iterateArr[1] << endl;
            }
            else
            {
                //cout << "RIGHT SIDE" << endl;
                // right side
                iterateArr[1]++; // to move from the starting point
                for (int i = 0; i < numOfElementAtEdge - 1; i++)
                {
                    if (isInsideMatrix(iterateArr, matrixSize))
                    {
                        res.push_back(iterateArr);
                    }
                    //cout << iterateArr[0] << ' ' << iterateArr[1] << endl;
                    iterateArr[0]++; // move down
                }
                iterateArr[0]--;

                // bottom side
                //cout << "BOTTOM SIDE" << endl;
                for (int i = 0; i < numOfElementAtEdge - 1; i++)
                {
                    iterateArr[1]--; // move left
                    //cout << iterateArr[0] << ' ' << iterateArr[1] << endl;
                    if (isInsideMatrix(iterateArr, matrixSize))
                    {
                        res.push_back(iterateArr);
                    }
                }
                // left side
                //cout << "LEFT SIDE" << endl;
                for (int i = 0; i < numOfElementAtEdge - 1; i++)
                {
                    iterateArr[0]--; // move up
                    //cout << iterateArr[0] << ' ' << iterateArr[1] << endl;
                    if (isInsideMatrix(iterateArr, matrixSize))
                    {
                        res.push_back(iterateArr);
                    }
                }
                // top side
                //cout << "TOP SIDE" << endl;
                for (int i = 0; i < numOfElementAtEdge - 1; i++)
                {
                    iterateArr[1]++; // move right
                    //cout << iterateArr[0] << ' ' << iterateArr[1] << endl;
                    if (isInsideMatrix(iterateArr, matrixSize))
                    {
                        res.push_back(iterateArr);
                    }
                }
            }
            numOfElementAtEdge += 2;
        }
        return res;
    }

    vector<vector<int>> bruteForce(int rows, int cols, int rStart, int cStart) {
        int maxDistance;
        vector<int> distanceFromCenter = {rStart - 0, rows - rStart, cStart - 0, cols - cStart};
        maxDistance = findMaxDistance(distanceFromCenter);
        return iterateMatrix({ rows, cols }, { rStart, cStart }, maxDistance);
    }

    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        return bruteForce(rows, cols, rStart, cStart);
    }
};

int main()
{
    Solution sol;
    int rowsInput = 5, colsInput = 6, rStartInput = 1, cStartInput = 4;
    vector<vector<int>> res = sol.spiralMatrixIII(rowsInput, colsInput, rStartInput, cStartInput);

    cout << "MAIN PROGRAM" << endl;

    for (auto& value : res)
    {
        cout << value[0] << ' ' << value[1] << endl;
    }
}