/*
Problem Number: 378. Kth Smallest Element in a Sorted Matrix
Difficulty Level: Medium
Link: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix

********************************************************************************

Given an n x n matrix where each of the rows and columns is sorted in ascending order,
return the kth smallest element in the matrix. Note that it is the kth smallest element
in the sorted order, not the kth distinct element.
You must find a solution with a memory complexity better than O(n2).

Example 1:
Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th
smallest number is 13

Example 2:
Input: matrix = [[-5]], k = 1
Output: -5

Constraints:
n == matrix.length == matrix[i].length
1 <= n <= 300
-10^9 <= matrix[i][j] <= 10^9
All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
1 <= k <= n2

Follow up:
Could you solve the problem with a constant memory (i.e., O(1) memory complexity)?
Could you solve the problem in O(n) time complexity? The solution may be too advanced
for an interview but you may find reading this paper fun.
*/

#include <queue>
#include <vector>

using namespace std;

// Solution 1: Min Heap
class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            minHeap;

        for (int rowID = 0; rowID < n; rowID++) {
            minHeap.push({matrix[rowID][0], rowID, 0});
        }

        while (k > 1) {
            auto smallestTuple = minHeap.top();
            minHeap.pop();

            int rowID = smallestTuple[1];
            int colID = smallestTuple[2];
            colID++;

            if (colID < m) {
                minHeap.push({matrix[rowID][colID], rowID, colID});
            }
            k--;
        }

        return minHeap.top()[0];
    }
};

// n = len(rows), m = len(cols)
// Time Complexity: O(n + k * log(n)) ==> O(k * log(n))
// Space Complexity: O(n)

// Solution 2: Binary Search
class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        n = matrix.size();
        m = matrix[0].size();

        int left = matrix[0][0];
        int right = matrix[n - 1][m - 1];
        int middle;

        while (left < right) {
            middle = left + (right - left) / 2;
            int count = countLessOrEqual(matrix, middle);
            if (count < k) {
                left = middle + 1;
            } else {
                right = middle;
            }
        }

        // return right;
        return left;
    }

  private:
    int n;
    int m;
    int countLessOrEqual(vector<vector<int>> &matrix, int target) {
        int rowID = n - 1;
        int colID = 0;
        int count = 0;

        while (rowID >= 0 && colID < m) {
            if (matrix[rowID][colID] <= target) {
                count += rowID + 1;
                colID++;
            } else {
                rowID--;
            }
        }

        return count;
    }
};
// n = len(rows), m = len(cols), d = maximum element - minimum element
// Time Complexity: O((n + m) * log(d))
// Space Complexity: O(1)