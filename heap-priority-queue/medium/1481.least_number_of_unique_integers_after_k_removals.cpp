/*
Problem Number: 1481. Least Number of Unique Integers after K Removals
Difficulty Level: Medium
Link:
https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals

********************************************************************************

Given an array of integers arr and an integer k. Find the least number of unique
integers after removing exactly k elements.

Example 1:
Input: arr = [5,5,4], k = 1
Output: 1
Explanation: Remove the single 4, only 5 is left.

Example 2:
Input: arr = [4,3,1,1,3,3,2], k = 3
Output: 2
Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will
be left.

Constraints:
1 <= arr.length <= 10^5
1 <= arr[i] <= 10^9
0 <= k <= arr.length
*/

#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// Solution 1: Sorting
class Solution {
  public:
    int findLeastNumOfUniqueInts(vector<int> &nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        vector<int> frequencies;
        for (auto [_, freq] : count) {
            frequencies.push_back(freq);
        }

        sort(frequencies.rbegin(), frequencies.rend());

        while (k > 0 && frequencies.back() <= k) {
            int freq = frequencies.back();
            frequencies.pop_back();
            k -= freq;
        }

        return frequencies.size();
    }
};

// n = len(nums), m = count of unique numbers
// Time Complexity: O(n + m + 2 * m * log(m)) ==> O(n + m * log(m))
// Space Complexity: O(2 * m) ==> O(m)

// Solution 2: Min Heap
class Solution {
  public:
    int findLeastNumOfUniqueInts(vector<int> &nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto [_, freq] : count) {
            minHeap.push(freq);
        }

        while (k > 0 && minHeap.top() <= k) {
            int freq = minHeap.top();
            minHeap.pop();
            k -= freq;
        }

        return minHeap.size();
    }
};

// n = len(nums), m = count of unique numbers
// Time Complexity: O(n + 2 * m * log(m)) ==> O(n + m * log(m))
// Space Complexity: O(2 * m) ==> O(m)

// Solution 3: Counting Sort
class Solution {
  public:
    int findLeastNumOfUniqueInts(vector<int> &nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        int n = nums.size();

        vector<int> countOfFrequencies(n + 1, 0);
        for (auto [_, freq] : count) {
            countOfFrequencies[freq]++;
        }

        int remainingUniqueElements = count.size();
        for (int index = 1; index <= n; index++) {
            int numberOfElements = min(k / index, countOfFrequencies[index]);
            k -= (index * numberOfElements);

            remainingUniqueElements -= numberOfElements;
            if (k < index) {
                return remainingUniqueElements;
            }
        }

        return 0;
    }
};

// n = len(nums), m = count of unique numbers
// Time Complexity: O(3 * n + m) ==> O(n)
// Space Complexity: O(n + m) ==> O(n)