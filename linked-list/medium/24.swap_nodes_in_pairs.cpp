/*
Problem Number: 24. Swap Nodes in Pairs
Difficulty Level: Medium
Link: https://leetcode.com/problems/swap-nodes-in-pairs/

********************************************************************************

Given a linked list, swap every two adjacent nodes and return its head. You must
solve the problem without modifying the values in the list's nodes (i.e., only
nodes themselves may be changed.)

Example 1:
Input: head = [1,2,3,4]
Output: [2,1,4,3]
Explanation:

Example 2:
Input: head = []
Output: []

Example 3:
Input: head = [1]
Output: [1]

Example 4:
Input: head = [1,2,3]
Output: [2,1,3]

Constraints:
The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr) {
            return head;
        }

        ListNode *dummy = new ListNode(0, head);
        ListNode *prev = dummy;
        ListNode *curr = head;

        while (curr != nullptr && curr->next != nullptr) {
            ListNode *temp = curr->next;
            curr->next = temp->next;
            prev->next = temp;
            temp->next = curr;

            prev = curr;
            curr = curr->next;
        }

        ListNode *result = dummy->next;
        delete dummy;
        return result;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
