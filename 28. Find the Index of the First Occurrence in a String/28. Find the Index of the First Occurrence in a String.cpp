#include <string.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

//Example 1:
//
//Input: haystack = "sadbutsad", needle = "sad"
//Output : 0
//Explanation : "sad" occurs at index 0 and 6.
//The first occurrence is at index 0, so we return 0.
//Example 2 :
//
//    Input : haystack = "leetcode", needle = "leeto"
//    Output : -1
//    Explanation : "leeto" did not occur in "leetcode", so we return -1.

class Solution {
public:

    int isSubStr(string& a, string& b)
    {
        return a == b;
    }

    int strStr(string haystack, string needle) {
        // size chuỗi cần tìm nhỏ hơn size chuỗi chứa chuỗi cần tìm
        if (haystack.length() < needle.length())
        {
            return -1;
        }
        vector<int> saveIndex;

        // duyệt để tìm các vị trí có thể của chữ cái đầu của chuỗi cần tìm
        for (int i = 0; i < haystack.length() - needle.length() + 1; i++)
        {
            if (needle[0] == haystack[i])
            {
                saveIndex.push_back(i);
            }
        }

        // haystack => n
        // needle => m

        // Kiểm tra các ứng viên có bằng chuỗi cần tìm không?
        // O(n.2m)
        for (int i = 0; i < saveIndex.size(); i++)
        {
            // O(m)
            string checkStr = haystack.substr(saveIndex[i], needle.length());
            // O(m)
            if (isSubStr(checkStr, needle))
            {
                return saveIndex[i];
            }
        }
        return -1;
    }
};

int main()
{
    Solution* sol = new Solution();
    cout << sol->strStr("abb", "abaaa");
}