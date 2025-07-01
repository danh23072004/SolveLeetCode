#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// Implement a customize stack by myself

class StackInteger
{
private:
    // array-based stack
    int* array;
    int size;
    int iterator;

    int safe_size_t_to_int(size_t value) {
        if (value > static_cast<size_t>(std::numeric_limits<int>::max())) {
            throw std::out_of_range("size_t value is too large to fit in an int");
        }
        return static_cast<int>(value);
    }
public:
    // empty stack
    StackInteger(size_t newSize) : size(safe_size_t_to_int(newSize)), iterator(0), array(new int[newSize] {0}) {};

    // initialize stack with values
    StackInteger(size_t newSize, vector<int> inputVector) : size(safe_size_t_to_int(newSize)), iterator(0), array(new int [newSize] {0})
    {
        // order of elements from left to right
        for (int i = 0; i < newSize; i++)
        {
            array[i] = inputVector[i];
        }
        iterator = size - 1;
    }

    void push(int val)
    {
        array[iterator] = val;
        iterator++;
    }

    void pop()
    {
        iterator--;
    }

    int top()
    {
        return array[iterator];
    }

    void clearStack()
    {
        for (int i = 0; i < iterator; i++)
        {
            array[i] = 0;
        }
        iterator = 0;
    }
};

class Solution {
public:
    // my solution is a brute force O(n.m)
    vector<int> myBruteForceSolution(vector<int>& nums1, vector<int>& nums2) {
        int greater, topStack;
        vector<int> result;
        for (const auto& val : nums1)
        {
            greater = -1;
            StackInteger stack(nums2.size(), nums2);
            topStack = stack.top();
            while (topStack != val)
            {
                if (topStack > val)
                {
                    greater = topStack;
                }
                stack.pop();
                topStack = stack.top();
            }
            result.push_back(greater);
        }
        return result;
    }

    vector <int> monotonicStackSolutionWithHash(vector<int>& nums1, vector<int>& nums2) {
        /* basic hash table based on values in nums1 array
        */ 

        bool* appearArr = new bool[1001] {false};
        for (int i = 0; i < nums1.size(); i++)
        {
            appearArr[nums1[i]] = true;
        }

        StackInteger stack()

        for (auto& number : nums2)
        {
            if (appearArr[number] == true)
            {

            }
        }
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        return myBruteForceSolution(nums1, nums2);
    }
};

int main()
{
    Solution sol;
    vector<int> nums1{ 4,1,2 };
    vector<int> nums2{ 1,3,4,2 };

    vector<int> result = sol.nextGreaterElement(nums1, nums2);

    for (auto& i : result)
    {
        cout << i << ' ';
    }
    cout << endl;
}