#include <string.h>
#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

    static void TraverseLinkedList(ListNode* head);
};


// This is my original solution
//class Solution {
//public:
//    void AppendNode(ListNode* node1, ListNode* node2)
//    {
//        if (node1 == nullptr || node2 == nullptr)
//            return;
//        else
//        {
//            node1->next = node2;
//        }
//    }
//
//    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//        if (list1 == nullptr)
//        {
//            if (list2 == nullptr)
//                return nullptr;
//            else
//            {
//                return list2;
//            }
//        }
//        else
//        {
//            if (list2 == nullptr)
//                return list1;
//            else
//            {
//
//                // This is the main code for general case
//                ListNode* head = new ListNode(0, nullptr);
//                ListNode* iterateNode = head;
//                // Assign head node
//                if (list1->val < list2->val)
//                {
//                    head->val = list1->val;
//                    list1 = list1->next;
//                }
//                else
//                {
//                    head->val = list2->val;
//                    list2 = list2->next;
//                }
//                // Process the rest of the linked list
//                while (list1 != nullptr && list2 != nullptr)
//                {
//                    if (list1->val < list2->val)
//                    {
//                        ListNode* newNode = new ListNode(list1->val, nullptr);
//                        AppendNode(iterateNode, newNode);
//                        list1 = list1->next;
//                    }
//                    else
//                    {
//                        ListNode* newNode = new ListNode(list2->val, nullptr);
//                        AppendNode(iterateNode, newNode);
//                        list2 = list2->next;
//                    }
//                    iterateNode = iterateNode->next;
//                }
//                while (list1 != nullptr)
//                {
//                    ListNode* newNode = new ListNode(list1->val, nullptr);
//                    AppendNode(iterateNode, newNode);
//                    list1 = list1->next;
//                    iterateNode = iterateNode->next;
//                }
//                while (list2 != nullptr)
//                {
//                    ListNode* newNode = new ListNode(list2->val, nullptr);
//                    AppendNode(iterateNode, newNode);
//                    list2 = list2->next;
//                    iterateNode = iterateNode->next;
//                }
//
//                return head;
//            }
//        }
//    }
//};

// This is the recommend solution
// The complexity is O(n + m)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;

        while (list1 && list2) {
            if (list1->val > list2->val) {
                cur->next = list2;
                list2 = list2->next;
            }
            else {
                cur->next = list1;
                list1 = list1->next;
            }
            cur = cur->next;
        }

        /* This line of code also solves both the general case and edge
        * General case:
        *   - Two list, but one of them will become empty
        *   - Initial with one empty list
        *   - Initial with both of them are empty lists.
        */
        cur->next = list1 ? list1 : list2;

        return dummy->next;
    }
};

// Traverse linked list
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

int main()
{
    // Create a two already sorted linked list for testing
    ListNode* list1 = nullptr;

    ListNode* list2 = new ListNode(0, nullptr);

    ListNode::TraverseLinkedList(list1);
    ListNode::TraverseLinkedList(list2);

    Solution* solution = new Solution();
    ListNode* newSortedMergeList = solution->mergeTwoLists(list1, list2);
    ListNode::TraverseLinkedList(newSortedMergeList);
}


