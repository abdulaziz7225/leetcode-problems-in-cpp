/*
Problem Number: 129. Sum Root to Leaf Numbers
Difficulty Level: Medium
Link: https://leetcode.com/problems/sum-root-to-leaf-numbers/

********************************************************************************

You are given the root of a binary tree containing digits from 0 to 9 only.
Each root-to-leaf path in the tree represents a number.
For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so
that the answer will fit in a 32-bit integer. A leaf node is a node with no
children.

Example 1:
Input: root = [1,2,3]
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.

Example 2:
Input: root = [4,9,0,5,1]
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.

Constraints:
The number of nodes in the tree is in the range [1, 1000].
0 <= Node.val <= 9
The depth of the tree will not exceed 10.
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

// Solution 1
class Solution {
  public:
    int sumNumbers(TreeNode *root) {
        int result = 0;
        vector<int> path;
        dfs(root, path, result);
        return result;
    }

  private:
    void dfs(TreeNode *root, vector<int> &path, int &result) {
        if (root == nullptr) {
            return;
        }

        path.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            result += buildNumber(path);
        } else {
            dfs(root->left, path, result);
            dfs(root->right, path, result);
        }

        path.pop_back();
    }

    int buildNumber(const vector<int> &path) {
        int number = 0;

        for (size_t i = 0; i < path.size(); i++) {
            number = 10 * number + path.at(i);
        }
        return number;
    }
};

// Time Complexity: O(n^2)
// Space Complexity: O(n^2)

// Solution 2: Optimized Approach
class Solution {
  public:
    int sumNumbers(TreeNode *root) { return dfs(root, 0); }

  private:
    int dfs(TreeNode *root, int currSum) {
        if (root == nullptr) {
            return 0;
        }

        currSum = 10 * currSum + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return currSum;
        }

        return dfs(root->left, currSum) + dfs(root->right, currSum);
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
