/*
Problem Number: 543. Diameter of Binary Tree
Difficulty Level: Easy
Link: https://leetcode.com/problems/diameter-of-binary-tree/

********************************************************************************

Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two
nodes in a tree. This path may or may not pass through the root. The length of a
path between two nodes is represented by the number of edges between them.

Example 1:
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

Example 2:
Input: root = [1,2]
Output: 1

Constraints:
The number of nodes in the tree is in the range [1, 104].
-100 <= Node.val <= 100
*/

#include <algorithm>
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

class Solution {
  public:
    int diameterOfBinaryTree(TreeNode *root) {
        dfs(root);
        return result;
    }

  private:
    int result = 0;
    int dfs(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        int leftSum = dfs(root->left);
        int rightSum = dfs(root->right);

        result = max(result, leftSum + rightSum);
        return 1 + max(leftSum, rightSum);
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)