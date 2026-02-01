/*
Problem Number: 90. Subsets II
Difficulty Level: Medium
Link: https://leetcode.com/problems/subsets-ii

********************************************************************************

Given an integer array nums that may contain duplicates, return all possible
subsets (the power set). The solution set must not contain duplicate subsets.
Return the solution in any order.

Example 1:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:
Input: nums = [0]
Output: [[],[0]]

Constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

#include <algorithm>
#include <vector>

using namespace std;

// Solution 1
class Solution {
  public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> result = {{}};
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int i = 0;
        int count = 0;
        int previousCount = 0;

        while (i < n) {
            count = 0;
            while (i + count < n && nums[i] == nums[i + count]) {
                count++;
            }

            previousCount = result.size();
            for (int k = 0; k < previousCount; k++) {
                vector<int> subset = result[k];

                for (int j = 0; j < count; j++) {
                    subset.push_back(nums[i]);
                    result.push_back(subset);
                }
            }
            i += count;
        }

        return result;
    }
};

// Time Complexity: O(n * 2^n)
// Space Complexity: O(n * 2^n)

// Solution 2
class Solution {
  public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> result = {{}};
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int startIndex = 0;
        int endIndex = 0;

        for (int i = 0; i < n; i++) {
            startIndex = 0;
            if (i > 0 && nums[i - 1] == nums[i]) {
                startIndex = endIndex;
            }

            endIndex = result.size();
            for (int k = startIndex; k < endIndex; k++) {
                vector<int> subset = result[k];
                subset.push_back(nums[i]);
                result.push_back(subset);
            }
        }
        return result;
    }
};

// Time Complexity: O(n * 2^n)
// Space Complexity: O(n * 2^n)