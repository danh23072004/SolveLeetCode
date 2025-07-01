// 191. Number of 1 Bits.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Solution {
public:
    //int hammingWeight(int n) {
    //    int count = 0;
    //    while (n != 0) {
    //        if (n % 2 == 1)
    //        {
    //            count++;
    //        }
    //        n /= 2;
    //    }
    //    return count;
    //}

    // Bitwise solution
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n != 0) {
            n &= (n - 1);
            count++;
        }
        return count;
    }
};

int main()
{
    Solution sol;
    cout << sol.hammingWeight(128);
}