/*
Problem Number: 46. Permutations
Difficulty Level: Medium
Link: https://leetcode.com/problems/permutations

********************************************************************************

Given an array nums of distinct integers, return all the possible permutations.
You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]

Constraints:
1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
*/

#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

// Solution 1
class Solution {
  public:
    vector<vector<int>> permute(vector<int> &nums) {
        queue<int> q;
        for (int num : nums) {
            q.push(num);
        }
        return backtrack(q);
    }

  private:
    vector<vector<int>> backtrack(queue<int> &q) {
        if (q.size() == 1) {
            return {{q.front()}};
        }

        vector<vector<int>> result;
        for (int i = 0; i < q.size(); i++) {
            int curr = q.front();
            q.pop();

            vector<vector<int>> permutations = backtrack(q);
            for (auto &perm: permutations) {
                perm.push_back(curr);
                result.push_back(perm);
            }

            q.push(curr);
        }

        return result;
    }
};
// Time Complexity: O(n * n!)
// Space Complexity: O(n * n!)

// Solution 2
class Solution {
  public:
    vector<vector<int>> permute(vector<int> &nums) {
        backtrack(0, nums);
        return result;
    }

  private:
    vector<vector<int>> result;
    void backtrack(int start, vector<int> &nums) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);
            backtrack(start + 1, nums);
            swap(nums[start], nums[i]);
        }
    }
};

// Time Complexity: O(n * n!)
// Space Complexity: O(n * n!)
