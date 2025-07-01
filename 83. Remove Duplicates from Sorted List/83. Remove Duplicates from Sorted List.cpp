
#include <iostream>
#include <string.h>

using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

    static void TraverseLinkedList(ListNode* head);
};

void ListNode::TraverseLinkedList(ListNode* head)
{
    cout << "--- Start Traversing linked list ---";
    while (head != nullptr)
    {
        cout << '\n';
        cout << head->val << ' ';
        head = head->next;
    }
    cout << "\n--- End Traversing linked list ---\n";
}

class Solution {
public:
    // true => value already existed within array
    // false => value not existed
    bool isExist(int num, bool* checkingArr)
    {
        return checkingArr[num + 100];
    }

    void setExist(int num, bool* checkingArr)
    {
        checkingArr[num + 100] = true;
    }

    ListNode* createLinkedList(int* arr, int length)
    {
        ListNode* head = new ListNode(arr[0], nullptr);
        if (length == 1)
        {
            return head;
        }
        else
        {
            ListNode* iterator = head;
            for (int i = 1; i < length; i++)
            {
                ListNode* newNode = new ListNode(arr[i], nullptr);
                iterator->next = newNode;
                iterator = iterator->next;
            }
            return head;
        }
    }

    ListNode* deleteDuplicates(ListNode* head) {
        // List with only one element has no duplicate
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* iterator = head;

        bool* checkingArr = new bool[201] {false};
        setExist(head->val, checkingArr);

        while (iterator != nullptr && iterator->next != nullptr)
        {
            if (isExist(iterator->next->val, checkingArr) == true)
            {
                // delete duplicate node (head->next)
                ListNode* deleteNode = iterator->next;
                if (iterator->next->next != nullptr)
                {
                    iterator->next = iterator->next->next;
                }
                else
                {
                    iterator->next = nullptr;
                }
                delete deleteNode;
            }
            else
            {
                setExist(iterator->next->val, checkingArr);
                iterator = iterator->next;
            }
        }
        return head;
    }
};

int main()
{
    Solution* sol = new Solution();
    int* arr = new int[3] {1, 1, 1};
    //int* arr = nullptr;
    ListNode* testLinkedList = sol->createLinkedList(arr, 3);
    ListNode::TraverseLinkedList(testLinkedList);

    sol->deleteDuplicates(testLinkedList);
    ListNode::TraverseLinkedList(testLinkedList);
}