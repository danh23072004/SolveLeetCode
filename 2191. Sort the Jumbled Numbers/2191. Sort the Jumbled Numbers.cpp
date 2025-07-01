#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Solution {
public:

    int convert(int a, vector<int>& mapping)
    {
        if (a == 0)
        {
            return mapping[0];
        }
        int digitNum = 1, newNum = 0, res = 0;
        while (a != 0)
        {
            newNum = a % 10;
            a = a / 10;
            newNum = mapping[newNum];
            res = res + newNum * digitNum;
            digitNum = digitNum * 10;
        }
        return res;
    }

    void merge(std::vector<pair<int, int>>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        std::vector<pair<int, int>> L(n1);
        std::vector<pair<int, int>> R(n2);

        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        int i = 0;
        int j = 0;
        int k = left;
        while (i < n1 && j < n2) {
            if (L[i].second <= R[j].second) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    void mergeSort(vector<pair<int, int>>& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }

    vector<int> mySolution(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> pairNums;
        for (int i = 0; i < nums.size(); i++)
        {
            pairNums.push_back({ nums[i], convert(nums[i], mapping) });
        }

        mergeSort(pairNums, 0, nums.size() - 1);

        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            res.push_back(pairNums[i].first);
        }

        return res;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        return mySolution(mapping, nums);
    }
};

int main()
{
    Solution sol;
    vector<int> mapping{ 9,8,7,6,5,4,3,2,1,0 };
    vector<int> nums{ 0,1,2,3,4,5,6,7,8,9 };
    vector<int> result = sol.sortJumbled(mapping, nums);

    for (auto& i : result)
    {
        cout << i << ' ';
    }

    cout << endl;
}
