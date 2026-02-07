/*
Problem Number: 34. Find First and Last Position of Element in Sorted Array
Difficulty Level: Medium
Link:
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

********************************************************************************

Given an array of integers nums sorted in non-decreasing order, find the
starting and ending position of a given target value. If target is not found in
the array, return [-1, -1]. You must write an algorithm with O(log n) runtime
complexity.

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]

Constraints:
0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
nums is a non-decreasing array.
-10^9 <= target <= 10^9
*/

#include <vector>

using namespace std;

// Solution 1: Bisect left and bisect right
class Solution {
  public:
    vector<int> searchRange(vector<int> &nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }
        int first = leftPosition(nums, target);
        int last = rightPosition(nums, target);
        return {first, last};
    }

  private:
    int leftPosition(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int middle;

        while (left < right) {
            middle = left + (right - left) / 2;
            if (nums[middle] < target) {
                left = middle + 1;
            } else {
                right = middle;
            }
        }

        return (nums[left] == target) ? left : -1;
    }
    int rightPosition(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int middle;

        while (left < right) {
            middle = left + (right - left + 1) / 2;
            if (nums[middle] > target) {
                right = middle - 1;
            } else {
                left = middle;
            }
        }

        return (nums[right] == target) ? right : -1;
    }
};

// Time Complexity: O(log(n))
// Space Complexity: O(1)

// Solution 2: Two bisect left calls
class Solution {
  public:
    vector<int> searchRange(vector<int> &nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }

        int first = bisectLeft(nums, target);
        if (first == nums.size() || nums[first] != target) {
            return {-1, -1};
        }
        int last = bisectLeft(nums, target + 1) - 1;
        return {first, last};
    }

  private:
    int bisectLeft(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size();
        int middle;

        while (left < right) {
            middle = left + (right - left) / 2;
            if (nums[middle] < target) {
                left = middle + 1;
            } else {
                right = middle;
            }
        }

        return left;
    }
};
// Time Complexity: O(log(n))
// Space Complexity: O(1)

// Solution 3: Search towards a specific direction
class Solution {
  public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int first = customBinarySearch(nums, target, true);
        int last = customBinarySearch(nums, target, false);
        return {first, last};
    }

  private:
    int customBinarySearch(vector<int> &nums, int target,
                           bool isSearchingFirst) {
        int left = 0;
        int right = nums.size() - 1;
        int middle;
        int index = -1;

        while (left <= right) {
            middle = left + (right - left) / 2;
            if (nums[middle] < target) {
                left = middle + 1;
            } else if (nums[middle] > target) {
                right = middle - 1;
            } else {
                index = middle;
                if (isSearchingFirst) {
                    right = middle - 1;
                } else {
                    left = middle + 1;
                }
            }
        }

        return index;
    }
};

// Time Complexity: O(log(n))
// Space Complexity: O(1)
