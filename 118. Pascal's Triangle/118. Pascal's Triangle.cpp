#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1)
            return { {1} };
        if (numRows == 2)
        {
            return { {1}, {1,1} };
        }

        vector<vector<int>> pascalTriangle = { { 1 }, { 1,1 } };

        // calculate from the third row
        for (int i = 1; i < numRows - 1; ++i)
        {
            vector<int> calculateRow = { 1 };
	        for (int j = 0; j < i; ++j)
	        {
                calculateRow.push_back(pascalTriangle[i][j] + pascalTriangle[i][j + 1]);
	        }
            calculateRow.push_back(1);
            pascalTriangle.push_back(calculateRow);
        }
        return pascalTriangle;

    }
};

int main()
{
    Solution sol;

    vector<vector<int>> result_vector = sol.generate(10);

    for (const vector<int>& row : result_vector)
    {
	    for (const int& value : row)
	    {
            cout << value << ' ';
	    }
        cout << '\n';
    }
}