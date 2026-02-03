/*
Problem Number: 47. Permutations II
Difficulty Level: Medium
Link: https://leetcode.com/problems/permutations-ii

********************************************************************************

Given a collection of numbers, nums, that might contain duplicates, return all
possible unique permutations in any order.

Example 1:
Input: nums = [1,1,2]
Output:
[[1,1,2],
[1,2,1],
[2,1,1]]

Example 2:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Constraints:
1 <= nums.length <= 8
-10 <= nums[i] <= 10
*/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<int> perm;

        length = nums.size();
        for (int num : nums) {
            counter[num]++;
        }

        backtrack(perm);
        return result;
    }

  private:
    int length;
    vector<vector<int>> result;
    unordered_map<int, int> counter;

    void backtrack(vector<int> &perm) {
        if (perm.size() == length) {
            result.push_back(perm);
            return;
        }

        for (auto &item : counter) {
            int num = item.first;
            int &freq = item.second;

            if (freq < 1) {
                continue;
            }

            perm.push_back(num);
            freq--;

            backtrack(perm);

            perm.pop_back();
            freq++;
        }
    }
};

// Time Complexity: O(n * n!)
// Space Complexity: O(n * n! + 3 * n) ==> O(n * n!)
