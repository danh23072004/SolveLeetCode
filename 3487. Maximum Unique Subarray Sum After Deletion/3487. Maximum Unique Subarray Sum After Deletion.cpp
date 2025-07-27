#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        int max = nums[0];
        for (int i = 1; i < nums.size(); ++i) max = std::max(max, nums[i]);
        if (max < 0)
        {
            return max;
        }

        // A hash map to store already counted numbers
        unordered_map<short, bool> isCounted;
        int sum = 0;
        bool positiveFlag = false;

        for (int i = 0; i < nums.size(); ++i)
        {
	        if (nums[i] > 0 && isCounted[nums[i]] == false)
	        {
                isCounted[nums[i]] = true;
                sum += nums[i];
	        }
        }
        return sum;
    }
};

int main()
{
    Solution sol;
    vector<int> test1 = { 1,2,-1,-2,1,0,-1 };
    cout << "Result: " << sol.maxSum(test1) << endl;

    vector<int> test2 = { -100 };
    cout << "Result: " << sol.maxSum(test2) << endl;
}