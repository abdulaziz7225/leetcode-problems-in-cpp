/*
Problem Number: 257. Binary Tree Paths
Difficulty Level: Easy
Link: https://leetcode.com/problems/binary-tree-paths

********************************************************************************

Given the root of a binary tree, return all root-to-leaf paths in any order.
A leaf is a node with no children.

Example 1:
Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]

Example 2:
Input: root = [1]
Output: ["1"]

Constraints:
The number of nodes in the tree is in the range [1, 100].
-100 <= Node.val <= 100
*/

#include <vector>
#include <string>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> allPaths;
        vector<int> path;
        dfs(root, path, allPaths);
        return allPaths;
    }

private:
    void dfs(TreeNode *root, vector<int> &path, vector<string> &allPaths)
    {
        if (root == nullptr)
        {
            return;
        }

        path.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr)
        {
            allPaths.push_back(build(path));
        }
        else
        {
            dfs(root->left, path, allPaths);
            dfs(root->right, path, allPaths);
        }

        path.pop_back();
    }

    string build(const vector<int> &path)
    {
        string s;
        for (size_t i = 0; i < path.size(); i++)
        {
            if (i > 0)
                s += "->";
            s += to_string(path.at(i));
        }
        return s;
    }
};

// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
