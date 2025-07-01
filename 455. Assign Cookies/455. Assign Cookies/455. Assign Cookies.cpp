// 455. Assign Cookies.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // sorting first

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        // Iterate from lowest to largest


    }
};

int main()
{
    Solution sol;

    vector<int> g = { 1,2,3 };
    vector<int> s = { 1,1 };

    cout << sol.findContentChildren(g,s);
}