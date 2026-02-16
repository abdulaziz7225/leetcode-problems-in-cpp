/*
Problem Number: 658. Find K Closest Elements
Difficulty Level: Medium
Link: https://leetcode.com/problems/find-k-closest-elements

********************************************************************************

Given a sorted integer array arr, two integers k and x, return the k closest
integers to x in the array. The result should also be sorted in ascending order.
An integer a is closer to x than an integer b if:
|a - x| < |b - x|, or
|a - x| == |b - x| and a < b

Example 1:
Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]

Example 2:
Input: arr = [1,1,2,3,4,5], k = 4, x = -1
Output: [1,1,2,3]

Constraints:
1 <= k <= arr.length
1 <= arr.length <= 10^4
arr is sorted in ascending order.
-10^4 <= arr[i], x <= 10^4
*/

#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>

using namespace std;

// Solution 1: Heap Priority Queue
class Solution {
  public:
    vector<int> findClosestElements(vector<int> &nums, int k, int x) {
        priority_queue<pair<int, int>> maxHeap;
        for (int num : nums) {
            maxHeap.push({abs(num - x), num});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        vector<int> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        sort(result.begin(), result.end());
        return result;
    }
};

// n = len(nums)
// Time Complexity: O((n + k) * log(k) + k) ==> O((n + k) * log(k))
// Space Complexity: O(2 * k) ==> O(k)

// Solution 2: Binary Search
class Solution {
  public:
    vector<int> findClosestElements(vector<int> &nums, int k, int x) {
        int left = 0;
        int right = nums.size() - k;
        int middle;

        while (left < right) {
            middle = left + (right - left) / 2;
            if (x - nums[middle] > nums[middle + k] - x) {
                left = middle + 1;
            } else {
                right = middle;
            }
        }

        vector<int> result(nums.begin() + left, nums.begin() + left + k);
        return result;
    }
};

// n = len(nums)
// Time Complexity: O(log(n - k) + k) ==> O(log(n) + k)
// Space Complexity: O(k)