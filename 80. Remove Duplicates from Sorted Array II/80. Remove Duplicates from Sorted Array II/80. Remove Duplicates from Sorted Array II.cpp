#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Return the number of elements, directly alter the nums
    int removeDuplicates(vector<int>& a) {
        int countDuplicate = 0;
        vector<bool> flagArr;

        for (int i = 0; i < a.size(); i++)
        {
            flagArr.push_back(true);
        }

        int totalRemoval = 0;
        for (int i = 1; i < a.size(); i++)
        {
            if (a[i] == a[i - 1])
            {
                countDuplicate++;
                if (countDuplicate >= 2)
                {
                    totalRemoval++;
                    flagArr[i] = false;
                }
            }
            else
            {
                countDuplicate = 0;
            }
        }

        int removeNumIndex = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (flagArr[i] == false)
            {
                removeNumIndex++;
            }
            else
            {
                a[i - removeNumIndex] = a[i];
            }
        }

        return a.size() - totalRemoval;
    }
};

int main()
{
    Solution* sol = new Solution();
    vector<int> test_arr = { 0,0,1,1,1,1,2,3,3 };

    cout << sol->removeDuplicates(test_arr) << endl;

    for (int i = 0; i < test_arr.size(); i++)
    {
        cout << test_arr[i] << ' ';
    }
}