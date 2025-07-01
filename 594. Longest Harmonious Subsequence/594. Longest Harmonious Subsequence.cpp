#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:

    int bruteForce(vector<int>& nums) {
        int maxLength = 0;
        int countLower, countUpper;

        for (int i = 0; i < nums.size(); i++)
        {
            countLower = 1;
            countUpper = 1;
            bool isUpperEqual = true, isLowerEqual = true;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] - nums[j] == 1) {
                    countUpper++;
                    isUpperEqual = false;
                }
                if (nums[i] - nums[j] == -1) {
                    countLower++;
                    isLowerEqual = false;
                }
                if (nums[i] - nums[j] == 0) {
                    countUpper++;
                    countLower++;
                }
            }
            if (!isUpperEqual) maxLength = max(maxLength, countUpper);
            if (!isLowerEqual) maxLength = max(maxLength, countLower);
        }

        return maxLength;
    }

    int useCountingArray(vector<int>& nums) {
        int maxLength = 0;
        unordered_map<int, int> countNum;

        for (int i = 0; i < nums.size(); i++) countNum[nums[i]]++;


        for (int i = 0; i < nums.size(); i++)
        {
            if (countNum[nums[i] + 1] > 0)
                maxLength = max(countNum[nums[i]] + countNum[nums[i] + 1], maxLength);
            if (countNum[nums[i] - 1] > 0)
                maxLength = max(countNum[nums[i]] + countNum[nums[i] - 1], maxLength);
        }
        return maxLength;
    }

    int combineSlidingWindowAndSorting(vector<int>& nums) {
        int maxLength = 0;
        sort(nums.begin(), nums.end());

        // after sorting -> 1 2 2 2 3 3 5 7
        vector<int>::iterator leftIter = nums.begin();
        vector<int>::iterator rightIter = leftIter;

        while (rightIter != nums.end()) {
            while (rightIter != nums.end() && *rightIter - *leftIter == 0) rightIter++;
            while (rightIter != nums.end() && *rightIter - *leftIter == 1) {
                maxLength = max(maxLength, int(rightIter - leftIter + 1));
                rightIter++;
            }
            while (rightIter != nums.end() && *rightIter - *leftIter > 1) leftIter++;
        }

        return maxLength;
    }

    int findLHS(vector<int>& nums) {
        //return bruteForce(nums);
        //return useCountingArray(nums);
        return combineSlidingWindowAndSorting(nums);
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1,3,2,2,5,2,3,7 };
    cout << s.findLHS(nums) << endl;

    nums = { 1,2,3,4};
    cout << s.findLHS(nums) << endl;

    nums = { 1,1,1,1};
    cout << s.findLHS(nums) << endl;
}