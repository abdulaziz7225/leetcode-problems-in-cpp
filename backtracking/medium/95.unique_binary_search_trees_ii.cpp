/*
Problem Number: 95. Unique Binary Search Trees II
Difficulty Level: Medium
Link: https://leetcode.com/problems/unique-binary-search-trees-ii

********************************************************************************

Given an integer n, return all the structurally unique BST's (binary search
trees), which has exactly n nodes of unique values from 1 to n. Return the
answer in any order.

Example 1:
Input: n = 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]

Example 2:
Input: n = 1
Output: [[1]]

Constraints:
1 <= n <= 8
*/

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

// Solution 1: Recursive Dynamic Programming without hashmap
class Solution {
  public:
    vector<TreeNode *> generateTrees(int n) { return allPossibleBST(1, n); }

  private:
    vector<TreeNode *> allPossibleBST(int start, int end) {
        if (start == end) {
            TreeNode *node = new TreeNode(start);
            return {node};
        }
        if (start > end) {
            return {nullptr};
        }

        vector<TreeNode *> result;

        for (int rootVal = start; rootVal <= end; rootVal++) {
            vector<TreeNode *> leftSubtrees =
                allPossibleBST(start, rootVal - 1);
            vector<TreeNode *> rightSubtrees = allPossibleBST(rootVal + 1, end);

            for (auto left : leftSubtrees) {
                for (auto right : rightSubtrees) {
                    TreeNode *node = new TreeNode(rootVal, left, right);
                    result.push_back(node);
                }
            }
        }
        return result;
    }
};

// Time Complexity: O(4^n / sqrt(n))
// Space Complexity: O(4^n / sqrt(n))

// Solution 2: Recursive Dynamic Programming with hashmap
class Solution {
  public:
    vector<TreeNode *> generateTrees(int n) { return allPossibleBST(1, n); }

  private:
    unordered_map<string, vector<TreeNode *>> memo;
    vector<TreeNode *> allPossibleBST(int start, int end) {
        string key = to_string(start) + "," + to_string(end);
        if (memo.count(key)) {
            return {memo[key]};
        }
        if (start > end) {
            return {nullptr};
        }

        vector<TreeNode *> result;

        for (int rootVal = start; rootVal <= end; rootVal++) {
            vector<TreeNode *> leftSubtrees =
                allPossibleBST(start, rootVal - 1);
            vector<TreeNode *> rightSubtrees = allPossibleBST(rootVal + 1, end);

            for (auto left : leftSubtrees) {
                for (auto right : rightSubtrees) {
                    TreeNode *node = new TreeNode(rootVal, left, right);
                    result.push_back(node);
                }
            }
        }
        memo[key] = result;
        return result;
    }
};

// Time Complexity: O(4^n / sqrt(n))
// Space Complexity: sum((n - k + 1) * 4^k / sqrt(k)) when k is from 1 to n