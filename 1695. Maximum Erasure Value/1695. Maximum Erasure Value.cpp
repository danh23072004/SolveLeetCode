// 1695. Maximum Erasure Value.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        // Solution using unordered map and sliding window

        vector<int>::iterator left_iter = nums.begin();
        vector<int>::iterator right_iter = nums.begin();
        long sum = 0, max = 0;

        unordered_map<int, bool> is_appeared;

        for (auto element : nums)
        {
            is_appeared[element] = false;
        }

        while (right_iter != nums.end())
        {
            while (is_appeared[*right_iter] != true || left_iter == right_iter)
            {
                sum += *right_iter;
                max = std::max(max, sum);
                is_appeared[*right_iter] = true;
                ++right_iter;
                if (right_iter == nums.end()) break;
            }
            if (right_iter == nums.end()) break;
            while (is_appeared[*right_iter] == true)
            {
                is_appeared[*left_iter] = false;
                sum -= *left_iter;
                ++left_iter;
            }
        }

        return max;
    }
};

int main()
{
    vector<int> test_vector = { 5,2,1,2,5,2,1,2,5 };
    Solution sol;
    cout << "Result: " << sol.maximumUniqueSubarray(test_vector) << endl;
}