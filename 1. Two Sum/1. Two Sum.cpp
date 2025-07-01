#include <string.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    vector<int> firstApproach(vector<int>& nums, int target)
    {
        // using brute force
        vector<int> ans;
        int size = nums.size();
        for (size_t i = 0; i < nums.size(); i++)
        {
            for (size_t j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target && i != j)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
    };

    bool binarySearch(int findNum, vector<pair<int, int>>& list, int& pos)
    {
        // find location of findNum
        int left = 0;
        int right = list.size() - 1;
        int mid = 0;
        while (left <= right)
        {
            // attention: mid = (right - left) / 2 is wrong
            mid = (right + left) / 2; 
            if (findNum < list[mid].first)
            {
                right = mid - 1;
            }
            else if (list[mid].first < findNum)
            {
                left = mid + 1;
            }
            else
            {
                pos = list[mid].second;
                return true;
            }
        }
        return false;
    };

    vector<int> secondApproach(vector<int>& nums, int target)
    {
        // using sort and binary search to reduce time complexity
        vector<pair<int, int>> list;
        for (int i = 0; i < nums.size(); i++)
        {
            list.push_back({ nums[i], i });
        }
        sort(list.begin(), list.end());
        int pos;
        for (int i = 0; i < list.size(); i++)
        {
            pos = -1;
            if (binarySearch(target - list[i].first, list, pos) == true)
            {
                if (pos != list[i].second)
                {
                    if (list[i].second < pos)
                    {
                        return { list[i].second, pos };
                    }
                    else
                    {
                        return { pos, list[i].second};
                    }
                }
                else
                {
                    /*
                    * This part is only for the case when
                    * - There is no answer in the test case
                    * - There is an element in an array can duplicate to fake the target
                    */
                    if (0 < i && i <= list.size() - 1 && list[i].first == list[i - 1].first)
                    {
                        if (list[i].second < list[i - 1].second)
                        {
                            return { list[i].second, list[i - 1].second };
                        }
                        else
                        {
                            return { list[i - 1].second, list[i].second};
                        }
                    }
                    else if (i >= 0 && i < list.size() - 1 && list[i].first == list[i + 1].first)
                    {
                        if (list[i].second < list[i + 1].second)
                        {
                            return { list[i].second, list[i + 1].second };
                        }
                        else
                        {
                            return { list[i + 1].second, list[i].second };
                        }
                    }
                    else
                    {
                        return {};
                    }
                }
            }
        }


        return {};
    };

    vector<int> twoSum(vector<int>& nums, int target) {
        //return firstApproach(nums, target);
        return secondApproach(nums, target);
    };
};

//class Solution {
//public:
//    bool binarysearch(vector<int>& nums, int target)
//    {
//        int low = 0;
//        int high = nums.size() - 1;
//        while (low <= high)
//        {
//            int mid = low + ((high - low) / 2);
//            if (nums[mid] == target)
//            {
//                return true;
//            }
//            else if (nums[mid] > target)
//            {
//                high = mid - 1;
//            }
//            else
//            {
//                low = mid + 1;
//            }
//        }
//        return false;
//    }
//
//    vector<int> twoSum(vector<int>& nums, int target) {
//        vector<int> original = nums;
//        sort(nums.begin(), nums.end());
//        vector<int> ans;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            if (binarysearch(nums, target - nums[i]))
//            {
//                ans.push_back(nums[i]);
//                ans.push_back(target - nums[i]);
//                break;
//            }
//        }
//        if (ans.size() == 2) {
//            vector<int> result;
//            for (int i = 0; i < original.size(); i++) {
//                if (original[i] == ans[0] || original[i] == ans[1]) {
//                    result.push_back(i);
//                }
//            }
//            return result;
//        }
//        return {};
//    }
//};

int main()
{
    /* There are 3 solutions for this 
    1 => brute forces
    2 => first element search through, second element use binary search
    3 => using hashmap, when accessing an element, immediately find the next element
    whether it's been stored in the hashmap, retrieve it
    */

    vector<int> test{ 3,2,3 };
    Solution* sol = new Solution();
    vector<int> result = sol->twoSum(test, 6);
    cout << result[0] << ' ' << result[1] << endl;
    

    //int numPos = 0;
    //if (sol->binarySearch(3, numPos, test))
    //{
    //    cout << "TRUE" << endl;
    //    cout << numPos;
    //}
    //else
    //{
    //    cout << "FALSE" << endl;
    //}
}