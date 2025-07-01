#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node
{
public:
	Node(int val, Node* nextPtr) : value(val), next(nextPtr)
	{

	};
	int value;
	Node* next;
};

class KthLargest
{
private:
	Node* head;
	int currentK;
public:
	KthLargest(int k, vector<int>& nums) : currentK(k)
	{
		sort(nums.begin(), nums.end());
		head = new Node(nums[0], nullptr);
		Node* iterator = head;
		for (int i = 1; i < nums.size(); i++)
		{
			iterator->next = new Node(nums[i], nullptr);
			iterator = iterator->next;
		}
	}

	void traverseLinkedList()
	{
		Node* iterator = head;
		cout << "print linked list" << endl;
		while (iterator != nullptr)
		{
			cout << iterator->value << ' ';
			iterator = iterator->next;
		}
		cout << "\ncompleted print linked list" << endl;
	}

	int add(int val)
	{
		Node* iterator = head;
		while (iterator != nullptr)
		{

		}
	}
};

int main()
{
	int k = 3;
	vector<int> nums = { 4, 5, 8, 2 };
	KthLargest* obj = new KthLargest(k, nums);

	obj->traverseLinkedList();

	//vector<int> addNumbers = { 3, 5, 10, 9, 4 };
	//for (int value : addNumbers)
	//{
	//	cout << "Add: " << value << endl;
	//	cout << "Largest kth element: " << obj->add(value);
	//}
}