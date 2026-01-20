/*
Problem Number: 82. Remove Duplicates from Sorted List II
Difficulty Level: Medium
Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

********************************************************************************

Given the head of a sorted linked list, delete all nodes that have duplicate
numbers, leaving only distinct numbers from the original list. Return the linked
list sorted as well.

Example 1:
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

Example 2:
Input: head = [1,1,1,2,3]
Output: [2,3]

Constraints:
The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}
};

class Solution {
  public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr) {
            return head;
        }

        ListNode *dummy = new ListNode(0, head);
        ListNode *prev = dummy;
        ListNode *curr = head;

        while (curr != nullptr) {
            while (curr->next != nullptr && curr->val == curr->next->val) {
                curr = curr->next;
            }

            if (prev->next == curr) {
                prev = curr;
            } else {
                prev->next = curr->next;
            }
            curr = curr->next;
        }

        ListNode *result = dummy->next;
        delete dummy;
        return result;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
