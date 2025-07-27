#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int count = 0;
	bool direction = true;
    int countHillValley(vector<int>& nums) {
		bool goingUp = false;
		bool goingDown = false;
		int count = 0;

	    for (int i = 0; i < nums.size() - 1; ++i)
	    {
		    if (nums[i+1] > nums[i])
		    {
				goingUp = true;
				if (goingUp && goingDown)
				{
					count++;
					goingDown = false;
				}
		    }
			else if (nums[i+1] < nums[i])
			{
				goingDown = true;
				if (goingUp && goingDown)
				{
					count++;
					goingUp = false;
				}
			}
	    }
		return count;
    }
};

int main()
{
	Solution sol;
	vector<int> test1 = { 2,4,1,1,6,5 };
	vector<int> test2 = { 6,6,5,5,4,1 };

	cout << "Result " << sol.countHillValley(test1) << '\n';
	cout << "Result " << sol.countHillValley(test2) << '\n';

}