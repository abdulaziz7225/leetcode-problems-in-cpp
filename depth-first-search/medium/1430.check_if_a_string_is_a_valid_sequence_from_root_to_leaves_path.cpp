/*
Problem Number: 1430. Check If a String Is a Valid Sequence from Root to Leaves
Path in a Binary Tree Difficulty Level: Medium Link:
https://leetcode.com/problems/check-if-a-string-is-a-valid-sequence-from-root-to-leaves-path-in-a-binary-tree

********************************************************************************

Given a binary tree where each path going from the root to any leaf form a valid
sequence, check if a given string is a valid sequence in such binary tree. We
get the given string from the concatenation of an array of integers arr and the
concatenation of all values of the nodes along a path results in a sequence in
the given binary tree.

Example 1:
Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,0,1]
Output: true
Explanation:
The path 0 -> 1 -> 0 -> 1 is a valid sequence (green color in the figure).
Other valid sequences are:
0 -> 1 -> 1 -> 0
0 -> 0 -> 0

Example 2:
Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,0,1]
Output: false
Explanation: The path 0 -> 0 -> 1 does not exist, therefore it is not even a
sequence.

Example 3:
Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,1]
Output: false
Explanation: The path 0 -> 1 -> 1 is a sequence, but it is not a valid sequence.

Constraints:
1 <= arr.length <= 5000
0 <= arr[i] <= 9
Each node's value is between [0 - 9]
*/

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

class Solution {
  public:
    bool isValidSequence(TreeNode *root, vector<int> &arr) {
        return dfs(root, arr, 0);
    }

  private:
    bool dfs(TreeNode *root, const vector<int> &arr, int currIndex) {
        if (root == nullptr || root->val != arr[currIndex]) {
            return false;
        }

        if (currIndex == arr.size() - 1) {
            return root->left == nullptr && root->right == nullptr;
        }

        return dfs(root->left, arr, currIndex + 1) ||
               dfs(root->right, arr, currIndex + 1);
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
