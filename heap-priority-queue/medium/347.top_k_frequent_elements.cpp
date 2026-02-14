/*
Problem Number: 347. Top K Frequent Elements
Difficulty Level: Medium
Link: https://leetcode.com/problems/top-k-frequent-elements

********************************************************************************

Given an integer array nums and an integer k, return the k most frequent
elements. You may return the answer in any order.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]

Example 3:
Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2
Output: [1,2]

Constraints:
1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.

Follow up: Your algorithm's time complexity must be better than O(n log n),
where n is the array's size.
*/

#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// Solution 1: Sorting
class Solution {
  public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        vector<pair<int, int>> topFrequent;
        for (auto p : count) {
            topFrequent.push_back({p.second, p.first});
        }

        sort(topFrequent.rbegin(), topFrequent.rend());

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(topFrequent[i].second);
        }
        return result;
    }
};

// n = len(nums), m = count of unique numbers
// Time Complexity: O(n + m * log(k) + k) ==> O(n + m * log(m))
// Space Complexity: O(m + 2 * k) ==> O(m + k)

// Solution 2: Heap Priority Queue user-defined nlargest method
class Solution {
  public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> count;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minFreqHeap;
        for (int num : nums) {
            count[num]++;
        }

        for (auto &tuple : count) {
            minFreqHeap.push({tuple.second, tuple.first});
            if (minFreqHeap.size() > k) {
                minFreqHeap.pop();
            }
        }

        vector<int> result;
        while (!minFreqHeap.empty()) {
            result.push_back(minFreqHeap.top().second);
            minFreqHeap.pop();
        }
        return result;
    }
};

// n = len(nums), m = count of unique numbers
// Time Complexity: O(n + m * log(k) + k) ==> O(n + m * log(m))
// Space Complexity: O(m + 2 * k) ==> O(m + k)