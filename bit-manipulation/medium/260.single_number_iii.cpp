/*
Problem Number: 260. Single Number III
Difficulty Level: Medium
Link: https://leetcode.com/problems/single-number-iii/

********************************************************************************

Given an integer array nums, in which exactly two elements appear only once and
all the other elements appear exactly twice. Find the two elements that appear
only once. You can return the answer in any order. You must write an algorithm
that runs in linear runtime complexity and uses only constant extra space.

Example 1:
Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.

Example 2:
Input: nums = [-1,0]
Output: [-1,0]

Example 3:
Input: nums = [0,1]
Output: [1,0]

Constraints:
2 <= nums.length <= 3 * 10^4
-2^31 <= nums[i] <= 2^31 - 1
Each integer in nums will appear twice, only two integers will appear once.
*/

#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> singleNumber(vector<int> &nums) {
        int xorOfPairs = 0;
        for (int num : nums) {
            xorOfPairs ^= num;
        }

        int diffBit = 1;
        while (!(xorOfPairs & diffBit)) {
            diffBit = diffBit << 1;
        }

        int first = 0;
        int second = 0;
        for (int num : nums) {
            if (num & diffBit) {
                first ^= num;
            } else {
                second ^= num;
            }
        }

        return {first, second};
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
