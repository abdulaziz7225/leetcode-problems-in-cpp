/*
Problem Number: 78. Subsets
Difficulty Level: Medium
Link: https://leetcode.com/problems/subsets/editorial/

********************************************************************************

Given an integer array nums of unique elements, return all possible subsets (the
power set). The solution set must not contain duplicate subsets. Return the
solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]

Constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
*/

#include <bitset>
#include <cmath>
#include <vector>

using namespace std;

// Solution 1: Iterative approach
class Solution {
  public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> result = {{}};

        for (auto num : nums) {
            vector<vector<int>> newSubset;

            for (auto curr : result) {
                vector<int> temp = curr;
                temp.push_back(num);
                newSubset.push_back(temp);
            }

            for (auto curr : newSubset) {
                result.push_back(curr);
            }
        }

        return result;
    }
};

// Time Complexity: O(n * 2^n)
// Space Complexity: O(n * 2^n)

// Solution 2: Backtracking approach
class Solution {
  public:
    vector<vector<int>> subsets(vector<int> &nums) {
        n = nums.size();
        backtrack(0, curr, nums);
        return result;
    }

  private:
    vector<vector<int>> result;
    vector<int> curr;
    int n;
    void backtrack(int first, vector<int> &curr, vector<int> &nums) {
        result.push_back(curr);

        for (int i = first; i < n; i++) {
            curr.push_back(nums[i]);
            backtrack(i + 1, curr, nums);
            curr.pop_back();
        }
    };
};

// Time Complexity: O(n * 2^n)
// Space Complexity: O(n * 2^n + n) ==> O(n * 2^n)

// Solution 3: Lexicographic (Binary Sorted) Subsets
class Solution {
  public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> result;
        int n = nums.size();

        for (int i = pow(2, n); i < pow(2, n + 1); i++) {
            string bitmask = bitset<32>(i).to_string().substr(32 - n);

            vector<int> subset;
            for (int j = 0; j < n; j++) {
                if (bitmask[j] == '1') {
                    subset.push_back(nums[j]);
                }
            }
            result.push_back(subset);
        }

        return result;
    }
};

// Time Complexity: O(n * 2^n)
// Space Complexity: O(n * 2^n)