/*
Problem Number: 4. Median of Two Sorted Arrays
Difficulty Level: Hard
Link: https://leetcode.com/problems/median-of-two-sorted-arrays/

********************************************************************************

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the
median of the two sorted arrays. The overall run time complexity should be O(log
(m+n)).

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Constraints:
nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-10^6 <= nums1[i], nums2[i] <= 10^6
*/

#include <climits>
#include <vector>

using namespace std;

// Solution 1: Merge Two Arrays
class Solution {
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0;

        vector<int> mergedList;
        mergedList.reserve(n + m);

        while (i < n && j < m) {
            if (nums1[i] < nums2[j]) {
                mergedList.push_back(nums1[i]);
                i++;
            } else {
                mergedList.push_back(nums2[j]);
                j++;
            }
        }

        while (i < n) {
            mergedList.push_back(nums1[i]);
            i++;
        }
        while (j < m) {
            mergedList.push_back(nums2[j]);
            j++;
        }

        int size = mergedList.size();
        if (size % 2 == 1) {
            return mergedList[size / 2];
        }
        return (mergedList[size / 2 - 1] + mergedList[size / 2]) / 2.0;
    }
};

// n = len(nums1), m = len(nums2)
// Time Complexity: O(n + m)
// Time Complexity: O(n + m)

// Solution 2: Two Pointers
class Solution {
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int size = n + m;

        int ptr1 = 0, ptr2 = 0;
        int prev = 0, curr = 0;

        for (int i = 0; i <= size / 2; i++) {
            prev = curr;

            if (ptr1 < n && (ptr2 == m || nums1[ptr1] < nums2[ptr2])) {
                curr = nums1[ptr1];
                ptr1++;
            } else {
                curr = nums2[ptr2];
                ptr2++;
            }
        }

        if (size % 2 == 0) {
            return (prev + curr) / 2.0;
        }
        return curr;
    }
};

// n = len(nums1), m = len(nums2)
// Time Complexity: O(n + m)
// Time Complexity: O(1)

// Solution 3: Binary Search
class Solution {
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n = nums1.size();
        int m = nums2.size();
        int size = n + m;
        int halfSize = (size + 1) / 2;

        int left = 0;
        int right = n;

        while (left <= right) {
            int partA = left + (right - left) / 2;
            int partB = halfSize - partA;

            int maxLeftA = (partA == 0) ? INT_MIN : nums1[partA - 1];
            int minRightA = (partA == n) ? INT_MAX : nums1[partA];
            int maxLeftB = (partB == 0) ? INT_MIN : nums2[partB - 1];
            int minRightB = (partB == m) ? INT_MAX : nums2[partB];

            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                if (size % 2 == 1) {
                    return max(maxLeftA, maxLeftB);
                }
                return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) /
                       2.0;
            } else if (maxLeftA < minRightB) {
                left = partA + 1;
            } else {
                right = partA - 1;
            }
        }
        return 0.0;
    }
};
// n = len(nums1), m = len(nums2)
// Time Complexity: O(log(min(n, m)))
// Time Complexity: O(1)
