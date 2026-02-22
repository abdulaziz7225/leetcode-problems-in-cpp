/*
Problem Number: 23. Merge k Sorted Lists
Difficulty Level: Hard
Link: https://leetcode.com/problems/merge-k-sorted-lists

********************************************************************************

You are given an array of k linked-lists lists, each linked-list is sorted in
ascending order. Merge all the linked-lists into one sorted linked-list and
return it.

Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
1->4->5,
1->3->4,
2->6
]
merging them into one sorted linked list:
1->1->2->3->4->4->5->6

Example 2:
Input: lists = []
Output: []

Example 3:
Input: lists = [[]]
Output: []

Constraints:
k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 10^4.
*/

#include <queue>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution 1: Heap Priority Queue
class Solution {
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) {
            return nullptr;
        }
        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>,
                       greater<pair<int, ListNode *>>>
            minHeap;

        ListNode *dummy = new ListNode();
        ListNode *curr = dummy;

        for (auto node : lists) {
            if (node != nullptr) {
                minHeap.push({node->val, node});
            }
        }

        while (!minHeap.empty()) {
            ListNode *minNode = minHeap.top().second;
            minHeap.pop();

            curr->next = minNode;
            curr = curr->next;

            if (minNode->next != nullptr) {
                minHeap.push({minNode->next->val, minNode->next});
            }
        }

        ListNode *result = dummy->next;
        delete dummy;
        return result;
    }
};

// n = total count of numbers, k = number of linked lists
// Time Complexity: O(k * log(k) + (n - k) * log(k)) ==> O(n * log(k))
// Space Complexity: O(k)

// Solution 2: Merge two linked lists at a time
class Solution {
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) {
            return nullptr;
        }

        while (lists.size() > 1) {
            vector<ListNode *> mergedLists;
            for (int index = 0; index < lists.size(); index += 2) {
                ListNode *list1 = lists[index];
                ListNode *list2 =
                    index + 1 < lists.size() ? lists[index + 1] : nullptr;
                mergedLists.push_back(mergeTwoSortedLists(list1, list2));
            }
            lists = move(mergedLists);
        }
        return lists[0];
    }

  private:
    ListNode *mergeTwoSortedLists(ListNode *list1, ListNode *list2) {
        ListNode *dummy = new ListNode();
        ListNode *curr = dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }

            curr = curr->next;
        }

        if (list1 != nullptr) {
            curr->next = list1;
        }
        if (list2 != nullptr) {
            curr->next = list2;
        }

        ListNode *result = dummy->next;
        delete dummy;
        return result;
    }
};

// n = total count of numbers, k = number of linked lists
// Time Complexity: O(n * log(k))
// Space Complexity: O(k)
