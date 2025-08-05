#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // baskets order can't be change

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {

	    for (const int& fruit : fruits)
	    {
		    for (int& basket : baskets)
		    {
			    if (fruit <= basket && basket != -1)
			    {
					basket = -1;
					break;
			    }
		    }
	    }
		int result = 0;
	    for (const int& basket : baskets)
	    {
			if (basket == -1) result++;
	    }
		return baskets.size() - result;
    }
};

int main()
{
    vector<int> fruits = { 4,2,5 };
    vector<int> baskets = { 3,5,4 };
    Solution sol;
    cout << "Result: " << sol.numOfUnplacedFruits(fruits, baskets);
}