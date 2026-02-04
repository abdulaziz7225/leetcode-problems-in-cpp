/*
Problem Number: 96. Unique Binary Search Trees
Difficulty Level: Medium
Link: https://leetcode.com/problems/unique-binary-search-trees

********************************************************************************

Given an integer n, return the number of structurally unique BST's (binary
search trees) which has exactly n nodes of unique values from 1 to n.

Example 1:
Input: n = 3
Output: 5

Example 2:
Input: n = 1
Output: 1

Constraints:
1 <= n <= 19
*/

#include <vector>

using namespace std;

class Solution {
  public:
    int numTrees(int n) {
        vector<int> uniqTrees(n + 1, 1);

        for (int nodes = 2; nodes <= n; nodes++) {
            int total = 0;
            for (int root = 1; root <= nodes; root++) {
                total += uniqTrees[root - 1] * uniqTrees[nodes - root];
            }
            uniqTrees[nodes] = total;
        }

        return uniqTrees[n];
    }
};

// Time Complexity: O(n^2)
// Space Complexity: O(n)
